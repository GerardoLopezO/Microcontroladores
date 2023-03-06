/*
 * clase 3.1 while.c
 *
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
#define TIEMPO 100 //definimos la constante tiempo en 500 milisegundos

//--Etiquetas
#define LEDS_DDRX  DDRB  // Esta es la etiqueta del registro DDRB (esto se hace para poder cambar el registro rapido y no en todo el codigo)
#define LEDS_PORTX PORTB // Esta es la etiqueta del puerto B donde le indicamos HIGH 
#define LED_0      PORTB2 // Etiquetas de los LEDS segun su puerto de conexion  esto remplaza el numero binario 
#define LED_1      PORTB3
#define LED_2      PORTB4
#define LED_3      PORTB5

//--Mascaras de bits (estos se usan cuadno en un registro solo quieres usar los bits que vas usar y los otros no moverlos = 0b00111100; aqui solo quieres usar los bits 5 al 2 y el resto no poner ni 0s ni 1 
// Ejemplo  compuerta logica and  & (las funciones pueden ser: F = x*1 la salida seria F= x, en el segundo caso F = x * 0 la salida seria F =0) donde la primera guarda y la segunda es un set o inicio
// Ejemplo compuerta logica or| (las funciones pueden ser: F = x + 1 la salida seria F = 1, en el segundo caso F = x + 0 la salida seria F= x) donde la primera limpra o clear y la segunda guarda 
//  Ejemplo practico tenemos un bit 8  Obxxxxxxxx en un registro
//         en una compuerta and          00001111   que da como resultado con los ceros borras y  con los unos guardas 



//--funciones

void ports_init (void)
{
	            //76543210
	LEDS_DDRX  =0b00111100; //declaro salidas de los pins 2 a 5 del registro D
	      //    0bxxxxx1xx | 0b00000100  es es lo que le pedimos que cambie (or)
	LEDS_DDRX = LEDS_DDRX | 0b00000100;
	    //      0bxxxxx1xx | 0b00000100 es el resultado  en este caso no afecta  ya el unico bit  no se modifico
	LEDS_DDRX = LEDS_DDRX | (1<< LED_1);// Esto para hacer mas corto el codigo en lugar de binario
	LEDS_DDRX |= (1<< LED_2); // para hacerlo mas corto que el anterio podemos usar esto (aqui cambiamos de led)
	LEDS_DDRX |= (1<< LED_3);
}

int main (void)
{
	ports_init();  // se manda llamar la funcio de inicializacion de puertos
	uint8_t i=2; // hacemos una variable de tipo entero y la inicializamoos en 2
	while(1)
	{
		i=2;
		while(i<=5) // que el bucle se repita  hasta que la variable se menor o igual a 5 
		{
			LEDS_PORTX |= (1<<i);// la etiqueta del puerto se indica que esta high 1 lugar
			_delay_ms(TIEMPO);// es para el retardo  en milisegundos
			i++; // incrementamos una i por cada iteracion del while 
		}
		while(i>=2) // Este es el bucle de regreso
		{
			LEDS_PORTX &= ~(1<<i);// la etiqueta del puerto se indica que esta high 1 lugar
			_delay_ms(TIEMPO);// es para el retardo  en milisegundos
			i--; // disminuyendo  una i por cada iteracion del while
		}
	}// fin while
}// fin main


