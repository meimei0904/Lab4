/*
 * button.h
 *
 *  Created on: Nov 28, 2024
 *      Author: MY LE
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

// Khai báo các hàm xử lý nút nhấn
void init_buffer();
void button_reading(void);
unsigned char is_button_pressed(unsigned char index);
unsigned char is_button_pressed_1s(unsigned char index);
unsigned char is_button_held(unsigned char index);
void reset_flagForButtonHold(unsigned char index);

#endif /* INC_BUTTON_H_ */
