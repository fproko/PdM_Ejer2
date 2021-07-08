/*=============================================================================
 * Author: Fernando Prokopiuk <fernandoprokopiuk@gmail.com>
 * Author: Armando Suhuán <suhuan.aj@pucp.edu.pe>
 * Date: 2021/07/07
 * Version: v1.0
 *===========================================================================*/
#include "teclas.h"
#include "sapi.h"
/*=============================================================================
 * Function: leerTecla 
 * Description: La función lee el estado de la entrada del uC luego de apretar una tecla
 * Inpunt: 
	1) Tecla a leer -> TEC1, TEC2, TEC3 o TEC4
 * Output: Valor booleano estado_tecla
	"0" -> Tecla apretada (ON)
	"1" -> Tecla sin apretar (OFF)
 *===========================================================================*/
bool_t leerTecla(gpioMap_t tecla)
{
	bool_t estado_tecla;
	estado_tecla = gpioRead(tecla);
	return estado_tecla;
}
