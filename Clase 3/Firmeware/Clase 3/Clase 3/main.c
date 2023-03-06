/*
 *Ejemplo 2  es  auto fantastico .c
 *
 * Created: 28/02/2023 10:07:01
 * Author : GFLO
 */ 
// C++ code este es el codigo  del auto fantastico con  funciones
//
#include <avr/io.h> //se incluyen las bibioletcas de E/S del AVR
#define F_CPU 16000000UL // velocidad fija (del dispositivo)
#include <util/delay.h> /* Funciones para retardos de tiempo */

//-- Constantes (aqui definimos costantes para minimizar codigo)
#define TIEMPO 500 //definimos la constante tiempo en 500 milisegundos

//--Etiquetas
#define LEDS_DDRX  DDRB  // Esta es la etiqueta del registro DDRB (esto se hace para poder cambar el registro rapido y no en todo el codigo)
#define LEDS_PORTX PORTB // Esta es la etiqueta del puerto B donde le indicamos HIGH 
#define LED_0      PORTB2 // Etiquetas de los LEDS segun su puerto de conexion  esto remplaza el numero binario 
#define LED_1      PORTB3
#define LED_2      PORTB4
#define LED_3      PORTB5

//--funciones

void ports_init (void)
{
	             //76543210
	LEDS_DDRX  =0b00111100; //declaro salidas de los pins 2 a 5 del registro D
	
}

int main (void)
{
	ports_init();  // se manda llamar la funcio de inicializacion de puertos
	while(1)
	{
		// 8421 8421
		//Ob0000_0000;
		LEDS_PORTX = (1<<LED_0);// prender el led 1 en binario 0b00000100 lo cambiamos con los operadores de desplazamiento (1<<2) y volvemos a cambiar ahora con etiquetas y nos queda (1<<LED_0)
		_delay_ms(TIEMPO);// es para el retardo  en milisegundos
		LEDS_PORTX = (1<<LED_1);// 
		_delay_ms(TIEMPO);//retardo  1 segundo
		LEDS_PORTX = (1<<LED_2);//  
		_delay_ms(TIEMPO);//retardo  1 segundo
		LEDS_PORTX = (1<<LED_3);// o 
		_delay_ms(TIEMPO);//retardo  1 segundo
		LEDS_PORTX = (1<<LED_2);//regreso del led 4
		_delay_ms(TIEMPO);//retardo  1 segundo
		LEDS_PORTX =(1<<LED_1);// regreso del led 3
		_delay_ms(TIEMPO);//retardo  1 segundo	
	}// fin while
}// fin main
