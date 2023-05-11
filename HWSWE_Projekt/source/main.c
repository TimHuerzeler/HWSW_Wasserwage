/**
 *****************************************************************************
 * @file        main.c
 * @brief       BTE 5053 HWSWE, C Template
 *
 * This is a template for C-Projects running on the Leguan board
 * and using STM32CubeIDE.
 *
 * @version     1.0
 * @date        2022-05-01
 * @author      Tim Hürzeler
 * 				Nicolas Reust
 * 				Sacha Widr
 *
 * @remark
 *****************************************************************************
 */
#include <leguan.h>
#include <cube.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <main.h>
#include <stm32h7xx_hal.h>

/* Defines */
void reset_LCD(void);
int Wasserwage(void);
int draw(void);
/* defines for Display */
#define LINE_LENGTH         (60)
/* positions to draw text */
#define POS_WELCOME         (20)
#define POS_WITHFPU         (50)
#define POS_WITHLIB         (70)

/* global variables for touch screen */
LCD_TouchPosition_t touchPosition;
uint16_t touch_x = 0;
uint16_t touch_y = 0;

/* Define size display, middle display and radius circle */
#define Max_X 800
#define Mid_X 400
#define Max_Y 480
#define Mid_Y 240
#define Radius 50

/* include external Assembler function */
extern float Accelerationcalc(float a,float b);

/**
 * @brief       main function
 *
 * This main function initializes the Leguan board. There is no additional
 * functionality in the main loop.
 *
 * @param       none
 * @return      always 0
 */
int main(void)
{
	/* Initialize Hardware */
	CUBEMX_Init();
	/* Initialize Leguan board */
	LEGUAN_Init();

	/* Set logging output destination to be the LCD */
	LOG_SetDestination(LCD_Stream);

	/* Main loop */
	while (1) {
		/* Drawing the home screen */
		reset_LCD();

		while (1){
			LCD_TouchGetPosition(&touchPosition);
			touch_x = touchPosition.x;
			touch_y = touchPosition.y;

			Wasserwage();
		}
	}
}
/*****************************************************************************/
/*  End 	    : main                                                       */
/*****************************************************************************/
/*****************************************************************************/
/*  Procedure   : Wasserwage                                                 */
/*****************************************************************************/
/**
 * @brief
 * The Wasserwage function is an app that can be used as a level.
 *
 * @param       none
 * @return      always -1
 */
