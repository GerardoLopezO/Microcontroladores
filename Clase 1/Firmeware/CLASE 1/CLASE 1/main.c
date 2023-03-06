/*
 * CLASE 1.c
 *
 * Created: 24/02/2023 14:16:34
 * Author : Axi
 */ 

#include <avr/io.h>


int main(void)// esto es igual setup en IDE de arduino
{           //76543210
	DDRB  = 0b00101000;// Aqui le decimos que el registro b en el pin 3 es salida en binario
	PORTB = 0x08;// Aqui le decimos que el puerto b en pin4 tiene 5v o esta high en hexagesimal
	       //76543210
	DDRC = 0b00000010; //Aqui le decimos que el registro c en el pin 1 es salida en binario
	PORTC = 0x00; // Aqui le decimo que el puerto c en pin3 tiene 5v o esta high en hexagesimal
    /* Replace with your application code */
    while (1) // esto es el loop en el IDE de arduino
    {
    }// fin while
}//fin main

