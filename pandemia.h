#ifndef PANDEMIA_H_INCLUDED
#define PANDEMIA_H_INCLUDED
#include "LinkedList.h"

typedef struct
{
    int id;
    char nombre[25];
    int recuperados;
    int infectados;
    int muertos;
}ePais;


/** \brief Imprime la lista de paises
 * \param LinkedList* lista
 * \return 0 en caso de exito, 1 en caso de error
 */
int mostrarPaises(LinkedList* lista);

/** \brief Imprime un pais recibiendo su puntero como param
 * \param eArticulo* pArticulo
 * \return 0 en caso de exito, 1 en caso de error
 */
int mostrarPais(ePais* pPais);

/** \brief Crea un nuevo pais recibiendo informacion como parametros
 * \param char* id
 * \param char* nombre
 * \param char* recuperados
 * \param char* infectados
 * \param char* muertos
 * \return puntero al nuevo pais
 */
ePais* pais_newParamS(char* id, char* nombre, char* recuperados, char* infectados, char* muertos);

/** \brief Guarda los datos en un archivo csv en forma de texto
 * \param LinkedList* lista
 * \param char* path
 * \return 0 en caso de exito, 1 en caso de error
 */
int guardarCSV(LinkedList* lista, char* path);

//Setters y getters obtienen y asignan un valor validado
int pais_setId(ePais* this, int id);
int pais_getId(ePais* this, int* id);
int pais_setNombre(ePais* this,char* nombre);
int pais_getNombre(ePais* this,char* nombre);
int pais_setRecuperados(ePais* this, int recuperados);
int pais_getRecuperados(ePais* this, int* recuperados);
int pais_setInfectados(ePais* this, int infectados);
int pais_getInfectados(ePais* this, int* infectados);
int pais_setMuertos(ePais* this, int muertos);
int pais_getMuertos(ePais* this, int* muertos);

/** \brief Asigna numeros a los elementos
 * \param void* pais
 * \return void
 */
void* map_estadisticas(void* pais);

#endif // PANDEMIA_H_INCLUDED