int Wasserwage()
{
	//initialize needed variables
    vector3f_t acceleration;
    float32_t accel_x = 0;
    float32_t accel_y = 0;
    float32_t accel_z = 0;
    float32_t accel_x_absolute_value = 0;
    float32_t accel_y_absolute_value = 0;
    float32_t accel_z_absolute_value = 0;
    float32_t g = 9.81;
    uint16_t winkel = 0;
    double winkel_x = 0;
    double winkel_y = 0;

	//define Pi
    double pi = 2*acos(0);

    /* Main loop */
    while (1){
    	//clear area
        LCD_SetForegroundColor(ColorBlack);
        LCD_Rect(0,15,800,415,0);

        //horizontal-level
    	while (1){
    		//Get Acceleration
    		SENSOR_GetAcceleration(&acceleration);

    		//calculate acceleration value in assembler function
    		accel_x = Accelerationcalc(acceleration.x,g);
    		accel_y = Accelerationcalc(acceleration.y,g);
    		accel_z = Accelerationcalc(acceleration.z,g);

    		//check if orientation is negative
    		//if yes make positive else copy value into new variable
    		if (accel_x < 0){accel_x_absolute_value = accel_x * -1;}else {accel_x_absolute_value = accel_x;};
    		if (accel_y < 0){accel_y_absolute_value = accel_y * -1;}else {accel_y_absolute_value = accel_y;};
    		if (accel_z < 0){accel_z_absolute_value = accel_z * -1;}else {accel_z_absolute_value = accel_z;};

    		//if horizontal-level {}, else break and do level for surface
    		if (accel_x_absolute_value > accel_z_absolute_value || accel_y_absolute_value > accel_z_absolute_value){
    			//calculation of angel stored in variable "winkel"
    			if (accel_x_absolute_value > accel_y_absolute_value){
    				winkel = ((pi/2)+atan(accel_y/accel_x))*180/pi;
    			}
    			if (accel_x_absolute_value < accel_y_absolute_value){
    				if ((-atan(accel_x/accel_y)*180/pi) > 0){
    					winkel = (-atan(accel_x/accel_y))*180/pi;
    				}
    				if ((-atan(accel_x/accel_y)*180/pi) < 0){
    					winkel = (pi-atan(accel_x/accel_y))*180/pi;
    				}
    			}
				//reset colours
				LCD_SetBackgroundColor(ColorBlack);
				LCD_SetForegroundColor(ColorWhite);

				//Draw middle Circle
				LCD_Circle(Mid_X, Mid_Y, 50);

				//make angle into printable value
				char string [80];
				if (accel_x <= 0){sprintf(string, " %3d",winkel);}
				else{
					int winkelanzeige = 180-winkel;
					sprintf(string, "-%3d",winkelanzeige);
				}
				//define number position
				LCD_String(Mid_X-15, Mid_Y, string);

				//Draw corresponding lines on touch screen
				double x_gU = Mid_Y/tan(winkel*pi/180);
				double y_gU = tan(winkel*pi/180)*Mid_X;
				double x_kU = Radius * cos(winkel*pi/180);
				double y_kU = Radius * sin(winkel*pi/180);

				//Angle between 0° and 90°
				if (0 <= winkel && winkel <=90){
					if (y_gU < 240){
						LCD_Line(0, (Mid_Y-y_gU), (Mid_X-x_kU), (Mid_Y-y_kU));
						LCD_Line(800, (Mid_Y+y_gU), (Mid_X+x_kU), (Mid_Y+y_kU));
					}
					else{
						LCD_Line((Mid_X-x_gU), 0, (Mid_X-x_kU), (Mid_Y-y_kU));
						LCD_Line((Mid_X+x_gU), 480, (Mid_X+x_kU), (Mid_Y+y_kU));
					}
				}
				//Angle between 90° and 180°
				if (90 < winkel && winkel <=180){
					if (y_gU < -240){
						LCD_Line((Mid_X-x_gU), 0, (Mid_X-x_kU), (Mid_Y-y_kU));
						LCD_Line((Mid_X+x_gU), 480, (Mid_X+x_kU), (Mid_Y+y_kU));
					}
					else{
						LCD_Line(800, (Mid_Y+y_gU), (Mid_X-x_kU), (Mid_Y-y_kU));
						LCD_Line(0, (Mid_Y-y_gU), (Mid_X+x_kU), (Mid_Y+y_kU));
					}
				}
				//display delay
				CORE_Delay(50);
				//Delete before drawn line
				LCD_SetForegroundColor(ColorBlack);
				if (0 <= winkel && winkel <=90){
					if (y_gU < 240){
						LCD_Line(0, (Mid_Y-y_gU), (Mid_X-x_kU), (Mid_Y-y_kU));
						LCD_Line(800, (Mid_Y+y_gU), (Mid_X+x_kU), (Mid_Y+y_kU));
					}
					else{
						LCD_Line((Mid_X-x_gU), 0, (Mid_X-x_kU), (Mid_Y-y_kU));
						LCD_Line((Mid_X+x_gU), 480, (Mid_X+x_kU), (Mid_Y+y_kU));
					}
				}
				if (90 < winkel && winkel <=180){
					if (y_gU < -240){
						LCD_Line((Mid_X-x_gU), 0, (Mid_X-x_kU), (Mid_Y-y_kU));
						LCD_Line((Mid_X+x_gU), 480, (Mid_X+x_kU), (Mid_Y+y_kU));
					}
					else{
						LCD_Line(800, (Mid_Y+y_gU), (Mid_X-x_kU), (Mid_Y-y_kU));
						LCD_Line(0, (Mid_Y-y_gU), (Mid_X+x_kU), (Mid_Y+y_kU));
					}
				}
    		}
    		else{break;}
    	}
		//reset display without interface
		LCD_SetForegroundColor(ColorBlack);
		LCD_Rect(0, 15, 800, 415, 0);

		//vertical-level
		while (1){
			//get sensor data
			SENSOR_GetAcceleration(&acceleration);

			//calculate acceleration value in assembler function
			accel_x = Accelerationcalc(acceleration.x,g);
			accel_y = Accelerationcalc(acceleration.y,g);
			accel_z = Accelerationcalc(acceleration.z,g);

			//check if orientation is negative
			if (accel_x < 0){accel_x_absolute_value = accel_x * -1;}else {accel_x_absolute_value = accel_x;};
			if (accel_y < 0){accel_y_absolute_value = accel_y * -1;}else {accel_y_absolute_value = accel_y;};
			if (accel_z < 0){accel_z_absolute_value = accel_z * -1;}else {accel_z_absolute_value = accel_z;};

			//if level for surface {},else break an do horizontal-level
			if (accel_x_absolute_value < accel_z_absolute_value && accel_y_absolute_value < accel_z_absolute_value){
				winkel_x = (atan(accel_x/accel_z))*180/pi;
				winkel_y = (atan(accel_y/accel_z))*180/pi;

				//reset colours
				LCD_SetForegroundColor(ColorWhite);
				LCD_SetBackgroundColor(ColorBlack);

				//draw middle circle
				LCD_Circle(Mid_X, Mid_Y, 50);

				//draw angle value
				char string [80];
				double winkel_x_ver;
				double winkel_y_ver;
				if (winkel_x < 0){winkel_x_ver=-winkel_x;}
				if (winkel_x > 0){winkel_x_ver=winkel_x;}
				if (winkel_y < 0){winkel_y_ver=-winkel_y;}
				if (winkel_y > 0){winkel_y_ver=winkel_y;}
				if (winkel_x_ver<winkel_y_ver){sprintf(string, " %3.0f",winkel_y);}
				if (winkel_x_ver>winkel_y_ver){sprintf(string, " %3.0f",winkel_x);}

				//define number position
				LCD_String(Mid_X-15, Mid_Y, string);

				double x_pos = winkel_x*240/45;
				double y_pos = winkel_y*240/45;

				//draw shift circle
				LCD_Circle((400+x_pos), (240+y_pos), 50);

				//display delay
				CORE_Delay(50);

				//delete shift circle
				LCD_SetForegroundColor(ColorBlack);
				LCD_Circle((400+x_pos), (240+y_pos), 50);
				LCD_Circle((400-x_pos), (240-y_pos), 50);
			}
			else{break;}
		}

    }
}

/*****************************************************************************/
/*  End         : waterlevel                                                 */
/*****************************************************************************/
/*****************************************************************************/
/*  Procedure   : reset_LCD                                                  */
/*****************************************************************************/
/**
 * @brief       reset_LCD function
 *
 * This function deletes everything on the LCD-Display
 *
 * @param       none
 * @return      always 0
 */
void reset_LCD(void)
{
	LCD_SetForegroundColor(ColorBlack);
	LCD_Rect(0, 0, 800, 480, 0);
}
/*****************************************************************************/
/*  End         : reset_LCD                                                  */
/*****************************************************************************/
