/* APIs for DIO Module */

void DIO_voidSetPinDirection (u8 Copy_u8PinNumber, u8 Copy_u8PortNumber, u8 Copy_u8Direction);
void DIO_voidSetPortDirection (u8 Copy_u8PortNumber, u8 Copy_u8PortDirection);

void DIO_voidSetPinValue (u8 Copy_u8PinNumber, u8 Copy_u8PortNumber, u8 Copy_u8Value);
void DIO_voidSetPortValue (u8 Copy_u8PortNumber, u8 Copy_u8Value);

u8 DIO_u8GetPinValue(u8 Copy_u8PinNumber, u8 Copy_u8PortNumber);
u8 DIO_u8GetPortValue(u8 Copy_u8PortNumber);

void DIO_voidTogglePinValue (u8 Copy_u8PinNumber, u8 Copy_u8PortNumber); 


/* Timer Module */

/* Enums */ 
enum TIMER0_Mode{TIMER0_NORMAL_MODE , TIMER0_PHASE_CORRECT_PWM , TIMER0_CTC_MODE , TIMER0_FAST_PWM};
enum TIMER0_CTC{TIMER0_CTC_DISCONNECT,TIMER0_CTC_TOG,TIMER0_CTC_CLR,TIMER0_CTC_SET};
enum TIMER0_PhaseCorrectPWM{TIMER0_PCPWM_DIS,TIMER0_PCPWM_NON_INVERT=2,TIMER0_PCPWM_INVERT};
enum TIMER0_FAST_PWM{TIMER0_FPWM_DIS,TIMER0_FPWM_NON_INVERT=2,TIMER0_FPWM_INVERT};
enum TIMER0_Prescalar{TIMER0_NO_PRESCALAR , TIMER0_PRESCALAR_1 , TIMER0_PRESCALAR_8 , TIMER0_PRESCALAR_64 , TIMER0_PRESCALAR_256,TIMER0_PRESCALAR_1024,TIMER0_COUNTER_T0_FALLING_EDGE , TIMER0_COUNTER_T0_RISING_EDGE};
enum TIMER0_Interrupt{TIMER0_INTERRUPT_OVERFLOW,TIMER0_INTERRUPT_COMPARE};
/* APIS */

void TIMER0_voidInit(enum TIMER0_Mode mode, u8 channelMode,enum TIMER0_Prescalar prescalar,  u8 preload);
u8 TIMER0_u8GetCounter(void);
void TIMER0_voidSetCounterValue(u8 counterValue);
void TIMER0_voidStart(void);
void TIMER0_voidStop(void);
void TIMER0_voidSetDutyCycle(f32 dutyCycle);
void TIMER0_voidSetFrequency(f32 frequency);
void TIMER0_voidEnableInterrupt(enum TIMER0_Interrupt);
void TIMER0_voidDisableInterrupt(enum TIMER0_Interrupt);
void TIMER0_voidSetCallBack(enum TIMER0_Interrupt, void(*callBack)(void));
u8 TIMER0_u8CheckFlag(enum TIMER0_Interrupt);
void TIMER0_voidClearFlag(enum TIMER0_Interrupt interrupt);
void TIMER0_voidSoftwarePWM(u8 port , u8 pin , u8 dutyCycle);

/* ADC Module */

typedef enum {
	ADC_MODE_SINGLE_CONVERSION,
	ADC_MODE_COUNTINOUS_CONVERSION
}ADC_Mode_t;

typedef enum {
	ADC_PRESCALAR_DIV_2 = 1,
	ADC_PRESCALAR_DIV_4,
	ADC_PRESCALAR_DIV_8,
	ADC_PRESCALAR_DIV_16,
	ADC_PRESCALAR_DIV_32,
	ADC_PRESCALAR_DIV_64,
	ADC_PRESCALAR_DIV_128
}ADC_Prescalar_t;

typedef enum {
	ADC_AUTO_TRIGGER_FREE_RUNNING,
	ADC_AUTO_TRIGGER_ANALOG_COMPARATOR,
	ADC_AUTO_TRIGGER_EXTI0,
	ADC_AUTO_TRIGGER_TIM0_COMPARE_MATCH,
	ADC_AUTO_TRIGGER_OVERFLOW,
	ADC_AUTO_TRIGGER_TIM1_COMPAE_MATCH_B,
	ADC_AUTO_TRIGGER_TIM1_OVERFLOW,
	ADC_AUTO_TRIGGER_TIM1_CAPTURE_EVENT
	
}ADC_AutoTrigger_t;

typedef enum {
	ADC_CHANNEL_SINGLE_0,
	ADC_CHANNEL_SINGLE_1,
	ADC_CHANNEL_SINGLE_2,
	ADC_CHANNEL_SINGLE_3,
	ADC_CHANNEL_SINGLE_4,
	ADC_CHANNEL_SINGLE_5,
	ADC_CHANNEL_SINGLE_6,
	ADC_CHANNEL_SINGLE_7,
	ADC_CHANNEL_DIFF_0_0_GAIN_10,
	ADC_CHANNEL_DIFF_1_0_GAIN_10,
	ADC_CHANNEL_DIFF_0_0_GAIN_200,
	ADC_CHANNEL_DIFF_1_0_GAIN_200,
	ADC_CHANNEL_DIFF_2_2_GAIN_10,
	ADC_CHANNEL_DIFF_3_2_GAIN_10,
	ADC_CHANNEL_DIFF_2_2_GAIN_200,
	ADC_CHANNEL_DIFF_3_2_GAIN_200,
	ADC_CHANNEL_DIFF_0_1_GAIN_1,
	ADC_CHANNEL_DIFF_1_1_GAIN_1,
	ADC_CHANNEL_DIFF_2_1_GAIN_1,
	ADC_CHANNEL_DIFF_3_1_GAIN_1,
	ADC_CHANNEL_DIFF_4_1_GAIN_1,
	ADC_CHANNEL_DIFF_5_1_GAIN_1,
	ADC_CHANNEL_DIFF_6_1_GAIN_1,
	ADC_CHANNEL_DIFF_7_1_GAIN_1,
	ADC_CHANNEL_DIFF_0_2_GAIN_1,
	ADC_CHANNEL_DIFF_1_2_GAIN_1,
	ADC_CHANNEL_DIFF_2_2_GAIN_1,
	ADC_CHANNEL_DIFF_3_2_GAIN_1,
	ADC_CHANNEL_DIFF_4_2_GAIN_1,
	ADC_CHANNEL_DIFF_5_2_GAIN_1,
	ADC_CHANNEL_SINGLE_1_22V,
	ADC_CHANNEL_SINGLE_GND,
}ADC_ChannelID_t;






/* APIs */
void ADC_voidInit(ADC_Mode_t mode,ADC_AutoTrigger_t triggerSource, ADC_Prescalar_t prescalar);
u16 ADC_u16ReadChannel();
void ADC_voidEnableInterruptWithCallback(ADC_ChannelID_t channel , void (*callback)(u16));
void ADC_voidStartConversion(ADC_ChannelID_t channel);
void ADC_voidStartContinousMode(void);
void ADC_voidStopContinousMode(void);


/* LCD Module */

void LCD_sendCommand(uint8_t command);
void LCD_displayCharacter(uint8_t data);
void LCD_displayString(const uint8_t *Str);
void LCD_init(void);
void LCD_clearScreen(void);
void LCD_displayStringRowColumn(uint8_t row,uint8_t col,const uint8_t *Str);
void LCD_goToRowColumn(uint8_t row,uint8_t col);
void LCD_integerToString(uint32_t data);



