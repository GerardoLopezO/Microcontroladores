/*
* Ex Medio Curso
* Descripción : Control de motor 5 V
* Dispositivo : Arduino UNO ATMEGA328-P
* Nombres : 1143867
* No. Lista : 5
*/

//--Librerias
#include <avr/io.h> //se incluyen las bibioletcas de E/S del AVR
#define F_CPU 16000000UL //1 Mhz velocidad del cristal interno
#include <util/delay.h> /* Funciones para retardos de tiempo */

//--Definiciones
//-Inputs
#define BTN_DDRX   DDRC
#define BTN_PORTX  PORTC
#define BTN_PINX   PINC
#define BTN_0      PORTC0
#define BTN_1      PORTC1
#define BTN_2      PORTC2

//-- Macros
//-- Inputs
//BTN_0
#define BTN_0_PRESS (BTN_PINX & (1<<BTN_0))
//BTN_1
#define BTN_1_PRESS (BTN_PINX & (1<<BTN_1))
//BTN-2
#define BTN_2_PRESS (BTN_PINX & (1<<BTN_2))
#define TIEMPO 400

//-Outputs
#define DISPLAY PORTD
#define DISPLAY2 PORTB

#define SEGA    PORTD2
#define SEGA_ON  DISPLAY |=  _BV(SEGA);
#define SEGA_OFF DISPLAY &=~ _BV(SEGA);
#define SEGB    PORTD3
#define SEGB_ON  DISPLAY |=  _BV(SEGB);
#define SEGB_OFF DISPLAY &=~ _BV(SEGB);
#define SEGC    PORTD4
#define SEGC_ON  DISPLAY |=  _BV(SEGC);
#define SEGC_OFF DISPLAY &=~ _BV(SEGC);
#define SEGD    PORTD5
#define SEGD_ON  DISPLAY |=  _BV(SEGD);
#define SEGD_OFF DISPLAY &=~ _BV(SEGD);
#define SEGE    PORTD6
#define SEGE_ON  DISPLAY |=  _BV(SEGE);
#define SEGE_OFF DISPLAY &=~ _BV(SEGE);
#define SEGF    PORTD7
#define SEGF_ON  DISPLAY |=  _BV(SEGF);
#define SEGF_OFF DISPLAY &=~ _BV(SEGF);
#define SEGG    PORTB0
#define SEGG_ON  DISPLAY2 |=  _BV(SEGG);
#define SEGG_OFF DISPLAY2 &=~ _BV(SEGG);


#define LED1 PORTC3
#define LED1_ON PORTC |= _BV(LED1);
#define LED1_OFF PORTC &=~ _BV(LED1);

#define LED2 PORTC4
#define LED2_ON PORTC |= _BV(LED2);
#define LED2_OFF PORTC &=~ _BV(LED2);

#define LED3 PORTC5
#define LED3_ON PORTC |= _BV(LED3);
#define LED3_OFF PORTC &=~_BV(LED3);

#define LED4 PORTB1
#define LED4_ON PORTB |= _BV(LED4);
#define LED4_OFF PORTB &=~_BV(LED4);

//--Declaracion de funciones
void init_ports(void);
void show_number(uint8_t var);
void LED_prendidos();//
void contador_asc();// motor_CW
void contador_dsc();//motor_CCW
void LED_extremos();//LED EXTREMOS APAGADOS
void contador_num();//contador de numeros
void STOP();//motor_FastTOP()

//-----Main--------
int main(void)
{
	init_ports();

	while (1)
	{
		if (!BTN_0_PRESS&&!BTN_1_PRESS&&!BTN_2_PRESS) //000 - Ningun boton presionado
		{
			LED_prendidos();
			show_number(1);
		}
		else if(!BTN_0_PRESS&&!BTN_1_PRESS&&BTN_2_PRESS) //001 -
		{
			contador_asc();
			show_number(2);
		}
		else if (!BTN_0_PRESS&&BTN_1_PRESS&&!BTN_2_PRESS) //010
		{
			contador_dsc();
			show_number(3);
		}
		else if (!BTN_0_PRESS&&BTN_1_PRESS&&BTN_2_PRESS) //011 -
		{
			LED_extremos();
			contador_num();
		}
		else //1XX - stop
		{
			STOP();
		}
	}//Fin while
} //Fin main


