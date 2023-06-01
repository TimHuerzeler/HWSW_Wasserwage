/**
 *****************************************************************************
 * @file        main.c
 * @brief       BTE 5053 HWSWE, C Template
 *
 * This is a template for C-Projects running on the Leguan board
 * and using STM32CubeIDE.
 *
 * @version     1.0
 * @date        2022-01-07
 * @author      ssn1, WBR1
 *
 * @remark      Last Modification
 *              \li wbr1 2022-01-07 created for BTE 5053
 *****************************************************************************
 */
#include <leguan.h>
#include <cube.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define PI 3.14159265358979323846
#define HalfofDisplayV 240
#define HalfofDisplayH 400

extern float Accelerationcalc(float a,float b);

double getAngleVertical(void) {
    vector3f_t acceleration;
    float32_t accel_x = 0;
    float32_t accel_y = 0;
    float32_t accel_z = 0;
    float32_t g = 9.81;

	SENSOR_GetAcceleration(&acceleration);
	//calculate acceleration value in assembler function
	accel_x = Accelerationcalc(acceleration.x,g);
	accel_y = Accelerationcalc(acceleration.y,g);
	accel_z = Accelerationcalc(acceleration.z,g);
	//calculate the angle in degrees
	double angle_rad = atan2(sqrt(accel_z*accel_z + accel_y*accel_y), accel_x);
    double angle_deg = angle_rad * 180.0 / PI;
    return angle_deg - 90;
}
double getAngleHorizontal(void) {
    vector3f_t acceleration;
    float32_t accel_x = 0;
    float32_t accel_y = 0;
    float32_t accel_z = 0;
    float32_t g = 9.81;

	SENSOR_GetAcceleration(&acceleration);
	//calculate acceleration value in assembler function
	accel_x = Accelerationcalc(acceleration.x,g);
	accel_y = Accelerationcalc(acceleration.y,g);
	accel_z = Accelerationcalc(acceleration.z,g);
	//calculate the angle in degrees
	double angle_rad = atan2(sqrt(accel_z*accel_z + accel_x*accel_x), accel_y);
    double angle_deg = angle_rad * 180.0 / PI;
    return angle_deg - 90;
}

bool isValueInRange(double value) {
    if (value >= 50 && value <= 90) {
        return true;
    } else {
        return false;
    }
}

void verticalAngle(double angle){
	LCD_SetBackgroundColor(ColorBlack);
	LCD_Clear();
	double x1 = 400 + (240 * tan(angle * PI / 180.0));
	double x2 = 400 + (240 * tan(angle * -1.0 * PI / 180.0));
	LCD_Line(x1,480,x2,0);
//	LCD_Rect(400,0,900,5,angle);
}

void horizontalAngle(double angle){
	LCD_SetBackgroundColor(ColorPurple);
	LCD_Clear();
	double iangle = angle * -1.0;
	double y1 = 240 + (400 * tan(angle * PI / 180.0));
	double y2 = 240 + (400 * tan(iangle * PI / 180.0));
    LCD_Line(0, y1, 800, y2);
}
double smoothAngle(double angle) {
    double smoothedAngle = fmod(angle, 360.0);  // Wrap angle between 0 and 360 degrees
    smoothedAngle = round(smoothedAngle * 100) / 100.0;  // Round to two decimal places
    return smoothedAngle;
}
void draw_rotating_line(double angle)
{
	LCD_SetBackgroundColor(ColorPurple);
	LCD_Clear();
    // Display dimensions
    int display_width = 800;
    int display_height = 480;

    // Center coordinates
    int center_x = display_width / 2;
    int center_y = display_height / 2;

    // Calculate the coordinates of the line endpoints
    double angle_radians = angle * M_PI / 180.0;
    int x1 = center_x + (int)((double)display_width / 2.0 * cos(angle_radians));
    int y1 = center_y + (int)((double)display_height / 2.0 * sin(angle_radians));
    int x2 = center_x - (int)((double)display_width / 2.0 * cos(angle_radians));
    int y2 = center_y - (int)((double)display_height / 2.0 * sin(angle_radians));

    // Draw the line
    LCD_Line(x1, y1, x2, y2);
}
void printAngleValue(double angle){
	char str[20]; // Create a character array to store the string
	sprintf(str, "%f", angle);
	LCD_String(400, 240, str);
	LCD_Circle(400, 240, 42);
}

void checkAngle(void){

}
void Wasserwage(void){
	double angleV = getAngleVertical();
//	double angleH = getAngleHorizontal();

	draw_rotating_line(angleV);
//	draw_rotating_line(angleH);
//	printAngleValue(angleV);
}

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
    for (;;) {
    	Wasserwage();
    	CORE_Delay(50);
    }

    return (0);
}
