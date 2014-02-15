/* Copyright (C) 2014 by Arjan van Vught <pm @ http://www.raspberrypi.org/forum/>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:

 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.

 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef BW_I2C_UI_H_
#define BW_I2C_UI_H_

#include <bw_ui.h>
#include <device_info.h>

#include <stdint.h>

#define BW_UI_I2C_BYTE_WAIT_US			14

extern int bw_i2c_ui_start (char);
extern void bw_i2c_ui_end (void);

extern void bw_i2c_ui_reinit(void);

extern void bw_i2c_ui_text_line_1(const char *, uint8_t);
extern void bw_i2c_ui_text_line_2(const char *, uint8_t);
extern void bw_i2c_ui_text_line_3(const char *, uint8_t);
extern void bw_i2c_ui_text_line_4(const char *, uint8_t);

extern void bw_i2c_ui_cls(void);
extern void bw_i2c_ui_set_contrast(uint8_t);
extern void bw_i2c_ui_set_backlight(uint8_t);

extern void bw_i2c_ui_get_backlight(uint8_t *);
extern void bw_i2c_ui_get_contrast(uint8_t *);

extern void bw_i2c_ui_read_id(void);

extern char bw_i2c_ui_read_button(char);
extern char bw_i2c_ui_read_button_last(void);

#endif /* BW_I2C_UI_H_ */
