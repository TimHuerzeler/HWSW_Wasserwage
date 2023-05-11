#include <leguan.h>
#include <cube.h>

#include <lvgl.h>

extern void LVGL_Init(void);
static void set_temp(void * bar, int32_t temp);
void Wasserwage(void);

/* include external Assembler function */
extern float Accelerationcalc(float a,float b);

int main() {
	// Initialize Hardware
	CUBEMX_Init();
	// Initialize Leguan board
	LEGUAN_Init();
	// Init LVGL
	LVGL_Init();

	// Set logging output destination to be the LCD
	LOG_SetDestination(LCD_Stream);

	// Create the interface. Replace this with your own code
	{
		static lv_style_t style_indic;

		lv_style_init(&style_indic);
		lv_style_set_bg_opa(&style_indic, LV_OPA_COVER);
		lv_style_set_bg_color(&style_indic, lv_palette_main(LV_PALETTE_RED));
		lv_style_set_bg_grad_color(&style_indic, lv_palette_main(LV_PALETTE_BLUE));
		lv_style_set_bg_grad_dir(&style_indic, LV_GRAD_DIR_VER);

		lv_obj_t * bar = lv_bar_create(lv_scr_act());
		lv_obj_add_style(bar, &style_indic, LV_PART_INDICATOR);
		lv_obj_set_size(bar, 20, 200);
		lv_obj_center(bar);
		lv_bar_set_range(bar, -20, 40);
	}

	// Main loop
	while (true) {
		// Call into LVGL for it to take over rendering and UI handling from now on
		lv_task_handler();
		Wasserwage();
	}
}
void Wasserwage(void){
	//initialize needed variables
    vector3f_t acceleration;
    float32_t accel_x = 0;
    float32_t accel_y = 0;
    float32_t accel_z = 0;
    float32_t accel_x_absolute_value = 0;
    float32_t accel_y_absolute_value = 0;
    float32_t accel_z_absolute_value = 0;
    float32_t g = 9.81;
    uint32_t winkel = 0;
    double winkel_x = 0;
    double winkel_y = 0;

	//define Pi
    double pi = 2*acos(0);

    /* Main loop */
    while (1){
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
				//make angle into printable value
				if (accel_x <= 0){set_temp(bar, winkel);}
				else{
					int winkelanzeige = 180-winkel;
					set_temp(bar, winkelanzeige);
					}
			}
			else{break;}
		}
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
				//draw angle value
				double winkel_x_ver;
				double winkel_y_ver;
				if (winkel_x < 0){winkel_x_ver=-winkel_x;}
				if (winkel_x > 0){winkel_x_ver=winkel_x;}
				if (winkel_y < 0){winkel_y_ver=-winkel_y;}
				if (winkel_y > 0){winkel_y_ver=winkel_y;}

				if (winkel_x_ver<winkel_y_ver){set_temp(bar, winkel_x);}
				if (winkel_x_ver>winkel_y_ver){set_temp(bar, winkel_y);}
			}
			else{break;}
		}
    }
}
void set_temp(void * bar, int32_t temp)
{
	lv_bar_set_value(bar, temp, LV_ANIM_ON);
}

