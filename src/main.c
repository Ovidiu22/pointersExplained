/*******************************/
/*** Created by Ovidiu Sabau ***/
/***	27th December 2022	 ***/
/*******************************/

/*----------------- Include -------------------*/
#include <stdint.h>
#include "LCD.h"
void L1Function(uint8_t, uint8_t *, uint8_t, uint8_t *);
void L2Function(uint8_t, uint8_t *, uint8_t, uint8_t *);

/*-------------- Main function ----------------*/
int main(void)
{
	initLCD();
	
	uint8_t x = 12;
	uint8_t y = 38;
	
	//updateLCDScreen(row on LCD, "Text 1", number, "Text 2");
	updateLCDScreen(1, "L0 x: ", x, "NONE");		// x value
	updateLCDScreen(2, "L0 &x: ", &x, "NONE");		// x address
 	updateLCDScreen(3, "L0 y: ", y, "NONE");		// y value
 	updateLCDScreen(4, "L0 &y: ", &y, "NONE");		// y address
	_delay_ms(3000);
	
	L1Function(x, &x, y, &y);
	
	updateLCDScreen(1, "L0 x: ", x, "NONE");		// x value
	updateLCDScreen(2, "L0 &x: ", &x, "NONE");		// x address
	updateLCDScreen(3, "L0 y: ", y, "NONE");		// y value
	updateLCDScreen(4, "L0 &y: ", &y, "NONE");		// y address
	
	
	return 0;
}


void L1Function(uint8_t x, uint8_t * xAdd, uint8_t y, uint8_t * yAdd)
{
	x = 11;
	y = 72;
	*yAdd = 36;
	updateLCDScreen(1, "L1 x: ", x, "NONE");		// x value
	updateLCDScreen(2, "L1 &x: ", xAdd, "NONE");	// x address
 	updateLCDScreen(3, "L1 y: ", *yAdd, "NONE");	// y value taken from address
 	updateLCDScreen(4, "L1 &y: ", yAdd, "NONE");	// y address
	_delay_ms(3000);
	
	L2Function(x, xAdd, y, yAdd);
}

void L2Function(uint8_t x, uint8_t * xAdd, uint8_t y, uint8_t * yAdd)
{
	updateLCDScreen(1, "L2 x: ", x, "NONE");		// x value
	updateLCDScreen(2, "L2 &x: ", xAdd, "NONE");	// x address
	updateLCDScreen(3, "L2 y: ", y, "NONE");		// y value
	updateLCDScreen(4, "L2 &y: ", yAdd, "NONE");	// y address

	_delay_ms(3000);
}