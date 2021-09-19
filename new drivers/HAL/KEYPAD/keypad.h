#ifndef KEYPAD_H_
#define KEYPAD_H_
#include "../../LIB/STD_TYPES.h"
#include <util/delay.h>
#include "../../MCAL/DIO/DIO_interface.h"

uint8_t KeyPad_getPressedKey();

#define N_col 4
#define N_row 4

#define KEYPAD_PORT PORTC

#endif /* KEYPAD_H_ */
