/*
 * Actividad Fundamental 2
 *
 *                   
 *                                                                       * 
 *   Microcontroladores  
 *   Auto Increible 
 *   Dispositivo: Arduino nano atmega328p                                      
 *   Lenguaje C                                                          *
 *   Rev: 1.0 
 *   Gerardo Lopez Oseguera
 *   1143867                                                             *
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
#define TIEMPO 500

//----Outputs
#define LED_DDRX  DDRB
#define LED_PORTX PORTB
#define LED_PINX  PINB
#define LED_0      PORTB2 // Etiquetas de los LEDS segun su puerto de conexion  esto remplaza el numero binario 
#define LED_1      PORTB3
#define LED_2      PORTB4
#define LED_3      PORTB5

//-- Macros
//-- Inputs
//BTN_0
#define BTN_0_PRESS (BTN_PINX & (1<<BTN_0))
//btn_1
#define BTN_1_PRESS (BTN_PINX & (1<<BTN_1))

//--Output
//-LED O
#define LED_0_ON  LED_PORTX |=  (1<<LED_0)
#define LED_0_OFF LED_PORTX &= ~(1<<LED_0)
//-LED 1
#define LED_1_ON  LED_PORTX |=  (1<<LED_1)
#define LED_1_OFF LED_PORTX &= ~(1<<LED_1)
//-LED 2
#define LED_2_ON  LED_PORTX |=  (1<<LED_2)
#define LED_2_OFF LED_PORTX &= ~(1<<LED_2)
//-LED 3
#define LED_3_ON  LED_PORTX |=  (1<<LED_3)
#define LED_3_OFF LED_PORTX &= ~(1<<LED_3)

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
      //00
  	  if(!BTN_1_PRESS&&!BTN_0_PRESS)// 
      {
        	
                // 8421 8421
                //Ob0000_0000;
                LED_0_ON;// prender el led 
                _delay_ms(TIEMPO);//retardo  
                LED_0_OFF;//apagar el led
                LED_1_ON;// 
                _delay_ms(TIEMPO);// 
                LED_1_OFF;
                LED_2_ON;//  
                _delay_ms(TIEMPO);// 
                LED_2_OFF;
                LED_3_ON;// o 
                _delay_ms(TIEMPO);// 
                LED_3_OFF;
                LED_2_ON;//regreso del led 4
                _delay_ms(TIEMPO);//retardo  
                LED_2_OFF;
                LED_1_ON;// regreso del led 3
                _delay_ms(TIEMPO);//retardo  
                LED_1_OFF;
          	
       }
  	  //01
        else if (!BTN_1_PRESS&& BTN_0_PRESS)
        {
          LED_1_OFF;// apagados LED_0
          LED_0_OFF;
          LED_2_OFF;
          LED_3_OFF;
        }
       //10
          else if ( BTN_1_PRESS&&!BTN_0_PRESS)
          {
            LED_0_ON;// apagados LED
            LED_3_ON;
            LED_1_OFF;
            LED_2_OFF;
            _delay_ms(TIEMPO);//retardo 
            LED_0_OFF;// apagados LED
            LED_3_OFF;
            LED_1_ON;
            LED_2_ON;
            _delay_ms(TIEMPO);//retardo 
          }
       //11
            else 
            {
              LED_1_ON;// enciendo LED_0
          	  LED_0_ON;
              LED_2_ON;
              LED_3_ON;
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
