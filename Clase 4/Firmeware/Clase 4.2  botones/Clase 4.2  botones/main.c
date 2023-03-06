/*
 * Clase 4.2  botones.c
 *
 *                   
 *                                                                       * 
 *   Ejemplo 1 práctica N° 3 - Lab. Microcontroladores                   *
 *   Dispositivo: Arduino nano atmega328p                                      
 *   Lenguaje C                                                          *
 *   Rev: 1.0                                                            *
 *                                                                       *
 *                                                     Fecha: 02/03/23   *
 ************************************************************************/
// ------- Preamble -------- //
//-- Bibliotecas
#include <avr/io.h> //se incluyen las bibioletcas de E/S del AVR
#define F_CPU 16000000UL //1 Mhz velocidad del cristal interno
#include <util/delay.h> /* Funciones para retardos de tiempo */

//-----Etiquetas------------//
//---- Inputs
#define BTN_DDRX   DDRD
#define BTN_PORTX  PORTD
#define BTN_PINX   PIND
#define BTN_0      PORTD4
#define BTN_1      PORTD3

//----Outputs
#define LED_DDRX  DDRB
#define LED_PORTX PORTB
#define LED_PINX  PINB
#define LED_0     PORTB4
#define LED_1	  PORTB3

//--Funciones ()
//-- Prototipos de Funciones()
void ports_init(void);


// ------- MAIN -------- //
int main(void)
{
// ---- Inits-----//
	ports_init();//llama la funcion
	
//----- Event Loop----//
	while(1)
	{
		//0b00000001 = 0b00000001
		//0bXXXXXXXX & 0b00000001 = 0b0000000X
		//0bXXXXXXX0 & 0b00000001 = 0b00000000
		//0bXXXXXXX1 & 0b00000001 = 0b00000001
		if (BTN_PINX & 0b00010000)// 
		{
			LED_PORTX |= 0b00010000;// enciendo LED_0
		}
		else
		{
			LED_PORTX &= ~(1<<LED_0);//Apago LED_0
		}
		if(BTN_PINX & (1<<BTN_1))// si el boton es 1 entras a la aacion 
		{
			LED_PORTX |= (1<<LED_1);
		}
		else
		{
			LED_PORTX &= ~(1<<LED_1);
		}
	}// Fin del while
}// Fin del main



void ports_init(void)
{
//-- Definir entradas y salidas
//- Inputs (colocamos 0)
	BTN_DDRX &= ~(1<<BTN_0); // solo PORTD4  es una entrada el & ~(1<<PORTD4) = 0
	BTN_DDRX &= ~(1<<BTN_1); // solo PORTD3 es una entrada
	
// - Outputs (colocamos 1)
	LED_DDRX |= (1<<LED_0); // solo PORTB4 es una salida el | (1<<PORTB4) = 1
	LED_DDRX |= (1<<LED_1);// Solo PORTB3 es una salida
	
//-- Init Entrada y Salidas
//- Inputs
	BTN_PORTX &= ~(1<<BTN_0);// Pull- down 
	BTN_PORTX &= ~(1<<BTN_1);// Pull- down 
	
//-Outputs
	LED_PORTX &= ~(1<<LED_0);// Output low (sink)
	LED_PORTX &= ~(1<<LED_1);// Output low (sink)
}


