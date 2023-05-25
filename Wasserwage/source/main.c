#include <leguan.h>
#include <cube.h>

#include <lvgl.h>
//testcomment
#define PI 3.14159265358979323846
#define CANVAS_WIDTH  800
#define CANVAS_HEIGHT  480

extern void LVGL_Init(void);
double getAngle1(void);
double getAngle2(void);

extern float Accelerationcalc(float a,float b);

void lv_example_canvas_1(double angle);

int main() {
	// Initialize Hardware
	CUBEMX_Init();
	// Initialize Leguan board
	LEGUAN_Init();
	// Init LVGL
	LVGL_Init();
	// Set logging output destination to be the LCD
	LOG_SetDestination(LCD_Stream);
	lv_example_canvas_1(30);
	// Main loop
	while (true) {
		// Call into LVGL for it to take over rendering and UI handling from now on
		lv_task_handler();
//		double angle1 = getAngle1();
//		lv_example_canvas_1(angle1);
	}
}

void lv_example_canvas_1(double angle)
{
	/*Create a buffer for the canvas*/
	static uint8_t cbuf[LV_CANVAS_BUF_SIZE_TRUE_COLOR(CANVAS_WIDTH, CANVAS_HEIGHT)];

	/*Create a canvas and initialize its palette*/
	lv_obj_t * canvas = lv_canvas_create(lv_scr_act());
	lv_canvas_set_buffer(canvas, cbuf, CANVAS_WIDTH, CANVAS_HEIGHT, LV_IMG_CF_TRUE_COLOR);
	lv_canvas_fill_bg(canvas, lv_color_hex3(0xccc), LV_OPA_COVER);
	lv_obj_center(canvas);

	lv_draw_rect_dsc_t rect_dsc;
	lv_draw_rect_dsc_init(&rect_dsc);
	rect_dsc.radius = 10;
	rect_dsc.bg_opa = LV_OPA_COVER;
    rect_dsc.bg_color = lv_palette_main(LV_PALETTE_RED);

    lv_canvas_draw_rect(canvas, 70, 60, 100, 70, &rect_dsc);

    /*Test the rotation. It requires another buffer where the original image is stored.
     *So copy the current image to buffer and rotate it to the canvas*/
    static lv_color_t cbuf_tmp[CANVAS_WIDTH * CANVAS_HEIGHT];
	memcpy(cbuf_tmp, cbuf, sizeof(cbuf_tmp));
	lv_img_dsc_t img;
	img.data = (void *)cbuf_tmp;
	img.header.cf = LV_IMG_CF_TRUE_COLOR;
	img.header.w = CANVAS_WIDTH;
	img.header.h = CANVAS_HEIGHT;

	lv_canvas_fill_bg(canvas, lv_palette_lighten(LV_PALETTE_GREY, 3), LV_OPA_COVER);
	lv_canvas_transform(canvas, &img, 30, LV_IMG_ZOOM_NONE, 0, 0, CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, true);
}

double getAngle1(void) {
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
    return angle_deg;
}

double getAngle2(void) {
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
	double angle_rad = atan2(sqrt(accel_x*accel_x + accel_z*accel_z), accel_y);
    double angle_deg = angle_rad * 180.0 / PI;
    return angle_deg;
}
