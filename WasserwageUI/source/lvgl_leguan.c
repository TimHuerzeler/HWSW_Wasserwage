#include <leguan.h>
#include <lvgl.h>

static lv_disp_draw_buf_t lvDrawBuffer;
static lv_color_t lvBuffer[LCD_WIDTH * LCD_HEIGHT / 10][2];

extern volatile uint32_t uwTick;
extern HAL_TickFreqTypeDef uwTickFreq;

// Overrides the default HAL_IncTick function which was specified as weak.
// This is done because this function is called every time the systick interrupt fires.
// We want to signal LVGL every millisecond that one "tick" has elapsed
void HAL_IncTick(void) {
	// Increase HAL tick
	uwTick += (uint32_t)uwTickFreq;

	// Increase LVGL tick
	lv_tick_inc(uwTickFreq);
}

static void LVGL_LeguanFlushLCD(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *buffer) {
	// Set area to draw to
	LCD_SetDrawArea(area->x1, area->y1, area->x2, area->y2);

	// Draw buffer to screen
    LCD_EnableDrawMode();
    LCD_DrawBuffer((LCD_Color_t*)buffer, (area->x2 - area->x1 + 1) * (area->y2 - area->y1 + 1));

    // Mark region as fully drawn
    lv_disp_flush_ready(disp);
}

static void LVGL_LeguanReadInput(lv_indev_drv_t *drv, lv_indev_data_t *data) {
    static LCD_TouchPosition_t lastPos;
    LCD_TouchPosition_t currPos;

    // Check if touch screen is currently being touched and if yes, where it was touched
    if (R_FAILURE(LCD_TouchGetPosition(&currPos)) || currPos.x == 0 || currPos.y == 0) {
    	// Screen isn't being touched right now

        data->state = LV_INDEV_STATE_RELEASED;
        currPos = lastPos;
    } else {
    	// Screen is getting touched

        data->point.x = currPos.x;
        data->point.y = currPos.y;
        data->state = LV_INDEV_STATE_PRESSED;
    }

    lastPos = currPos;
}

void LVGL_Init(void) {
	// Initialize LVGL
    lv_init();

    // Initialize draw buffer
    lv_disp_draw_buf_init(&lvDrawBuffer, lvBuffer[0], lvBuffer[1], LCD_WIDTH * LCD_HEIGHT / 10);

    // Initialize display driver
    static lv_disp_drv_t lvDisplayDriver;
    lv_disp_drv_init(&lvDisplayDriver);
    lvDisplayDriver.flush_cb = LVGL_LeguanFlushLCD;
    lvDisplayDriver.draw_buf = &lvDrawBuffer;
    lvDisplayDriver.hor_res  = LCD_WIDTH;
    lvDisplayDriver.ver_res  = LCD_HEIGHT;
    lv_disp_drv_register(&lvDisplayDriver);

    // Initialize touch input driver
    static lv_indev_drv_t lvInputDriver;
    lv_indev_drv_init(&lvInputDriver);
    lvInputDriver.type = LV_INDEV_TYPE_POINTER;
    lvInputDriver.read_cb = LVGL_LeguanReadInput;
    lv_indev_drv_register(&lvInputDriver);
}
