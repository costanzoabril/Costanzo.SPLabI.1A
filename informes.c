#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pandemia.h"

int filtrarPaisesExitosos(void* pais)
{
    ePais* x;
    int retorno = 0;
    int auxMuertes;

    if(pais != NULL)
    {
        x = (ePais*) pais;
        pais_getMuertos(x, &auxMuertes);

        if(auxMuertes < 5000)
        {
            retorno = 1;
        }
    }
    return retorno;
}

int filtrarPaisesMal(void* pais)
{
    ePais* x;
    int retorno = 0;
    int auxInfectados;
    int auxRecuperados;

    if(pais != NULL)
    {
        x = (ePais*) pais;
        pais_getInfectados(x, &auxInfectados);
        pais_getRecuperados(x, &auxRecuperados);

        auxRecuperados = auxRecuperados *3;

        if(auxInfectados > auxRecuperados)
        {
            retorno = 1;
        }
    }
    return retorno;
}

int sortPorInfectados(void* aux1, void* aux2)
{
	int retorno = 0;
	int infectados1;
	int infectados2;

	pais_getInfectados(aux1, &infectados1);
	pais_getInfectados(aux2, &infectados2);

	if(infectados1 > infectados2)
	{
		retorno = 1;
	}
	else if(infectados1 < infectados2)
	{
		retorno = -1;
	}
	return retorno;
}

int paisMasCastigado(LinkedList* lista)
{
    int flag = 0;
    int retorno = 1;
    ePais* pPais = NULL;
    int mayorCantidad;
    int muertos;
    char pais[51];

    if(lista != NULL)
    {
        for(int i=0; i<ll_len(lista); i++)
        {
            pPais = (ePais*) ll_get(lista, i);
            pais_getMuertos(pPais, &muertos);
            if(flag == 0 || muertos > mayorCantidad)
            {
                mayorCantidad = muertos;
                pais_getNombre(pPais, pais);
                flag = 1;
                retorno = 0;
            }
        }

        printf("El pais con mas muertes es %s con %d muertes\n", pais, mayorCantidad);
    }
    return retorno;
}

