#include <leguan.h>
#include <cube.h>

#include <lvgl.h>
#define PI 3.14159265358979323846
#define CANVAS_WIDTH  800
#define CANVAS_HEIGHT  480

extern void LVGL_Init(void);
double getAngle1(void);
double getAngle2(void);

extern float Accelerationcalc(float a,float b);

//static void set_value_Bar1(void * bar, int32_t v);
//static void set_value_Bar2(void * bar, int32_t v);
//
////static void set_value_meter2(void * meter, void * indic, int32_t v);
//static void event_cb1(lv_event_t * e);
//static void event_cb2(lv_event_t * e);

void lv_bar_1(void * bar);
void lv_bar_2(void * bar);

int main() {
	// Initialize Hardware
	CUBEMX_Init();
	// Initialize Leguan board
	LEGUAN_Init();
	// Init LVGL
	LVGL_Init();
	// Set logging output destination to be the LCD
	LOG_SetDestination(LCD_Stream);

//	static lv_style_t style;
//	lv_style_init(&style);
//	lv_style_set_flex_flow(&style, LV_FLEX_FLOW_ROW_WRAP);
//	lv_style_set_flex_main_place(&style, LV_FLEX_ALIGN_SPACE_EVENLY);
//	lv_style_set_layout(&style, LV_LAYOUT_FLEX);
//	lv_style_set_bg_color(&style, lv_palette_main(LV_PALETTE_BLUE_GREY));
//
//	lv_obj_t * cont = lv_obj_create(lv_scr_act());
//	lv_obj_set_size(cont, 800, 480);
//	lv_obj_center(cont);
//	lv_obj_add_style(cont, &style, 0);
//
//	lv_obj_t * bar1 = lv_bar_create(cont);
//	lv_obj_t * bar2 = lv_bar_create(cont);
//
//	lv_obj_set_size(bar1, 140, LV_SIZE_CONTENT);
//	lv_obj_set_size(bar2, 140, LV_SIZE_CONTENT);
//
//	lv_obj_add_flag(bar1, LV_OBJ_FLAG_CHECKABLE);
//	lv_obj_add_flag(bar2, LV_OBJ_FLAG_CHECKABLE);
//
//	lv_bar_1(bar1);
//	lv_bar_2(bar2);

	// Main loop
	LCD_SetForegroundColor(ColorBlack);
	while (true) {
		// Call into LVGL for it to take over rendering and UI handling from now on
		lv_task_handler();
		double angle1 = getAngle1();
//		double angle2 = getAngle2();

//		set_value_Bar1(bar1, angle1);
//		set_value_Bar2(bar2, angle2);

		LCD_Rect(400,240,50,50,angle1);

	}
}
//
//static void set_value_Bar1(void * bar, int32_t v)
//{
//    lv_bar_set_value(bar, v, LV_ANIM_OFF);
//}
//static void set_value_Bar2(void * bar, int32_t v)
//{
//    lv_bar_set_value(bar, v, LV_ANIM_OFF);
//}
//
//static void event_cb1(lv_event_t * e)
//{
//    lv_obj_draw_part_dsc_t * dsc = lv_event_get_draw_part_dsc(e);
//    if(dsc->part != LV_PART_INDICATOR) return;
//
//    lv_obj_t * obj = lv_event_get_target(e);
//
//    lv_draw_label_dsc_t label_dsc;
//    lv_draw_label_dsc_init(&label_dsc);
//    label_dsc.font = LV_FONT_DEFAULT;
//
//    char buf[8];
//    lv_snprintf(buf, sizeof(buf), "%d", (int)lv_bar_get_value(obj));
//
//    lv_point_t txt_size;
//    lv_txt_get_size(&txt_size, buf, label_dsc.font, label_dsc.letter_space, label_dsc.line_space, LV_COORD_MAX,
//                    label_dsc.flag);
//
//    lv_area_t txt_area;
//    /*If the indicator is long enough put the text inside on the right*/
//    if(lv_area_get_width(dsc->draw_area) > txt_size.x + 20) {
//        txt_area.x2 = dsc->draw_area->x2 - 5;
//        txt_area.x1 = txt_area.x2 - txt_size.x + 1;
//        label_dsc.color = lv_color_white();
//    }
//    /*If the indicator is still short put the text out of it on the right*/
//    else {
//        txt_area.x1 = dsc->draw_area->x2 + 5;
//        txt_area.x2 = txt_area.x1 + txt_size.x - 1;
//        label_dsc.color = lv_color_white();
//    }
//
//    txt_area.y1 = dsc->draw_area->y1 + (lv_area_get_height(dsc->draw_area) - txt_size.y) / 2;
//    txt_area.y2 = txt_area.y1 + txt_size.y - 1;
//
//    lv_draw_label(&txt_area, dsc->clip_area, &label_dsc, buf, NULL);
//}
//
//static void event_cb2(lv_event_t * e)
//{
//    lv_obj_draw_part_dsc_t * dsc = lv_event_get_draw_part_dsc(e);
//    if(dsc->part != LV_PART_INDICATOR) return;
//
//    lv_obj_t * obj = lv_event_get_target(e);
//
//    lv_draw_label_dsc_t label_dsc;
//    lv_draw_label_dsc_init(&label_dsc);
//    label_dsc.font = LV_FONT_DEFAULT;
//
//    char buf[8];
//    lv_snprintf(buf, sizeof(buf), "%d", (int)lv_bar_get_value(obj));
//
//    lv_point_t txt_size;
//    lv_txt_get_size(&txt_size, buf, label_dsc.font, label_dsc.letter_space, label_dsc.line_space, LV_COORD_MAX,
//                    label_dsc.flag);
//
//    lv_area_t txt_area;
//    /*If the indicator is long enough put the text inside on the right*/
//    if(lv_area_get_width(dsc->draw_area) > txt_size.x + 20) {
//        txt_area.x2 = dsc->draw_area->x2 - 5;
//        txt_area.x1 = txt_area.x2 - txt_size.x + 1;
//        label_dsc.color = lv_color_black();
//    }
//    /*If the indicator is still short put the text out of it on the right*/
//    else {
//        txt_area.x1 = dsc->draw_area->x2 + 5;
//        txt_area.x2 = txt_area.x1 + txt_size.x - 1;
//        label_dsc.color = lv_color_black();
//    }
//}
//
//void lv_bar_1(void * bar)
//{
//    static lv_style_t style_bg;
//    static lv_style_t style_indic;
//
//    lv_style_init(&style_bg);
//    lv_style_set_border_color(&style_bg, lv_palette_main(LV_PALETTE_YELLOW));
//    lv_style_set_border_width(&style_bg, 2);
//    lv_style_set_pad_all(&style_bg, 6); /*To make the indicator smaller*/
//    lv_style_set_radius(&style_bg, 6);
//    lv_style_set_anim_time(&style_bg, 1000);
//
//    lv_style_init(&style_indic);
//    lv_style_set_bg_opa(&style_indic, LV_OPA_COVER);
//    lv_style_set_bg_color(&style_indic, lv_palette_main(LV_PALETTE_GREEN));
//    lv_style_set_radius(&style_indic, 3);
//
//    lv_obj_remove_style_all(bar);  /*To have a clean start*/
//    lv_obj_add_style(bar, &style_bg, 0);
//    lv_obj_add_style(bar, &style_indic, LV_PART_INDICATOR);
//
//    lv_obj_add_event_cb(bar, event_cb1, LV_EVENT_DRAW_PART_END, NULL);
//
//    lv_obj_set_size(bar, 200, 20);
//    lv_obj_center(bar);
//    lv_bar_set_range(bar,0,200);
//    lv_bar_set_start_value(bar, 20, LV_ANIM_OFF);
//}
//
//void lv_bar_2(void * bar)
//{
//    static lv_style_t style_bg;
//    static lv_style_t style_indic;
//
//    lv_style_init(&style_bg);
//    lv_style_set_border_color(&style_bg, lv_palette_main(LV_PALETTE_YELLOW));
//    lv_style_set_border_width(&style_bg, 2);
//    lv_style_set_pad_all(&style_bg, 6); /*To make the indicator smaller*/
//    lv_style_set_radius(&style_bg, 6);
//
//
//    lv_style_init(&style_indic);
//    lv_style_set_bg_opa(&style_indic, LV_OPA_COVER);
//    lv_style_set_bg_color(&style_indic, lv_palette_main(LV_PALETTE_PURPLE));
//    lv_style_set_radius(&style_indic, 3);
//
//    lv_obj_remove_style_all(bar);  /*To have a clean start*/
//    lv_obj_add_style(bar, &style_bg, 0);
//    lv_obj_add_style(bar, &style_indic, LV_PART_INDICATOR);
//
//    lv_obj_add_event_cb(bar, event_cb2, LV_EVENT_DRAW_PART_END, NULL);
//
//    lv_obj_set_size(bar, 20, 200);
//    lv_obj_set_align(bar, LV_ALIGN_TOP_LEFT);
//    lv_bar_set_range(bar,0,200);
//    lv_bar_set_start_value(bar, 20, LV_ANIM_OFF);
//}
//
//void lv_example_canvas_1(double angle)
//{
//    lv_draw_rect_dsc_t rect_dsc;
//    lv_draw_rect_dsc_init(&rect_dsc);
//    rect_dsc.radius = 1;
//    rect_dsc.bg_opa = LV_OPA_COVER;
//    rect_dsc.bg_color = lv_palette_main(LV_PALETTE_RED);
//    rect_dsc.border_color = lv_color_white();
//
//    static uint8_t cbuf[LV_CANVAS_BUF_SIZE_TRUE_COLOR(CANVAS_WIDTH, CANVAS_HEIGHT)];
//
//    lv_obj_t * canvas = lv_canvas_create(lv_scr_act());
//    lv_canvas_set_buffer(canvas, cbuf, CANVAS_WIDTH, CANVAS_HEIGHT, LV_IMG_CF_TRUE_COLOR);
//    lv_obj_center(canvas);
//    lv_canvas_fill_bg(canvas, lv_palette_lighten(LV_PALETTE_GREY, 3), LV_OPA_COVER);
//
//    lv_canvas_draw_rect(canvas, 70, 60, 100, 70, &rect_dsc);
//
//    /*Test the rotation. It requires another buffer where the original image is stored.
//     *So copy the current image to buffer and rotate it to the canvas*/
//    static uint8_t cbuf_tmp[LV_CANVAS_BUF_SIZE_TRUE_COLOR(CANVAS_WIDTH, CANVAS_HEIGHT)];
//    memcpy(cbuf_tmp, cbuf, sizeof(cbuf_tmp));
//    lv_img_dsc_t img;
//    img.data = (void *)cbuf_tmp;
//    img.header.cf = LV_IMG_CF_TRUE_COLOR;
//    img.header.w = CANVAS_WIDTH;
//    img.header.h = CANVAS_HEIGHT;
//
//    lv_canvas_fill_bg(canvas, lv_palette_lighten(LV_PALETTE_GREY, 3), LV_OPA_COVER);
//    lv_canvas_transform(canvas, &img, angle, LV_IMG_ZOOM_NONE, 0, 0, CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, true);
//}

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

//double getAngle2(void) {
//    vector3f_t acceleration;
//    float32_t accel_x = 0;
//    float32_t accel_y = 0;
//    float32_t accel_z = 0;
//    float32_t g = 9.81;
//
//	SENSOR_GetAcceleration(&acceleration);
//	//calculate acceleration value in assembler function
//	accel_x = Accelerationcalc(acceleration.x,g);
//	accel_y = Accelerationcalc(acceleration.y,g);
//	accel_z = Accelerationcalc(acceleration.z,g);
//	//calculate the angle in degrees
//	double angle_rad = atan2(sqrt(accel_x*accel_x + accel_z*accel_z), accel_y);
//    double angle_deg = angle_rad * 180.0 / PI;
//    return angle_deg;
//}
