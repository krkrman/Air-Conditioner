/*
 * new drivers.c
 *
 * Created: 9/16/2021 11:56:40 PM
 * Author : Karim Essam
 */ 
#define F_CPU 1000000UL

#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/ADC/ADC_interface.h"
#include "HAL/LCD/LCD_interface.h"
#include "HAL/LCD/lcd.h"
#include "HAL/MOTOR/motor.h"
#include "HAL/MOTOR/MOTOR_interface.h"
#include "HAL/LM35/LM35_interface.h"

#include "HAL/KEYPAD/KEYPAD_interface.h"
#include "HAL/KEYPAD/keypad.h"
#include <util/delay.h>


void displayLCDInitalState()
{
	LCD_clearScreen();
	LCD_displayString("Enter degree:");
}
void displayDegreeWarning()
{
	LCD_clearScreen();
	LCD_displayString("degree is 15:30");
	_delay_ms(2000);
}

void displayNumber(u8* stringDegree , u8* index , s8 charater){
	stringDegree[(*index)++] = (u8)charater;
	stringDegree[*index] = '\0';
	LCD_clearScreen();
	LCD_displayString(stringDegree);
}

void displayResutlt(u8* desiredDegree , u8* stringDegree)
{
	*desiredDegree = (u8)atoi(stringDegree);
	if (*desiredDegree > 30 || *desiredDegree < 15)
	{
		displayDegreeWarning();
	}
	displayLCDInitalState();
}
int main(void)
{	
	/********* KEYPAD INIT ************************/
	Keypad_t keyPad;

	keyPad.rows = 4;
	keyPad.columns = 4;
	u8 rowPins[4];
	u8 rowPorts[4];
	
	u8 columnPins[4];
	u8 columnPorts[4];
	
	for (int i = 0; i < 4 ;i++)
	{
		rowPins[i] = i;
		rowPorts[i] = PORTC;
		columnPins[i] = i+4;
		columnPorts[i] = PORTC;
	}
	keyPad.rowPins = rowPins;
	keyPad.columnPins = columnPins;
	keyPad.rowPorts = rowPorts;
	keyPad.columnPorts = columnPorts;
	
	u8 map[4][4] =
	{{'7','8','9','/'},
	{'4','5','6','*'},
	{'1','2','3','-'},
	{'c','0','=','+'}};
	keyPad.map = map;
	
	KEYPAD_voidInit(&keyPad);
		
	/********************************************************************/
	LM35 lm35 = {.analogPin = 0};
	LM35_voidInit();	
		
	LCD_init();
	displayLCDInitalState();
	
	Motor_t motor = {.pin1 = 0 , .pin2 = 2 ,. PWM_pin = 1 , .port = PORTD};
	MOTOR_voidInit(&motor);
	
	u8 stringDegree[5];
	u8 index = 0;
	u8 desiredDegree = 100;
	u8 realDegree = 0;

    while (1) 
    {
		realDegree = LM35_u8GetTemp(&lm35);
		
		s8 character = KEYPAD_u8GetKey(&keyPad);
		if (character != (s8)-1 && character != '=')
		{
			displayNumber(stringDegree , &index , character);

		} else if (character == '=')
		{
			index = 0;
			displayResutlt(&desiredDegree , stringDegree);
		}
		
		if (realDegree > desiredDegree)
		{
			MOTOR_voidRotateWithSoftwarePWM(&motor , 100 , ROTATION_CLOCK_WISE);
		}else
		{
			MOTOR_voidStop(&motor);
		}
    }
}

