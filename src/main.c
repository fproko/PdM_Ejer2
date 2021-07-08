/*=============================================================================
 * Author: Fernando Prokopiuk <fernandoprokopiuk@gmail.com>
 * Date: 2021/07/07
 *===========================================================================*/

/*=====[Inclusions of function dependencies]=================================*/

#include "../inc/main.h"
#include "sapi.h"
#include "secuencias.h"
//#include "led.h"
//#include "teclas.h"


/*=====[Definition macros of private constants]==============================*/

/*=====[Definitions of extern global variables]==============================*/

/*=====[Definitions of public global variables]==============================*/

/*=====[Definitions of private global variables]=============================*/

/*=====[Main function, program entry point after power on or reset]==========*/

int main( void )
{
   // ----- Setup -----------------------------------
   boardInit();

	int8_t i = 0; 
	delay_t delay;
	delayInit(&delay, 800); //Argumentos: *dirección a mi variable delay_t y valor 800.
	static gpioMap_t secuencia1[] = {LED1, LED_OFF, LED2, LED3};
	uint8_t tiempoSecuencia1[] = {1000, 500, 2000, 3000};  //tiempos en ms para LED1, LED2 y LED3, respectivamente
	//static gpioMap_t secuencia2[] = {LED3, LED2, LED1, LEDB};
	static bool_t  flagsControl[] = {FALSE, FALSE, FALSE, FALSE};
	/*
	flagsControl[0]-> Tecla leída
	flagsControl[1]-> Led encendido
	flagsControl[2]-> Leds apagados
	*/
	gpioMap_t * psecuencia = secuencia1;
	const uint8_t ultimoLed = sizeof(secuencia1)/sizeof(gpioMap_t);

   // ----- Repeat for ever -------------------------
   while (true)
	{
		activarSecuencia(psecuencia,i);

      if (delayRead(&delay))
      {
         i++;
      }
      if (i > ultimoLed - 1)
      {
         i = 0;
      }
   }
   // YOU NEVER REACH HERE, because this program runs directly or on a
   // microcontroller and is not called by any Operating System, as in the 
   // case of a PC program.
   return 0;
}
