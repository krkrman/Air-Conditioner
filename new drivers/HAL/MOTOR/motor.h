/*
 * motor.h
 *
 *  Created on: Sep 9, 2021
 *      Author: Hp
 */

#ifndef MOTOR_H_
#define MOTOR_H_


typedef unsigned char			uint8_t;

#define MOTOR_NUMBER 1
#define PWM_PORT PORTB
#define PWM_PIN  1


typedef struct
{
	DIO_PORT_t port;
	uint8_t pin1;
	uint8_t pin2;

}ST_MOTOR_config_t;

typedef struct{
	ST_MOTOR_config_t motor[MOTOR_NUMBER];
}ST_MOTOR_channels_t;

void MOTOR_init(ST_MOTOR_config_t* config);
void MOTOR_cw(uint8_t motor_number,uint8_t duty_cycle);
void MOTOR_ccw(uint8_t motor_number,uint8_t duty_cycle);
void MOTOR_stop(uint8_t motor_number);


#endif /* MOTOR_H_ */
