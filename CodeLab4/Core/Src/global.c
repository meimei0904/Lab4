/*
 * global.c
 *
 *  Created on: Nov 1, 2024
 *      Author: MY LE
 */
#include "global.h"
int mode = 1;
int red_value, yellow_value, green_value;
int red_draft, yellow_draft, green_draft;

void LedTimeDurationInit() {
	red_value = RED_INIT;
	yellow_value = YELLOW_INIT;
	green_value = GREEN_INIT;
	red_draft = red_value;
	yellow_draft = yellow_value;
	green_draft = green_value;
}

int getMode() {
	return mode;
}
