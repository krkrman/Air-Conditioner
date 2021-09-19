/*
 * Keypad.c
 *
 *  Created on: Feb 15, 2021
 *      Author: Hp
 */
#include "keypad.h"
#if (N_col==3)
static uint8_t Keypad_4x3_adjustKeyNumber (uint8_t button_number);
#elif (N_col==4)
static uint8_t Keypad_4x4_adjustKeyNumber (uint8_t button_number);
#endif

uint8_t KeyPad_getPressedKey()
{
	uint8_t col,row;
	while(1)
	{
		for(col=0;col<N_col;col++)
		{
			DIO_voidSetPortDirection(KEYPAD_PORT,INPUT);
			DIO_voidSetPinDirection(col+4,KEYPAD_PORT,OUTPUT);
			DIO_voidSetPortValue(KEYPAD_PORT,~ (0b00010000 <<col));
			for(row=0 ; row<N_row ; row++)
			{
				if(!DIO_u8GetPinValue(row,KEYPAD_PORT))
				{
					#if (N_col == 3)
					return Keypad_4x3_adjustKeyNumber((row*N_col)+col+1);
					#elif (N_col == 4)
					return Keypad_4x4_adjustKeyNumber((row*N_col)+col+1);
					#endif
				}
			}

		}

	}

}



#if (N_col==3)
static uint8_t Keypad_4x3_adjustKeyNumber(uint8_t button_number)
{
	switch(button_number)
	{
	case 10: return '*'; break; /* ASCII Code of (*) */
	case 11: return 0 ; break; /* ASCII Code of (0) */
	case 12: return '#'; break; /* ASCII Code of (#) */
	default: return button_number; break;

	}
}
#elif (N_col==4)

static uint8_t Keypad_4x4_adjustKeyNumber(uint8_t button_number)
{
	switch(button_number)
	{
			case 1: return 7;
					break;
			case 2: return 8;
					break;
			case 3: return 9;
					break;
			case 4: return '%'; // ASCII Code of %
					break;
			case 5: return 4;
					break;
			case 6: return 5;
					break;
			case 7: return 6;
					break;
			case 8: return '*'; /* ASCII Code of '*' */
					break;
			case 9: return 1;
					break;
			case 10: return 2;
					break;
			case 11: return 3;
					break;
			case 12: return '-'; /* ASCII Code of '-' */
					break;
			case 13: return 13;  /* ASCII of Enter */
					break;
			case 14: return 0;
					break;
			case 15: return '='; /* ASCII Code of '=' */
					break;
			case 16: return '+'; /* ASCII Code of '+' */
					break;
			default: return button_number;

	}
}

#endif


