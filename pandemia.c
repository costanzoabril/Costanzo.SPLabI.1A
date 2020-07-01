#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pandemia.h"


int mostrarPaises(LinkedList* lista)
{
    int retorno = 1;
	int tam;
	ePais* pPais;

	if(lista != NULL)
	{
	    tam = ll_len(lista);

		printf("\n  ID         Nombre          Recuperados  Infectados   Muertos\n\n");

		for(int i =0; i<tam; i++)
		{
		    pPais = (ePais*)ll_get(lista,i);
			if(pPais != NULL)
			{
				mostrarPais(pPais);
				retorno = 0;
			}
		}
        printf("\n\n");
	}
	return retorno;
}

int mostrarPais(ePais* pPais)
{
    int retorno = 1;
    int auxId;
    char auxNombre[20];
    int auxRecuperados;
    int auxInfectados;
    int auxMuertos;

    if(!pais_getId(pPais, &auxId)
    && !pais_getNombre(pPais, auxNombre)
    && !pais_getRecuperados(pPais, &auxRecuperados)
    && !pais_getInfectados(pPais, &auxInfectados)
    && !pais_getMuertos(pPais, &auxMuertos))
    {

        printf("%3d   %20s   %8d    %8d    %8d  \n", auxId, auxNombre, auxRecuperados, auxInfectados, auxMuertos);
        retorno = 0;
    }
    else
    {
        printf("\nError");
    }
    return retorno;
}

ePais* pais_newParamS(char* id, char* nombre, char* recuperados, char* infectados, char* muertos)
{
    ePais* nuevo = (ePais*) malloc(sizeof(ePais));

	if(nuevo != NULL)
	{
		if(    pais_setId(nuevo, atoi(id))
            || pais_setNombre(nuevo, nombre)
            || pais_setRecuperados(nuevo, atoi(recuperados))
            || pais_setInfectados(nuevo, atoi(infectados))
            || pais_setMuertos(nuevo, atoi(muertos)))
		{
			free(nuevo);
			nuevo = NULL;
		}
	}
	return nuevo;
}

int guardarCSV(LinkedList* lista, char* path)
{
    int retorno = 1;
	FILE* pFile;
	ePais* pPais;
	int auxId;
	char auxNombre[15];
	int auxInfectados;
	int auxRecuperados;
	int auxMuertos;

	pFile = fopen(path, "w");

	if(pFile != NULL)
	{
	    retorno = 0;
		fprintf(pFile, "id,nombre,recuperados,infectados,muertos\n");

        for(int i = 1; i < ll_len(lista); i++)
        {
            pPais = ll_get(lista, i);

            if(   !pais_getId(pPais, &auxId)
               && !pais_getNombre(pPais, auxNombre)
               && !pais_getRecuperados(pPais, &auxRecuperados)
               && !pais_getInfectados(pPais, &auxInfectados)
               && !pais_getMuertos(pPais, &auxMuertos))
               {
                   fprintf(pFile, "%d,%s,%d,%d,%d\n", auxId, auxNombre, auxRecuperados, auxInfectados, auxMuertos);
               }
        }
        fclose(pFile);
	}
	return retorno;
}

int pais_setId(ePais* this, int id)
{
    int retorno = 1;

	if(this != NULL && id >=0)
	{
		this->id = id;
		retorno = 0;
	}
	return retorno;
}

int pais_getId(ePais* this, int* id)
{
   int retorno = 1;

	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 0;
	}
	return retorno;
}

int pais_setNombre(ePais* this,char* nombre)
{
    int retorno = 1;

	if(this != NULL && nombre != NULL)
	{
		strcpy(this->nombre, nombre);
		retorno = 0;
    }
	return retorno;
}

int pais_getNombre(ePais* this,char* nombre)
{
    int retorno = 1;

	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre, this->nombre);
		retorno = 0;
	}
	return retorno;
}

int pais_setRecuperados(ePais* this, int recuperados)
{
    int retorno = 1;

	if(this != NULL && recuperados >=0)
	{
		this->recuperados = recuperados;
		retorno = 0;
	}
	return retorno;
}

int pais_getRecuperados(ePais* this, int* recuperados)
{
   int retorno = 1;

	if(this != NULL && recuperados != NULL)
	{
		*recuperados = this->recuperados;
		retorno = 0;
	}
	return retorno;
}

int pais_setInfectados(ePais* this, int infectados)
{
    int retorno = 1;

	if(this != NULL && infectados >=0)
	{
		this->infectados = infectados;
		retorno = 0;
	}
	return retorno;
}

int pais_getInfectados(ePais* this, int* infectados)
{
   int retorno = 1;

	if(this != NULL && infectados != NULL)
	{
		*infectados = this->infectados;
		retorno = 0;
	}
	return retorno;
}

int pais_setMuertos(ePais* this, int muertos)
{
    int retorno = 1;

	if(this != NULL && muertos >=0)
	{
		this->muertos = muertos;
		retorno = 0;
	}
	return retorno;
}

int pais_getMuertos(ePais* this, int* muertos)
{
   int retorno = 1;

	if(this != NULL && muertos != NULL)
	{
		*muertos = this->muertos;
		retorno = 0;
	}
	return retorno;
}

void* map_estadisticas(void* pais)
{
    void* retorno;
    ePais* x;
    int auxRecuperados;
    int auxInfectados;
    int auxMuertos;

    if(pais != NULL)
    {
        x = (ePais*) pais;

        if(!pais_getRecuperados(x, &auxRecuperados)
        && !pais_getInfectados(x, &auxInfectados)
        && !pais_getMuertos(x, &auxMuertos))
        {
            auxRecuperados = rand()%(50001 + 949998);
            auxInfectados = rand()%(40001 + 1959999);
            auxMuertos = rand()%(1001 + 49000);

            pais_setRecuperados(x, auxRecuperados);
            pais_setInfectados(x, auxInfectados);
            pais_setMuertos(x, auxMuertos);
        }
        else
        {
            printf("Error.");
        }
        retorno = x;
    }
    return retorno;
}