//--Funciones -----------
void init_ports(void)
{
	
	//-- Definir entradas y salidas
	//- Inputs (colocamos 0)
	BTN_DDRX &= ~(1<<BTN_0); //
	BTN_DDRX &= ~(1<<BTN_1); //
	BTN_DDRX &= ~(1<<BTN_2);
	
	//-- Init Entrada y Salidas
	//- Inputs
	BTN_PORTX |=  (1<<BTN_0);//
	BTN_PORTX |=  (1<<BTN_1);// P
	BTN_PORTX |=  (1<<BTN_2);
	
	
	//--Outputs
	DDRD  |=  (_BV(SEGA) | _BV(SEGB));
	DDRD  |=  (_BV(SEGC) | _BV(SEGD));
	DDRD  |=  (_BV(SEGE) | _BV(SEGF));
	DDRB  |=  _BV(SEGG);
	
	//-Apagados
	PORTD  &= ~(_BV(SEGA) | _BV(SEGB) | _BV(SEGC) | _BV(SEGD));
	PORTD  &= ~(_BV(SEGE) | _BV(SEGF));
	PORTB  &= ~_BV(SEGG);
	
}

void LED_prendidos()
{
	LED1_ON;
	LED2_ON;
	LED3_ON;
	LED4_ON;
	
}
void contador_asc()//
{
	LED1_ON;
	_delay_ms(TIEMPO);
	LED2_ON;
	_delay_ms(TIEMPO);
	LED3_ON;
	_delay_ms(TIEMPO);
	LED4_ON;
	_delay_ms(TIEMPO);
	LED1_OFF;
	LED2_OFF;
	LED3_OFF;
	LED4_OFF;
	_delay_ms(TIEMPO);
}
void contador_dsc()//
{
	LED4_ON;
	_delay_ms(TIEMPO);
	LED3_ON;
	_delay_ms(TIEMPO);
	LED2_ON;
	_delay_ms(TIEMPO);
	LED1_ON;
	_delay_ms(TIEMPO);
	LED4_OFF;
	LED3_OFF;
	LED2_OFF;
	LED1_OFF;
	_delay_ms(TIEMPO);

}
void LED_extremos()//
{
	LED1_OFF;
	LED2_ON;
	LED3_ON;
	LED4_OFF;

}
void contador_num()//
{
	show_number(4);
	_delay_ms(TIEMPO);
	show_number(5);
	_delay_ms(TIEMPO);
	show_number(6);
	_delay_ms(TIEMPO);
	show_number(7);
	_delay_ms(TIEMPO);

}
void STOP()//
{
	LED1_OFF;
	LED2_OFF;
	LED3_OFF;
	LED4_OFF;
	SEGA_OFF;
	SEGB_OFF;
	SEGC_OFF;
	SEGD_OFF;
	SEGE_OFF;
	SEGF_OFF;
	SEGG_OFF;

}
void show_number(uint8_t var)
{
	switch (var)
	{
		case 1: //p
		SEGA_ON;
		SEGB_ON;
		SEGC_OFF;
		SEGD_OFF;
		SEGE_ON;
		SEGF_ON;
		SEGG_ON;
		break;
		case 2: // d
		SEGA_OFF;
		SEGB_ON;
		SEGC_ON;
		SEGD_ON;
		SEGE_ON;
		SEGF_OFF;
		SEGG_ON;
		break;
		case 3: //A
		SEGA_ON;
		SEGB_ON;
		SEGC_ON;
		SEGD_OFF;
		SEGE_ON;
		SEGF_ON;
		SEGG_ON;
		break;
		case 4: //0
		SEGA_ON;
		SEGB_ON;
		SEGC_ON;
		SEGD_ON;
		SEGE_ON;
		SEGF_ON;
		SEGG_OFF;
		break;
		case 5: //1
		SEGA_OFF;
		SEGB_ON;
		SEGC_ON;
		SEGD_OFF;
		SEGE_OFF;
		SEGF_OFF;
		SEGG_OFF;
		case 6: //2
		SEGA_ON;
		SEGB_ON;
		SEGC_OFF;
		SEGD_ON;
		SEGE_ON;
		SEGF_OFF;
		SEGG_ON;
		break;
		case 7: //3
		SEGA_ON;
		SEGB_ON;
		SEGC_ON;
		SEGD_ON;
		SEGE_OFF;
		SEGF_OFF;
		SEGG_ON;
		break;
	}
}

