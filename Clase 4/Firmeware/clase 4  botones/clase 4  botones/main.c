//
/*************************************************************************
 *   CLASE  4                   *
 *                                                                       * 
 *   Ejemplo 1 práctica N° 3 - Lab. Microcontroladores                   *
 *   Dispositivo: Arduino nano atmega328p                                             *
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

//--Funciones ()
//-- Prototipos de Funciones()
void ports_init(void);


// ------- MAIN -------- //
int main(void)
{
// ---- Inits-----//
	ports_init();//llama la funcion
	
//----- Event Loop----//
	while(10)
	{
		//0b00000001 = 0b00000001
		PORTB = PIND;
	}
}



void ports_init(void)
{
//-- Definir entradas y salidas
//- Inputs (colocamos 0)
	DDRD = DDRD & ~(1<<PORTD4); // solo PORTD4  es una entrada el & ~(1<<PORTD4) = 0
	DDRD &= ~(1<<PORTD3); // solo PORTD3 es una entrada
	
// - Outputs (colocamos 1)
	DDRB = DDRB | (1<<PORTB4); // solo PORTB4 es una salida el | (1<<PORTB4) = 1
	DDRB |= (1<<PORTB3);// Solo PORTB3 es una salida
	
//-- Init Entrada y Salidas
//- Inputs
	PORTD &= ~(1<<PORTD4);// Pull- down 
	PORTD |= (1<<PORTD3); // Pull- up 
	
//-Outputs
	PORTB &= ~(1<<PORTB4);// Output low (sink)
	PORTB &= ~(1<<PORTB3);// Output low (sink)
}
