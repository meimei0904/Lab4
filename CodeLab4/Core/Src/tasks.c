/*
 * task.c
 *
 *  Created on: Nov 28, 2024
 *      Author: MY LE
 */


#include "tasks.h"


void toggle_led(void) {
	HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
}
