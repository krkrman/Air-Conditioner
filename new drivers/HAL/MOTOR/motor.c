typedef unsigned char			uint8_t;
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/TIMER0/TIMER0_interface.h"
#include "../../LIB/STD_TYPES.h"
#include "motor.h"


static ST_MOTOR_channels_t channels;
static uint8_t counter=0;
void MOTOR_init(ST_MOTOR_config_t* config)
{

	TIMER0_voidInit(TIMER0_CTC_MODE , TIMER0_CTC_DISCONNECT , TIMER0_PRESCALAR_64 , 0);
	DIO_PORT_t port = config->port;
	uint8_t pin1 = config->pin1;
	uint8_t pin2 = config->pin2;
	if (port ==PORTA)
	{
		DIO_voidSetPinDirection(pin1,PORTA,OUTPUT);
		DIO_voidSetPinDirection(pin2,PORTA,OUTPUT);
	}
	else if(port==PORTB)
	{
		DIO_voidSetPinDirection(pin1,PORTB,OUTPUT);
		DIO_voidSetPinDirection(pin2,PORTB,OUTPUT);
	}
	else if(port==PORTC)
	{
		DIO_voidSetPinDirection(pin1,PORTC,OUTPUT);
		DIO_voidSetPinDirection(pin2,PORTC,OUTPUT);
	}
	else
	{
		DIO_voidSetPinDirection(pin1,PORTD,OUTPUT);
		DIO_voidSetPinDirection(pin2,PORTD,OUTPUT);
	}

	channels.motor[counter].port =port;
	channels.motor[counter].pin1 =pin1;
	channels.motor[counter].pin2 =pin2;
	counter++;
}
void MOTOR_cw(uint8_t motor_number,uint8_t duty_cycle)
{
	motor_number -=1;
	DIO_PORT_t port = channels.motor[motor_number].port;
	uint8_t pin1 = channels.motor[motor_number].pin1;
	uint8_t pin2 = channels.motor[motor_number].pin2;

	if (port ==PORTA)
	{
		DIO_voidSetPinValue(pin1,PORTA,LOW);
		DIO_voidSetPinValue(pin2,PORTA,HIGH);
	}
	else if(port==PORTB)
	{
		DIO_voidSetPinValue(pin1,PORTB,LOW);
		DIO_voidSetPinValue(pin2,PORTB,HIGH);
	}
	else if(port==PORTC)
	{
		DIO_voidSetPinValue(pin1,PORTC,LOW);
		DIO_voidSetPinValue(pin2,PORTC,HIGH);
	}
	else
	{
		DIO_voidSetPinValue(pin1,PORTD,LOW);
		DIO_voidSetPinValue(pin2,PORTD,HIGH);
	}

	TIMER0_voidSoftwarePWM(PWM_PORT , PWM_PIN , duty_cycle);


}
void MOTOR_ccw(uint8_t motor_number,uint8_t duty_cycle)
{
	motor_number -=1;
	DIO_PORT_t port = channels.motor[motor_number].port;
	uint8_t pin1 = channels.motor[motor_number].pin1;
	uint8_t pin2 = channels.motor[motor_number].pin2;

	if (port ==PORTA)
	{
		DIO_voidSetPinValue(pin1,PORTA,HIGH);
		DIO_voidSetPinValue(pin2,PORTA,LOW);
	}
	else if(port==PORTB)
	{
		DIO_voidSetPinValue(pin1,PORTB,HIGH);
		DIO_voidSetPinValue(pin2,PORTB,LOW);
	}
	else if(port==PORTC)
	{
		DIO_voidSetPinValue(pin1,PORTC,HIGH);
		DIO_voidSetPinValue(pin2,PORTC,LOW);
	}
	else
	{
		DIO_voidSetPinValue(pin1,PORTD,HIGH);
		DIO_voidSetPinValue(pin2,PORTD,LOW);
	}

	TIMER0_voidSoftwarePWM(PWM_PORT , PWM_PIN , duty_cycle);
}
void MOTOR_stop(uint8_t motor_number)
{
	motor_number -=1;
	DIO_PORT_t port = channels.motor[motor_number].port;
	uint8_t pin1 = channels.motor[motor_number].pin1;
	uint8_t pin2 = channels.motor[motor_number].pin2;

	if (port ==PORTA)
	{
		DIO_voidSetPinValue(pin1,PORTA,LOW);
		DIO_voidSetPinValue(pin2,PORTA,LOW);
	}
	else if(port==PORTB)
	{
		DIO_voidSetPinValue(pin1,PORTB,LOW);
		DIO_voidSetPinValue(pin2,PORTB,LOW);
	}
	else if(port==PORTC)
	{
		DIO_voidSetPinValue(pin1,PORTC,LOW);
		DIO_voidSetPinValue(pin2,PORTC,LOW);
	}
	else
	{
		DIO_voidSetPinValue(pin1,PORTD,LOW);
		DIO_voidSetPinValue(pin2,PORTD,LOW);
	}
}

