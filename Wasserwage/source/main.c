#include <leguan.h>
#include <cube.h>

#include <lvgl.h>

#define PI 3.14159265358979323846

extern void LVGL_Init(void);
double getAngle(void);

extern float Accelerationcalc(float a,float b);

static void set_value_Bar(void * bar, int32_t v);
static void set_value_meter1(void * indic, int32_t v);
static void set_value_meter2(void * indic, int32_t v);

void lv_example_bar_2(void * bar);
void lv_example_meter_1(void * meter);
void lv_example_meter_2(void * meter);

int main() {
	// Initialize Hardware
	CUBEMX_Init();
	// Initialize Leguan board
	LEGUAN_Init();
	// Init LVGL
	LVGL_Init();
	// Set logging output destination to be the LCD
	LOG_SetDestination(LCD_Stream);
	lv_obj_t * bar = lv_bar_create(lv_scr_act());
	lv_obj_t * meter1 = lv_meter_create(lv_scr_act());
	lv_obj_t * meter2 = lv_meter_create(lv_scr_act());
	lv_example_bar_2(bar);

	// Main loop
	while (true) {
		// Call into LVGL for it to take over rendering and UI handling from now on
		CORE_Delay(500);
		lv_task_handler();
		double angle = getAngle();

		set_value_Bar(bar, angle);
		set_value_meter1(meter1, 45);
		set_value_meter2(meter2, 69);
	}
}

static void set_value_Bar(void * bar, int32_t v)
{
    lv_bar_set_value(bar, v, LV_ANIM_OFF);
}

static void set_value_meter1(void * meter, int32_t v)
{
    lv_meter_set_indicator_value(meter, v, LV_ANIM_OFF);
}

static void set_value_meter2(void * meter, int32_t v)
{
    lv_meter_set_indicator_value(meter, v, LV_ANIM_OFF);
}

void lv_example_bar_2(void * bar)
{
    static lv_style_t style_bg;
    static lv_style_t style_indic;

    lv_style_init(&style_bg);
    lv_style_set_border_color(&style_bg, lv_palette_main(LV_PALETTE_YELLOW));
    lv_style_set_border_width(&style_bg, 2);
    lv_style_set_pad_all(&style_bg, 6); /*To make the indicator smaller*/
    lv_style_set_radius(&style_bg, 6);
    lv_style_set_anim_time(&style_bg, 1000);

    lv_style_init(&style_indic);
    lv_style_set_bg_opa(&style_indic, LV_OPA_COVER);
    lv_style_set_bg_color(&style_indic, lv_palette_main(LV_PALETTE_PURPLE));
    lv_style_set_radius(&style_indic, 3);

    lv_obj_remove_style_all(bar);  /*To have a clean start*/
    lv_obj_add_style(bar, &style_bg, 0);
    lv_obj_add_style(bar, &style_indic, LV_PART_INDICATOR);

    lv_obj_set_size(bar, 200, 20);
    lv_obj_center(bar);
    lv_bar_set_range(bar,0,200);
    lv_bar_set_start_value(bar, 20, LV_ANIM_OFF);
}

void lv_example_meter_1(void * meter)
{
	lv_obj_set_align(meter, LV_ALIGN_TOP_RIGHT);
    lv_obj_set_size(meter, 200, 200);

    /*Add a scale first*/
    lv_meter_set_scale_ticks(meter, 41, 2, 10, lv_palette_main(LV_PALETTE_GREY));
    lv_meter_set_scale_major_ticks(meter, 8, 4, 15, lv_color_black(), 10);


    lv_meter_indicator_t * indic;

    /*Add a blue arc to the start*/
    indic = lv_meter_add_arc(meter, 3, lv_palette_main(LV_PALETTE_BLUE), 0);
    lv_meter_set_indicator_start_value(meter, indic, 0);
    lv_meter_set_indicator_end_value(meter, indic, 20);

    /*Make the tick lines blue at the start of the scale*/
    indic = lv_meter_add_scale_lines(meter, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_BLUE),
                                     false, 0);
    lv_meter_set_indicator_start_value(meter, indic, 0);
    lv_meter_set_indicator_end_value(meter, indic, 20);

    /*Add a red arc to the end*/
    indic = lv_meter_add_arc(meter, 3, lv_palette_main(LV_PALETTE_RED), 0);
    lv_meter_set_indicator_start_value(meter, indic, 80);
    lv_meter_set_indicator_end_value(meter, indic, 100);

    /*Make the tick lines red at the end of the scale*/
    indic = lv_meter_add_scale_lines(meter, lv_palette_main(LV_PALETTE_RED), lv_palette_main(LV_PALETTE_RED), false,
                                     0);
    lv_meter_set_indicator_start_value(meter, indic, 80);
    lv_meter_set_indicator_end_value(meter, indic, 100);

    /*Add a needle line indicator*/
    indic = lv_meter_add_needle_line(meter, 4, lv_palette_main(LV_PALETTE_GREY), -10);
}

void lv_example_meter_2(void * meter)
{
	lv_obj_set_align(meter, LV_ALIGN_TOP_LEFT);
    lv_obj_set_size(meter, 220, 220);

    /*Remove the circle from the middle*/
    lv_obj_remove_style(meter, NULL, LV_PART_INDICATOR);

    /*Add a scale first*/
    lv_meter_set_scale_ticks(meter, 11, 2, 10, lv_palette_main(LV_PALETTE_GREY));
    lv_meter_set_scale_major_ticks(meter, 1, 2, 30, lv_color_hex3(0xeee), 15);
    lv_meter_set_scale_range(meter, 0, 100, 270, 90);

    /*Add a three arc indicator*/
    lv_meter_indicator_t * indic1 = lv_meter_add_arc(meter, 10, lv_palette_main(LV_PALETTE_RED), 0);

}

double getAngle(void) {
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
	double angle_rad = atan2(sqrt(accel_x*accel_x + accel_y*accel_y), accel_z);
    double angle_deg = angle_rad * 180.0 / PI;
    return angle_deg;
}
