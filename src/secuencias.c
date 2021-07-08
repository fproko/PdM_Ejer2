/*=============================================================================
 * Author: Fernando Prokopiuk <fernandoprokopiuk@gmail.com>
 * Author: Armando Suhuán <suhuan.aj@pucp.edu.pe>
 * Date: 2021/07/07
 * Version: v1.0
 *===========================================================================*/
#include "secuencias.h"
#include "led.h"
#include "teclas.h"
#include "sapi.h"
/*=============================================================================
 * Function: activarSecuencia 
 * Description: Enciende el Led correspondiente a la posición dentro de una secuencia determinada

Secuencia 1:					Secuencia 2:
	 ____ ____ ____ ____		 ____ ____ ____ ____
    |LEDB|LED1|LED2|LED3|		|LED3|LED2|LED1|LEDB|
i->   0     1    2    3	     i->  0     1    2    3		

 * Inpunt: 
	1) Puntero que apunta a la secuencia según la tecla presionada
	2) Posición del Led que corresponde encender dentro la secuencia que corresponda.
 * Output: No devuelve salida
 *===========================================================================*/



void activarSecuencia(gpioMap_t * psecuencia, int8_t * tiempoDestello, int8_t i){

    if (leerTecla(TEC1) == flagsControl[0])
    {
        psecuencia = secuencia1;
    }
    if (leerTecla(TEC4) == flagsControl[0])
    {
        psecuencia = secuencia2;
    }

    apagarLeds();
	encenderLed(*(psecuencia+i));
}