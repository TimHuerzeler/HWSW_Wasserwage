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
  *  @file lcd.h
  *  @ingroup peripherals
  *  @author Nikolaij Saegesser, Nicola Stettler, Serge Weidmann
  *  @brief Display MMIO Registers
  */

#pragma once

#if defined(__cplusplus)
extern "C" {
#endif

/* Includes */
#include "common/types.h"
#include "common/attributes.h"
#include "common/mmio.h"
#include "common/color.h"

/* Macros */
#define LCD_BASE_ADDRESS    0xC0000000ULL

#define LCD_WIDTH           800UL
#define LCD_HEIGHT          480UL

#define LCD                 MMIO_MAP(LCD_BASE_ADDRESS, LCD_MemoryMap_t)

/** LCD Commands **/
#define LCD_CMD_RESET								0x01
#define LCD_CMD_SET_DISPLAY_OFF                     0x28
#define LCD_CMD_SET_DISPLAY_ON                      0x29
#define LCD_CMD_SET_ADDRESS_MODE                    0x36
#define LCD_CMD_SET_PIXEL_DATA_INTERFACE            0xF0
#define LCD_CMD_SET_COLUMN_ADDRESS                  0x2A
#define LCD_CMD_SET_PAGE_ADDRESS                    0x2B
#define LCD_CMD_WRITE_MEMORY_START                  0x2C
#define LCD_CMD_READ_MEMORY_START                   0x2E
#define LCD_CMD_WRITE_MEMORY_CONTINUE               0x3C
#define LCD_CMD_READ_MEMORY_CONTINUE                0x3E
#define LCD_CMD_SET_SCROLL_AREA		                0x33
#define LCD_CMD_SET_SCROLL_START		            0x37

/** Touch Registers **/
#define LCD_TOUCH_REG_GENERAL_STATUS                0x00
#define LCD_TOUCH_REG_GENERAL_CONFIG                0x01
#define LCD_TOUCH_REG_MEASURE_RES_CONFIG            0x02
#define LCD_TOUCH_REG_MEASURE_AVERAGE_CONFIG        0x03
#define LCD_TOUCH_REG_ADC_SAMPLE_TIME_CONFIG        0x04
#define LCD_TOUCH_REG_PANEL_SETUP_TIME_CONFIG       0x05
#define LCD_TOUCH_REG_DELAY_CONVERSION_CONFIG       0x06
#define LCD_TOUCH_REG_TOUCH_DETECT_PULLUP_CONFIG    0x07
#define LCD_TOUCH_REG_AUX_MEASURE_CONFIG            0x0A
#define LCD_TOUCH_REG_OP_MODE_CONFIG                0x0B

/** Touch Commands **/
#define LCD_TOUCH_CMD_MEASURE_X                     0x52
#define LCD_TOUCH_CMD_MEASURE_XY                    0x70

/* Types */

#define LCD_COLOR(r, g, b) BGR565_COLOR(r, g, b)
typedef BGR565_t LCD_Color_t;

typedef struct LEGUAN_PACKED {
	volatile reg16_t cmd;
#if defined(LEGUAN_FIRMWARE_CPU)
    uint8_t padding[0x100000 - sizeof(reg16_t)];
#endif
	union {
		volatile uint8_t data8;
		volatile uint16_t data16;
	};
} LCD_MemoryMap_t;

typedef void (*LCD_TouchCallback_t)(void);

typedef struct {
	uint16_t x, y;
} LCD_TouchPosition_t;

typedef enum {
	North,
	East,
	South,
	West
} LCD_Orientation_t;

/* Functions */

/** Display **/

/**
 * @brief Initializes the LCD peripheral
 * @return Status result
 */
result_t LCD_Init(void);

/**
 * @brief LCD Stream function for use with the logger
 * @param string String to print
 * @param new_line Advance a line after printing
 */
void LCD_Stream(const char *string, bool new_line);

/**
 * @brief Sets the cursor X position for console logging
 * @param x X coordinate of the cursor
 */
void LCD_SetCursorX(uint16_t x);

/**
 * @brief Sets the cursor Y position for console logging
 * @param y Y coordinate of the cursor
 */
void LCD_SetCursorY(uint16_t y);

/**
 * @brief Sets the area, which is to be scrolled. Note that only the whole width of the screen can be scrolled.
 * @param y1 Start of the scrolling area
 * @param y2 End of the scrolling area
 * @return Status result
 */
result_t LCD_SetScrollArea(uint16_t y1, uint16_t y2);

/**
 * @brief Scrolls the area defined with LCD_SetScrollArea().
 * @param lines Amount of lines the defined area is scrolled
 * @return Status result
 */
result_t LCD_Scroll(int16_t lines);

/**
 * @brief Sets the LCD foreground color (used for primitives, text, etc)
 * @param color Foreground color
 */
void LCD_SetForegroundColor(color_t color);

/**
 * @param Sets the LCD background color (used for the background)
 * @param color Foreground color
 */
void LCD_SetBackgroundColor(color_t color);

/**
 * @brief Returns the actual set Foreground Color
 * @param *color Pointer to the color Variable, in which the actual foreground color is to be stored.
 */
void LCD_GetForegroundColor(color_t *color);

/**
 * @brief Returns the set Background Color
 * @param *color Pointer to the color Variable, in which the actual background color is to be stored.
 */
void LCD_GetBackgroundColor(color_t *color);

/**
 * @brief Calculates the RGB565 Color out of RGB888 values and returns the struct with the values.
 * @param r RGB888 Red Value
 * @param g RGB888 Green Value
 * @param b RGB888 Blue Value
 * @return actual Background Color
 */
color_t LCD_ColorConvert(uint8_t r, uint8_t g, uint8_t b);

/**
 * @brief Overwrites all content with the background color
 */
void LCD_Clear(void);

/**
 * @brief Draws a single pixel with the current foreground color
 * @param x X coordinate of the pixel
 * @param y Y coordinate of the pixel
 * @return Status result
 */
result_t LCD_Pixel(uint16_t x, uint16_t y);

/**
 * @brief Draws a filled rectangle with the current foreground color
 * @param x X coordinate of the top left corner
 * @param y Y coordinate of the top left corner
 * @param width Rectangle width
 * @param height Rectangle height
 * @param angle Angle by which the rectangle is rotated (0 for no rotation)
 * @return Status result
 */
result_t LCD_FilledRect(uint16_t x, uint16_t y, uint16_t width, uint16_t height, uint16_t angle);

/**
 * @brief Draws the outlines of a rectangle. If the Rectangle is to be tilted, the turning point is the top left corner.
 * @param x X coordinate of the top left corner
 * @param y Y coordinate of the top left corner
 * @param width Rectangle width
 * @param height Rectangle height
 * @param angle	Angle by which the rectangle is rotated (0 for no rotation)
 * @return Status result
 */
result_t LCD_Rect(uint16_t x, uint16_t y, uint16_t width, uint16_t height, uint16_t angle);

/**
 * @brief Draws a line from start to end with the current foreground color
 * @param x1 X coordinate of the start of the line
 * @param y1 Y coordinate of the start of the line
 * @param x2 X coordinate of the end of the line
 * @param y2 Y coordinate of the end of the line
 * @return Status result
 */
result_t LCD_Line(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);

/**
 * @brief Draws a tilted Line with a defined length. The turning point is the start coordinates of the line. (Horizontal Line: angle = 0, Vertical Line: angle = 90)
 * @param x X coordinate of the Line's starting point
 * @param y Y coordinate of the Line's starting point
 * @param l	Length of the line
 * @param angle	Turning angle in degrees of the line
 * @return Status result
 */
result_t LCD_TiltedLine(uint16_t x, uint16_t y, uint16_t l, uint16_t angle);

/**
 * @brief Draws the outline of a circle with the current foreground color
 * @param center_x X coordinate of the center of the circle
 * @param center_y Y coordinate of the center of the circle
 * @param radius Circle radius
 * @return Status result
 */
result_t LCD_Circle(uint16_t center_x, uint16_t center_y, uint16_t radius);

/**
 * @brief Draws a filled circle with the current foreground color
 * @param center_x X coordinate of the center of the circle
 * @param center_y Y coordinate of the center of the circle
 * @param radius Circle radius
 * @return Status result
 */
result_t LCD_FilledCircle(uint16_t center_x, uint16_t center_y, uint16_t radius);

/**
 * @brief Draws the outlines of a Triangle
 * @param x0-x2 X coordinates of the triangle's edges
 * @param y0-y2 Y coordinates of the triangle's edges
 * @return Status result
 */
result_t LCD_Triangle(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);

/**
 * @brief Draws the outlines of an equilateral Triangle.
 * @param x X coordinate of the triangle's center
 * @param y Y coordinate of the triangle's center
 * @param s	Length of the triangle's sides
 * @param orientation Orientation of the triangle.
 * @return Status result
 */
result_t LCD_EquiTriangle(uint16_t x, uint16_t y, uint16_t s, LCD_Orientation_t orientation);

/**
 * @brief Sets the Size of the font.
 * @param size New size of the font
 * @return Status result
 */
result_t LCD_SetFontSize(uint16_t size);

/**
 * @brief Returns the current font size.
 * @return Font size
 */
uint16_t LCD_GetFontSize();

/**
 * @brief Draws a ASCII character with the current foreground color
 * @param x X coordinate of the character
 * @param y Y coordinate of the character
 * @param c Character to draw
 * @return Status result
 */
result_t LCD_Character(uint16_t x, uint16_t y, char c);

/**
 * @brief Draws a NULL terminated string with the current foreground color
 * @param start_x Start X coordinate of the string
 * @param start_y Start Y coordinate of the string
 * @param string String to draw
 * @return Status result
 */
result_t LCD_String(uint16_t start_x, uint16_t start_y, const char *string);

/**
 * @brief Draws a formatted string with the current foreground color
 * @param start_x Start X coordinate of the string
 * @param start_y Start Y coordinate of the string
 * @param fmt Format specifier
 * @param ... Format arguments
 * @return Status result
 */
result_t LCD_StringFormat(uint16_t start_x, uint16_t start_y, const char *fmt, ...);

/**
 * @brief Draws a NULL terminated string with the current foreground color continuing where lcd_string left off before
 * @param string String to draw
 * @return Status result
 */
result_t LCD_StringContinue(const char *string);

/**
 * @brief Sets the subarea of the screen that will be drawn to
 * @param x1 X coordinate of the start of the area
 * @param y1 Y coordinate of the start of the area
 * @param x2 X coordinate of the end of the area
 * @param y2 Y coordinate of the end of the area
 * @return Status result
 */
result_t LCD_SetDrawArea(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);

/**
 * @brief Turns on draw mode. Needs to be called after sending any commands
 */
void LCD_EnableDrawMode(void);

/**
 * @brief Draws a buffer of colors to the screen
 * @param buffer Color data
 * @param size Size of buffer
 * @return Status result
 */
result_t LCD_DrawBuffer(LCD_Color_t *buffer, size_t size);

/** Bitmap **/
/**
 * @brief Draws a Bitmap included as .c file.
 * @param image Pointer to the Pixel array
 * @param x X coordinate of the top left corner
 * @param x Y coordinate of the top left corner
 * @param width With of the image in Pixels
 * @param height Height of the image in Pixels
 * @param orientation Direction in which the picture is rotated
 * @return Status result
 */
result_t LCD_DrawBitmap(const uint16_t *image, uint16_t x, uint16_t y, uint16_t width, uint16_t height, LCD_Orientation_t orientation);

/** Touch **/

/**
 * @brief Initializes the LCD Touch Controller
 * @return Status result
 */
result_t LCD_TouchInit(void);

/**
 * @brief Sets the touch calibration values
 * @param minX Minimum X position
 * @param minY Minimum Y position
 * @param maxX Maximum X position
 * @param maxY Maximum Y position
 * @return Status result
 */
result_t LCD_TouchSetCalibrationValues(uint16_t minX, uint16_t minY, uint16_t maxX, uint16_t maxY);

/**
 * @brief Initiates a touch measurement
 */
void LCD_TouchStartMeasurement(void);

/**
 * @brief Registers a callback to be called when the touch screen was touched
 * @param callback Callback to call
 */
void LCD_TouchSetTouchCallback(LCD_TouchCallback_t callback);

/**
 * @brief Gets the currently touched position on the screen.
 * @param position Touch coordinate. (0, 0) if untouched
 * @return Status result
 */
result_t LCD_TouchGetPosition(LCD_TouchPosition_t *position);

#if defined(__cplusplus)
}
#endif
