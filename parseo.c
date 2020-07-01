#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parseo.h"
#include "pandemia.h"

int cargarCSV(LinkedList* lista, char* path)
{
    int retorno = 1;
    char buffer[5][30];
    int cant;
    ePais* aux;

    FILE* f;
    f = fopen(path, "r");

    if(f != NULL)
    {
        fscanf(f, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n",buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]);
        while(!feof(f))
        {
            cant = fscanf(f, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n",buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]);

            if (cant == 5)
            {
                aux = pais_newParamS(buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]);
                if(aux != NULL)
                {
                    ll_add(lista, aux);
                    retorno = 0;
                }
            }
            else
            {
                break;
            }
        }
    }
    fclose(f);
    return retorno;
}
