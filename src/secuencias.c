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

void activarSecuencia(gpioMap_t *psecuencia, uint16_t *tiempoDestello)
{
    static int8_t i = 0;
    static bool blinkLed = 1;
    static uint8_t estadoSemaforo = 0; // Estados-> 0=NORMAL  1=DESCONECTADO  2=ALARMA
    static delay_t delay;

    if (leerTecla(TEC2) == 0)
    {
        estadoSemaforo++;
    }
    if (estadoSemaforo > 2)
    {
        estadoSemaforo = 0;
    }
    if (estadoSemaforo == 0)
    {
        apagarLeds();
        delayWrite(&delay, *(tiempoDestello + i));
        encenderLed(*(psecuencia + i));

        if (delayRead(&delay))
        {
            i++;
        }
        if (i > 2)
        {
            i = 0;
        }
    }

    if (estadoSemaforo == 1)
    {
        apagarLeds();
        gpioWrite(LEDG, ON);
        i = 0;
    }

    if (estadoSemaforo == 2)
    {
        apagarLeds();
        gpioWrite(LEDB, ON);
        i = 0;
    }
}
