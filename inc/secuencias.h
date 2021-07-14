/*=============================================================================
 * Copyright (c) 2021, Armando_Suhuan <suhuan.aj@pucp.edu.pe>
 * All rights reserved.
 * License: bsd-3-clause (see LICENSE.txt)
 * Date: 2021/07/09
 * Version: 1
 *===========================================================================*/
#include "sapi.h"

/*=============================================================================
 * Function: activarSecuencia
 * Description: Enciende el Led correspondiente a la posici�n dentro de una secuencia determinada
Secuencia 1:					Secuencia 2:
	 ____ ____ ____ ____		 ____ ____ ____ ____
    |LEDB|LED1|LED2|LED3|		|LED3|LED2|LED1|LEDB|
i->   0     1    2    3	     i->  0     1    2    3
 * Inpunt:
	1) Puntero que apunta a la secuencia seg�n la tecla presionada
	2) Posici�n del Led que corresponde encender dentro la secuencia que corresponda.
 * Output: No devuelve salida
 *===========================================================================*/
void activarSecuencia(gpioMap_t *psecuencia, uint16_t *tiempoDestello);
