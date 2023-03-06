/*
 *Ejemplo 2  es  auto fantastico .c
 *
 * Created: 28/02/2023 10:07:01
 * Author : GFLO
 */ 
// C++ code este es el codigo  del auto fantastico con  funciones
//
#include <avr/io.h> //se incluyen las bibioletcas de E/S del AVR
#include <util/delay.h> /* Funciones para retardos de tiempo */

//-- Constantes (aqui definimos costantes para minimizar codigo)
#define TIEMPO 1000 //definimos la constante tiempo en 500 milisegundos

//--funciones

int ports_init (void)
{
	//76543210
	DDRD  =0b00111100; //declaro salidas de los pins 2 a 5 del registro D
	DDRB  =0b00000001; // declaro salida al pin 0 del registro B
	
}

int main (void)
{
	ports_init();  // se manda llamar la funcio de inicializacion de puertos
	while(1)
	{
		// 8421 8421
		//Ob0000_0000;
		PORTD = (1<<2);// prender el led 1 en binario 0b00000100 lo cambiamos con los operadores de desplazamiento 
		PORTB =0x00; // decirle que mientras d esta prendido b esta apagado
		_delay_ms(TIEMPO);// es para el retardo  en milisegundos
		PORTD = (1<<3);// prender el led 1 en binario 0b00001000 lo cambiamos con los operadores de desplazamiento 
		PORTB =0x00; // decirle que mientras d esta prendido b esta apagado
		_delay_ms(TIEMPO);//retardo  1 segundo
		PORTD = (1<<4);// prender el led 1 en binario 0b00010000 lo cambiamos con los operadores de desplazamiento 
		PORTB =0x00; // decirle que mientras d esta prendido b esta apagado
		_delay_ms(TIEMPO);//retardo  1 segundo
		PORTD = (1<<5);// prender el led 1 en binario 0b00100000 lo cambiamos con los operadores de desplazamiento 
		PORTB =0x00; // decirle que mientras d esta prendido b esta apagado
		_delay_ms(TIEMPO);//retardo  1 segundo
		PORTD =0X00;//apagar el puerto d cuando se prenda puer b
		PORTB =0x01;// prender  el led 5
		_delay_ms(TIEMPO);//retardo  1 segundo
		PORTD =0b00100000;// regreso del led 4
		PORTB =0x00; // decirle que mientras d esta prendido b esta apagado
		_delay_ms(TIEMPO);//retardo  1 segundo
		PORTD =0b00010000;// regreso del led 3
		PORTB =0x00;
		_delay_ms(TIEMPO);//retardo  1 segundo
		PORTD =0b00001000;// regresol del led 2
		PORTB =0x00; // decirle que mientras d esta prendido b esta apagado
		_delay_ms(TIEMPO);//retardo  1 segundo	
	}// fin while
}// fin main
