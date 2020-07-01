#ifndef PARSEO_H_INCLUDED
#define PARSEO_H_INCLUDED
#include "LinkedList.h"

/** \brief Parsea y carga los datos de un archivo csv
 * \param LinkedList* lista
 * \param char* path
 * \return 0 en caso de exito, 1 en caso de error
 */
int cargarCSV(LinkedList* lista, char* path);

#endif // PARSEO_H_INCLUDED
