 /******************************************************************************
 *
 * Module: main.c
 *
 * File Name: main.c
 *
 * Description: Source file for the project
 *
 * Author: Omar Ahmed Anwar Mansour
 *
 *******************************************************************************/

#include "lcd.h"
#include "ultrasonic.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

int main(int argc, char **argv) {

	LCD_init();

	sei();

	Ultrasonic_init();

	LCD_displayString("DISTANCE=     cm");

	uint16 distance = 0;

	while(1){

		distance = Ultrasonic_readDistance();

		LCD_moveCursor(0, 10);


		if(distance < 100){

			LCD_displayCharacter(' ');
		}

		LCD_intgerToString(distance);
	}

}

