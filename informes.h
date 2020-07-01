#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED
#include "LinkedList.h"

/** \brief Filtra los paises con menos de 5000 muertes
 * \param void* pais
 * \return 0 en caso de exito, 1 en caso de error
 */
int filtrarPaisesExitosos(void* pais);

/** \brief Filtra los paises que sus infectador triplican sus recuperados
 * \param void* pais
 * \return 0 en caso de exito, 1 en caso de error
 */
int filtrarPaisesMal(void* pais);

/** \brief Ordena segun la cantidad de infectados
 * \param void* aux1
 * \param void* aux2
 * \return 0 en caso de ser iguales, 1 si el aux1 es mayor, o -1 si el aux2 es mayor
 */
int sortPorInfectados(void* aux1, void* aux2);

/** \brief Informa el pais con mas muertes y su cantidad
 * \param LinkedList* lista
 * \return 0 en caso de exito, 1 en caso de error
 */
int paisMasCastigado(LinkedList* lista);

#endif // INFORMES_H_INCLUDED
