 /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
  *          _                                                      *
  *         | |                                                     *
  *         | |     ___  __ _ _   _  __ _ _ __                      *
  *         | |    / _ \/ _` | | | |/ _` | '_ \                     *
  *         | |___|  __/ (_| | |_| | (_| | | | |                    *
  *         \_____/\___|\__, |\__,_|\__,_|_| |_|                    *
  *        ============= __/ | ==================                   *
  *                     |___/           BFH 2021                    *
  *                                                                 *
  * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
  * This software can be used by students and other personal of the *
  * Bern University of Applied Sciences under the terms of the MIT  *
  * license.                                                        *
  * For other persons this software is under the terms of the GNU   *
  * General Public License version 2.                               *
  *                                                                 *
  * Copyright &copy; 2021, Bern University of Applied Sciences.     *
  * All rights reserved.                                            *
  * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/**
  *  @file lcd.c
  *  @ingroup peripherals
  *  @author Nikolaij Saegesser, Nicola Stettler, Serge Weidmann
  *  @brief Display implementation
  */

#include "peripherals/external/lcd.h"

#include "peripherals/internal/gpio.h"
#include "peripherals/internal/spi.h"

#include "common/core.h"
#include "common/attributes.h"
#include "common/intrinsics.h"
#include "common/processor.h"
#include "common/math.h"

#include "resources/font.inc"

#include <string.h>

static LCD_Color_t m_foreground_color, m_background_color;

static uint16_t m_console_cursor_x, m_console_cursor_y;
static uint16_t m_touchMinX, m_touchMaxX, m_touchMinY, m_touchMaxY;

static uint16_t m_console_font_size = 1;

#if defined(LEGUAN_FIRMWARE_CPU)
	static GPIO_Handle_t TouchCS = GPIO_LOW_ACTIVE(D,6);
#else
	static GPIO_Handle_t TouchCS = GPIO_LOW_ACTIVE(D,13);
#endif

/* LCD */

static LEGUAN_ALWAYS_INLINE void LCD_Command(uint8_t cmd) {
    LCD->cmd = cmd;
}

static LEGUAN_ALWAYS_INLINE void LCD_Data8(uint8_t data) {
    LCD->data8 = data;
}

static LEGUAN_ALWAYS_INLINE void LCD_Data16(uint16_t data) {
    LCD->data16 = data;
}

static LEGUAN_ALWAYS_INLINE void LCD_CommandData8(uint8_t cmd, uint8_t data) {
    LCD_Command(cmd);
    LCD_Data8(data);
}

static LEGUAN_ALWAYS_INLINE void LCD_CommandData16(uint8_t cmd, uint16_t data) {
    LCD_Command(cmd);
    LCD_Data16(data);
}

void LCD_SetCursorX(uint16_t x) {
	m_console_cursor_x = x;
}

void LCD_SetCursorY(uint16_t y) {
	m_console_cursor_y = y;
}

result_t LCD_SetDrawArea(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2) {
    if (x1 > LCD_WIDTH || y1 > LCD_HEIGHT)
        return RESULT_INVALID_ARGUMENTS;
    if (x2 > LCD_WIDTH || y2 > LCD_HEIGHT)
        return RESULT_INVALID_ARGUMENTS;

    /* Set horizontal region */
    LCD_Command(LCD_CMD_SET_COLUMN_ADDRESS);
    LCD_Data8(x1 >> 8);
    LCD_Data8(x1 & 0xFF);
    LCD_Data8(x2 >> 8);
    LCD_Data8(x2 & 0xFF);

    /* Set vertical region */
    LCD_Command(LCD_CMD_SET_PAGE_ADDRESS);
    LCD_Data8(y1 >> 8);
    LCD_Data8(y1 & 0xFF);
    LCD_Data8(y2 >> 8);
    LCD_Data8(y2 & 0xFF);

    return RESULT_SUCCESS;
}

void LCD_EnableDrawMode(void) {
    LCD_Command(LCD_CMD_WRITE_MEMORY_START);
}

result_t LCD_Init(void) {

    /* Turn display on */
    LCD_Command(LCD_CMD_SET_DISPLAY_ON);

    /* Flip LCD horizontally */
    LCD_CommandData8(LCD_CMD_SET_ADDRESS_MODE, 0b00000010);

    CORE_Delay(10);

    /* Set LCD color format */
    LCD_CommandData8(LCD_CMD_SET_PIXEL_DATA_INTERFACE, 0b011); // RGB565

    LCD_SetDrawArea(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);

    CORE_Delay(100);

    /* Start pixel access mode */
    LCD_EnableDrawMode();

    LCD_SetForegroundColor(ColorWhite);
    LCD_SetBackgroundColor(ColorBlack);
    LCD_Clear();

    return RESULT_SUCCESS;
}


void LCD_Stream(const char *string, bool new_line) {
    if (m_console_cursor_y >= LCD_HEIGHT - CONSOLE_FONT_CHAR_HEIGHT) {
        m_console_cursor_y = 0;
    }

    if (new_line) {
        LCD_StringContinue(string);
        LCD_StringContinue("\n");
    }
    else
        LCD_StringContinue(string);
}

result_t LCD_SetScrollArea(uint16_t y1, uint16_t y2) {

    uint16_t FixedLinesTop = y1;
    uint16_t FixedLinesBottom = LCD_HEIGHT - y2;
    uint16_t ScrollingLines = LCD_HEIGHT - FixedLinesTop - FixedLinesBottom;

    /* Set Top Fixed Area */
    LCD_Command(LCD_CMD_SET_SCROLL_AREA);

    /* Set Top Fixed Area */
    LCD_Data8(FixedLinesTop >> 8);
    LCD_Data8(FixedLinesTop & 0xFF);

    /* Set Height of the scrolling Area */
    LCD_Data8(ScrollingLines >> 8);
    LCD_Data8(ScrollingLines & 0xFF);

    /* Set Bottom Fixed Area */
    LCD_Data8(FixedLinesBottom >> 8);
    LCD_Data8(FixedLinesBottom & 0xFF);

    return RESULT_SUCCESS;
}

result_t LCD_Scroll(int16_t lines) {
    if (lines < 0)
        return RESULT_INVALID_ARGUMENTS;

    LCD_Command(LCD_CMD_SET_SCROLL_START);
    LCD_Data8(lines >> 8);
    LCD_Data8(lines & 0xFF);

    return RESULT_SUCCESS;
}

void LCD_SetForegroundColor(color_t color) {
    m_foreground_color.r = color.r;
    m_foreground_color.g = color.g;
    m_foreground_color.b = color.b;
}

void LCD_SetBackgroundColor(color_t color) {
    m_background_color.r = color.r;
    m_background_color.g = color.g;
    m_background_color.b = color.b;
}

void LCD_GetForegroundColor(color_t *color) {
    color->r = m_foreground_color.r;
    color->g = m_foreground_color.g;
    color->b = m_foreground_color.b;
}

void LCD_GetBackgroundColor(color_t *color) {
    color->r = m_background_color.r;
    color->g = m_background_color.g;
    color->b = m_background_color.b;
}

color_t LCD_ColorConvert(uint8_t r, uint8_t g, uint8_t b) {
    color_t color = COLOR(0xFF, 0xFF, 0xFF,0xFF);
    uint32_t rgb = 0;

    rgb = (r << 16) + (g << 8) + b;
    color.r = ((((rgb & 0xf80000) >> 8) + ((rgb & 0xfc00) >> 5) + ((rgb & 0xf8) >> 3)) & 0b1111100000000000) >> 11;
    color.g = ((((rgb & 0xf80000) >> 8) + ((rgb & 0xfc00) >> 5) + ((rgb & 0xf8) >> 3)) & 0b0000011111100000) >> 5;
    color.b = ((((rgb & 0xf80000) >> 8) + ((rgb & 0xfc00) >> 5) + ((rgb & 0xf8) >> 3)) & 0b0000000000011111);

    return color;
}

static LEGUAN_ALWAYS_INLINE void LCD_Set(const LCD_Color_t *color) {
    LCD_Data16(*(const uint16_t*)color);
}

result_t LCD_Pixel(uint16_t x, uint16_t y) {
    if (x > LCD_WIDTH || y > LCD_HEIGHT)
        return RESULT_INVALID_ARGUMENTS;

    LCD_SetDrawArea(x, y, x, y);
    LCD_EnableDrawMode();

    LCD_Set(&m_foreground_color);

    return RESULT_SUCCESS;
}

result_t LCD_FilledRect(uint16_t x, uint16_t y, uint16_t width, uint16_t height, uint16_t angle) {
    if (x > LCD_WIDTH || y > LCD_HEIGHT)
        return RESULT_INVALID_ARGUMENTS;

    uint16_t next_x;
    uint16_t next_y;

    /* Switch case to determine if the lines are horizontal or vertical.
     * If so, the slow trigonometry functions can be avoided.*/
    switch (angle) {
    case 0:
        next_x = x;
        next_y = y + height;
        break;
    case 90:
        next_x = x + height;
        next_y = y;
        break;
    case 180:
        next_x = x;
        next_y = y - height;
        break;
    case 270:
        next_x = x - height;
        next_y = y;
        break;
    case 360:
        next_x = x;
        next_y = y + height;
        break;
    default:
        ;
        float rad = ((2 * M_PI) / 360.0) * (float) angle;
        next_x = x + sinf(rad) * height;
        next_y = y + cosf(rad) * height;
        break;
    }

    int16_t delta_x = +abs((int32_t)next_x - (int32_t)x);
    int16_t delta_y = -abs((int32_t)next_y - (int32_t)y);
    int16_t speed_x = x < next_x ? 1 : -1;
    int16_t speed_y = y < next_y ? 1 : -1;
    int16_t error = delta_x + delta_y;

    /* Bresenham's line drawing algorithm with a line drawn at every point with the length of the rectangle */
    while (true) {
        if (x == next_x && y == next_y)
			break;

        LCD_Pixel(x, y);
        LCD_TiltedLine(x, y, width, angle);

        if (x != next_x) {
            if ((error * 2) > delta_y) {
                error += delta_y;
                x += speed_x;
            }
        }

        if (y != next_y) {
            if ((error * 2) < delta_x) {
                error += delta_x;
                y += speed_y;
            }
        }
    }

    return RESULT_SUCCESS;
}

result_t LCD_Rect(uint16_t x, uint16_t y, uint16_t width, uint16_t height, uint16_t angle) {
    uint16_t next_x, next_y;

    LCD_TiltedLine(x, y, width, angle);
    LCD_TiltedLine(x, y, height, angle + 270);

    /* Switch case to determine if the lines are horizontal or vertical.
     * If so, the slow trigonometry functions can be avoided.*/
    switch (angle) {
    case 0:
        next_x = x;
        next_y = y + height;

        LCD_TiltedLine(next_x, next_y, width, angle);

        next_x = x + width;
        next_y = y;

        LCD_TiltedLine(next_x, next_y, height, 270);
        break;
    case 90:
        next_x = x + height;
        next_y = y;

        LCD_TiltedLine(next_x, next_y, width, angle);

        next_x = x;
        next_y = y - width;

        LCD_TiltedLine(next_x, next_y, height, 0);
        break;
    case 180:
        next_x = x;
        next_y = y - height;

        LCD_TiltedLine(next_x, next_y, width, angle);

        next_x = x - width;
        next_y = y;

        LCD_TiltedLine(next_x, next_y, height, 90);
        break;
    case 270:
        next_x = x - height;
        next_y = y;

        LCD_TiltedLine(next_x, next_y, width, angle);

        next_x = x - height;
        next_y = y + width;

        LCD_TiltedLine(next_x, next_y, height, 0);
        break;
    case 360:
        next_x = x;
        next_y = y + height;

        LCD_TiltedLine(next_x, next_y, width, angle);

        next_x = x + width;
        next_y = y;

        LCD_TiltedLine(next_x, next_y, height, 270);
        break;
    default: {
            float rad = ((2 * M_PI)/360.0) * (float)angle;

            next_y = y + cosf(rad) * height;
            next_x = x + sinf(rad) * height;

            LCD_TiltedLine(next_x,next_y,width,angle);

            next_x = x + cosf(rad) * width;
            next_y = y - sinf(rad) * width;

            LCD_TiltedLine(next_x, next_y, height, angle + 270);
        }
        break;
    }

    return RESULT_SUCCESS;
}

result_t LCD_Line(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2) {
    if (x1 > LCD_WIDTH || y1 > LCD_HEIGHT)
        return RESULT_INVALID_ARGUMENTS;
    if (x2 > LCD_WIDTH || y2 > LCD_HEIGHT)
        return RESULT_INVALID_ARGUMENTS;

    int16_t delta_x = +abs((int32_t)x2 - (int32_t)x1);
    int16_t delta_y = -abs((int32_t)y2 - (int32_t)y1);

    int16_t speed_x = x1 < x2 ? 1 : -1;
    int16_t speed_y = y1 < y2 ? 1 : -1;

    int16_t error = delta_x + delta_y;

    /* Bresenham's line drawing algorithm */
    while (true) {
        if (x1 == x2 && y1 == y2)
			break;

        LCD_Pixel(x1, y1);

        if (x1 != x2) {
            if ((error * 2) > delta_y) {
                error += delta_y;
                x1 += speed_x;
            }
        }

        if (y1 != y2) {
            if ((error * 2) < delta_x) {
                error += delta_x;
                y1 += speed_y;
            }
        }
    }

    return RESULT_SUCCESS;
}

result_t LCD_TiltedLine(uint16_t x, uint16_t y, uint16_t length, uint16_t angle){
    uint16_t next_x, next_y;

    /* Switch case to determine if the line is horizontal or vertical.
     * If so, the slow trigonometry functions can be avoided.*/
    switch (angle){
    case 0:
        next_x = x + length;
        next_y = y;
        break;
    case 90:
        next_x = x;
        next_y = y - length;
        break;
    case 180:
        next_x = x - length;
        next_y = y;
        break;
    case 270:
        next_x = x;
        next_y = y + length;
        break;
    case 360:
        next_x = x + length;
        next_y = y;
        break;
    default: {
            float rad = ((2 * M_PI)/360.0) * (float)angle;

            next_x = x + cosf(rad) * length;
            next_y = y - sinf(rad) * length;
        }
        break;
    }

    LCD_Line(x,y,next_x,next_y);

    return RESULT_SUCCESS;
}

static void LCD_CircleImpl(int16_t center_x, int16_t center_y, int16_t x, int16_t y) {
    LCD_Pixel(center_x + x, center_y + y);
    LCD_Pixel(center_x - x, center_y + y);
    LCD_Pixel(center_x + x, center_y - y);
    LCD_Pixel(center_x - x, center_y - y);

    LCD_Pixel(center_x + y, center_y + x);
    LCD_Pixel(center_x - y, center_y + x);
    LCD_Pixel(center_x + y, center_y - x);
    LCD_Pixel(center_x - y, center_y - x);
}

result_t LCD_Circle(uint16_t center_x, uint16_t center_y, uint16_t radius) {
    /* Explicitly not check for invalid positions here because
     * placing a circle outside of the viewing window might
     * be useful to draw e.g semi-circles
     */

    int16_t x = 0;
    int16_t y = radius;
    int16_t d = 3 - 2 * radius;

    LCD_CircleImpl(center_x, center_y, x, y);

    /* Bresenham's circle drawing algorithm */
    while (y >= x) {
        x += 1;

        if (d > 0) {
            y -= 1;
            d += 4 * (x - y) + 10;
        } else {
            d += 4 * x + 6;
        }

        LCD_CircleImpl(center_x, center_y, x, y);
    }

   return RESULT_SUCCESS;
}

result_t LCD_FilledCircle(uint16_t center_x, uint16_t center_y, uint16_t radius){
    int16_t x, y;
    int16_t radError;

    x = radius;
    y = 0;
    radError = 1 - x;

    while (x >= y) {

        LCD_Line(x + center_x, y + center_y, -x + center_x, y + center_y);
        LCD_Line(y + center_x, x + center_y, -y + center_x, x + center_y);
        LCD_Line(-x + center_x, -y + center_y, x + center_x, -y + center_y);
        LCD_Line(-y + center_x, -x + center_y, y + center_x, -x + center_y);

        y++;
        if (radError < 0) {
            radError += 2 * y + 1;
        } else {
            x--;
            radError += 2 * (y - x + 1);
        }
    }
    return RESULT_SUCCESS;
}

result_t LCD_Triangle(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2){
    if ((x0 > LCD_WIDTH || y0 > LCD_HEIGHT)||(x1 > LCD_WIDTH || y1 > LCD_HEIGHT)||(x2 > LCD_WIDTH || y2 > LCD_HEIGHT))
           return RESULT_INVALID_ARGUMENTS;

    LCD_Line(x0,y0,x1,y1);
    LCD_Line(x1,y1,x2,y2);
    LCD_Line(x2,y2,x0,y0);

    return RESULT_SUCCESS;
}

result_t LCD_EquiTriangle(uint16_t x, uint16_t y, uint16_t s, LCD_Orientation_t orientation){
    if (x > LCD_WIDTH || y > LCD_HEIGHT)
        return RESULT_INVALID_ARGUMENTS;

    uint16_t h = sqrt(3) / 2 * s;
	uint16_t xCorner[3], yCorner[3];

    switch (orientation) {
    case North:
        xCorner[0] = x - s / 2;
        yCorner[0] = y + h / 2;
        xCorner[1] = x + s / 2;
        yCorner[1] = y + h / 2;
        xCorner[2] = x;
        yCorner[2] = y - h / 2;
        break;
    case East:
        xCorner[0] = x - h / 2;
        yCorner[0] = y - s / 2;
        xCorner[1] = x - h / 2;
        yCorner[1] = y + s / 2;
        xCorner[2] = x + h / 2;
        yCorner[2] = y;
        break;
    case South:
        xCorner[0] = x + s / 2;
        yCorner[0] = y - h / 2;
        xCorner[1] = x - s / 2;
        yCorner[1] = y - h / 2;
        xCorner[2] = x;
        yCorner[2] = y + h / 2;
        break;
    case West:
        xCorner[0] = x + h / 2;
        yCorner[0] = y + s / 2;
        xCorner[1] = x + h / 2;
        yCorner[1] = y - s / 2;
        xCorner[2] = x - h / 2;
        yCorner[2] = y;
        break;
    }

    LCD_Triangle(
		xCorner[0], yCorner[0],
		xCorner[1], yCorner[1],
		xCorner[2], yCorner[2]
	);

    return RESULT_SUCCESS;
}

result_t LCD_SetFontSize(uint16_t size){
    if (size < 1 || size > 5)
        return RESULT_INVALID_ARGUMENTS;
    m_console_font_size = size;
    return RESULT_SUCCESS;
}

uint16_t LCD_GetFontSize(){
    return m_console_font_size;
}

result_t LCD_Character(uint16_t x, uint16_t y, char c) {
    /* Set working region same size as character bitmap times the scaling Factor */
    R_TRY(LCD_SetDrawArea(x, y, x + (CONSOLE_FONT_CHAR_WIDTH+1) * m_console_font_size - 1, y + (CONSOLE_FONT_CHAR_HEIGHT+1) * m_console_font_size - 1));
    LCD_EnableDrawMode();

    /* Draw the character mit the scaling factor */
    for (uint32_t i = 0; i < (CONSOLE_FONT_CHAR_WIDTH * CONSOLE_FONT_CHAR_HEIGHT + 1) * m_console_font_size; i++) {
        uint32_t index = i / (8 * m_console_font_size);
            if (ConsoleFont[(uint8_t) c][index] & (1 << (i % 8)))
                for(int j = 0; j < m_console_font_size; j++){
                LCD_Set(&m_foreground_color);
                }
            else {
                for(int j = 0; j < m_console_font_size; j++){
                LCD_Set(&m_background_color);
                }
            }
        }

    return RESULT_SUCCESS;
}

result_t LCD_String(uint16_t start_x, uint16_t start_y, const char *string) {
    uint16_t x = start_x, y = start_y;
    while (true) {
        char c = *string++;

        if (c == '\n') {
            x = 0;
            y += CONSOLE_FONT_CHAR_HEIGHT * m_console_font_size;
            continue;
        } else if (c == '\x00') {
            break;
        }

        if (LCD_Character(x, y, c) != RESULT_SUCCESS)
            return RESULT_INVALID_ARGUMENTS;

        /* Advance cursor horizontally */
        x += CONSOLE_FONT_CHAR_WIDTH * m_console_font_size + 1;
    }

    m_console_cursor_x = x;
    m_console_cursor_y = y;

    return RESULT_SUCCESS;
}

result_t LCD_StringContinue(const char *string) {
    return LCD_String(m_console_cursor_x, m_console_cursor_y, string);
}

void LCD_Clear(void) {
    /* Set working region fill entire screen */
    LCD_SetDrawArea(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
    LCD_EnableDrawMode();

    for (uint32_t pixel = 0; pixel < LCD_WIDTH * LCD_HEIGHT; pixel++) {
        LCD_Set(&m_background_color);
    }

    m_console_cursor_x = 0;
    m_console_cursor_y = 0;

}

result_t LCD_DrawBuffer(LCD_Color_t *buffer, size_t size) {
    if (buffer == NULL || size == 0)
        return RESULT_INVALID_ARGUMENTS;

    LCD_EnableDrawMode();
    for (uint32_t i = 0; i < size; i++)
        LCD_Data16(*(uint16_t*)&buffer[i]);

    return RESULT_SUCCESS;
}

/* Bitmap */

result_t LCD_DrawBitmap(const uint16_t *image, uint16_t x, uint16_t y, uint16_t width, uint16_t height, LCD_Orientation_t orientation) {
    if (image == NULL || width == 0 || height == 0 || (x > LCD_WIDTH) || (y > LCD_HEIGHT))
        return RESULT_INVALID_ARGUMENTS;

    LCD_Color_t color;

    switch (orientation) {
    case North:
        LCD_SetDrawArea(x, y, x + width - 1, y + height - 1);
        LCD_EnableDrawMode();

        for (uint32_t i = 0; i < width * height; i++) {
            color.r = (image[i] & 0b1111100000000000) >> 11;
            color.g = (image[i] & 0b0000011111100000) >> 5;
            color.b = (image[i] & 0b0000000000011111);
            LCD_Set(&color);
        }

        break;
    case East:
        LCD_SetDrawArea(x, y, x + height - 1, y + width - 1);
        LCD_EnableDrawMode();

        for (uint32_t y = width; y > 0; y--) {
            for (uint32_t x = 0; x < height; x++) {
                color.r = (image[((x + 1) * width - 1) + (y - width)] & 0b1111100000000000) >> 11;
                color.g = (image[((x + 1) * width - 1) + (y - width)] & 0b0000011111100000) >> 5;
                color.b = (image[((x + 1) * width - 1) + (y - width)] & 0b0000000000011111);
                LCD_Set(&color);
            }
        }

        break;
    case South:
        LCD_SetDrawArea(x, y, x + width - 1, y + height - 1);
        LCD_EnableDrawMode();

        for (uint32_t i = width * height - 1; i > 0; i--) {
            color.r = (image[i] & 0b1111100000000000) >> 11;
            color.g = (image[i] & 0b0000011111100000) >> 5;
            color.b = (image[i] & 0b0000000000011111);
            LCD_Set(&color);
        }

        break;
    case West:
        LCD_SetDrawArea(x, y, x + height - 1, y + width - 1);
        LCD_EnableDrawMode();

        for (uint32_t y = width; y > 0; y--) {
            for (uint32_t x = height; x > 0; x--) {
                color.r = (image[(x - 1)*width + (width - y)] & 0b1111100000000000) >> 11;
                color.g = (image[(x - 1)*width + (width - y)] & 0b0000011111100000) >> 5;
                color.b = (image[(x - 1)*width + (width - y)] & 0b0000000000011111);
                LCD_Set(&color);
            }
        }

        break;
    }

    return RESULT_SUCCESS;
}

/* Touch */

static void LCD_TouchEnable(void) {
	GPIO_SetValue(TouchCS, true);
}

static void LCD_TouchDisable(void) {
	GPIO_SetValue(TouchCS, false);
}

LEGUAN_MAYBE_UNUSED
static result_t LCD_TouchReadRegister(uint8_t address, uint8_t *value) {
	if (value == NULL)
		return RESULT_INVALID_ARGUMENTS;

    uint8_t send_buffer[]    = { address << 1 | 1, 0 };
    uint8_t receive_buffer[] = { 0, 0 };

    LCD_TouchEnable();
    result_t result = SPI_WriteRead(SPI_Touch, receive_buffer, send_buffer, 2);
    LCD_TouchDisable();

    *value = receive_buffer[1];

    return result;
}

LEGUAN_MAYBE_UNUSED
static result_t LCD_TouchReadBuffer(uint8_t address, uint8_t *buffer, size_t size) {
	if (buffer == NULL || size == 0)
		return RESULT_INVALID_ARGUMENTS;

    address = (address << 1) | 1;

    LCD_TouchEnable();
    result_t result = SPI_WriteRead(SPI_Touch, buffer, &address, size);
    LCD_TouchDisable();

    return result;
}

static result_t LCD_TouchSendCommand(uint8_t address) {
    address <<= 1;

    LCD_TouchEnable();
    result_t result = SPI_Write(SPI_Touch, &address, 1);
    LCD_TouchDisable();

    return result;
}

result_t LCD_TouchInit(void) {
	uint8_t buffer[] = {
		(0x01 << 1), (1 << 6),
		(0x02 << 1), 0x00,
		(0x03 << 1), (3 << 6) | (3 << 4) | (2 << 2) | (2 << 0),
		(0x04 << 1), (2 << 6) | (2 << 4) | (2 << 2) | (2 << 0),
		(0x05 << 1), (7 << 4) | (7 << 0),
		(0x06 << 1), (0 << 4) | (0 << 0),
		(0x07 << 1), (3 << 4) | (3 << 0),
		(0x0A << 1), (0 << 5) | (3 << 3) | (2 << 1),
		(0x0B << 1), (1 << 1) | (1 << 2)
	};

	LCD_TouchEnable();
	CORE_Delay(3);
	R_TRY(SPI_Write(SPI_Touch, buffer, sizeof(buffer)));
	LCD_TouchDisable();

	m_touchMinX = 0;
	m_touchMinY = 0;
	m_touchMaxX = LCD_WIDTH;
	m_touchMaxY = LCD_HEIGHT;

	/* Start first measurement */
    LCD_TouchStartMeasurement();

    return RESULT_SUCCESS;
}

result_t LCD_TouchSetCalibrationValues(uint16_t minX, uint16_t minY, uint16_t maxX, uint16_t maxY) {
	if (minX >= maxX || minY >= maxY) return RESULT_INVALID_ARGUMENTS;

	m_touchMinX = minX;
	m_touchMaxX = maxX;
	m_touchMinY = minY;
	m_touchMaxY = maxY;

	return RESULT_SUCCESS;
}

void LCD_TouchStartMeasurement(void) {
    LCD_TouchSendCommand(LCD_TOUCH_CMD_MEASURE_XY);
}

void LCD_TouchSetTouchCallback(LCD_TouchCallback_t callback) {

}

result_t LCD_TouchGetPosition(LCD_TouchPosition_t *position) {
	if (position == NULL)
		return RESULT_INVALID_ARGUMENTS;

    uint8_t send_buffer[5] = { (LCD_TOUCH_CMD_MEASURE_X << 1) | 1, 0, 0, 0, 0 };
    uint8_t recv_buffer[5] = { 0 };

    uint32_t retry = 0;
	do {
		LCD_TouchStartMeasurement();
		LCD_TouchEnable();
		CORE_Delay(3);

		memset(recv_buffer, 0x00, 5);

		R_TRY(SPI_WriteRead(SPI_Touch, recv_buffer, send_buffer, 5));

		LCD_TouchDisable();

		retry++;
		if (retry > 10) return RESULT_OPERATION_FAILED;
    } while ((recv_buffer[2] & 0b11) == 0b11 || (recv_buffer[4] & 0b11) == 0b11);

	LCD_TouchStartMeasurement();

    if ((recv_buffer[2] & 0b11) != 0b00 || (recv_buffer[4] & 0b11) != 0b00) {
    	position->x = 0;
    	position->y = 0;
    } else {
    	position->x = recv_buffer[1] << 4 | recv_buffer[2] >> 4;
    	position->y = recv_buffer[3] << 4 | recv_buffer[4] >> 4;
    }

    position->x = ((float32_t)position->x / 0x1000) * (m_touchMaxX + m_touchMinX) - m_touchMinX;
    position->y = ((float32_t)(0x1000 - position->y) / 0x1000) * (m_touchMaxY + m_touchMinY) - m_touchMinY;

    return RESULT_SUCCESS;
}
