#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "LinkedList.h"
#include "validaciones.h"
#include "pandemia.h"
#include "informes.h"
#include "parseo.h"

int menu();

int main()
{
    srand(time(NULL));
    int seguir = 0;
    char path[25];
    char csv[15];

    strcpy(csv, ".csv");

    LinkedList* listaPandemia = ll_newLinkedList();
    LinkedList* listaAux = ll_newLinkedList();

    do
    {
        switch(menu())
        {
        case 1:
            utn_getCadena(path, 25, 2, "Ingrese nombre del archivo (sin el .csv): ", "\nError ");
            strcat(path, csv);

            if(!cargarCSV(listaPandemia, path))
            {
                printf("\nArchivos cargados con exito en '%s'.\n", path);
            }
            else
            {
               printf("\nError.\n");
            }
            break;
        case 2:
            if(!ll_isEmpty(listaPandemia))
            {
                mostrarPaises(listaPandemia);
            }
            else
            {
               printf("\nDebe cargar el archivo primero.\n");
            }
            break;
        case 3:
            if(!ll_isEmpty(listaPandemia))
            {
                listaPandemia = ll_map(listaPandemia, map_estadisticas);

                if(listaPandemia != NULL)
                {
                    printf("Lista cargada con estadisticas exitosamente.\n");
                }
                else
                {
                    printf("Error.\n");
                }
            }
            else
            {
               printf("\nDebe cargar el archivo primero.\n");
            }
            break;
        case 4:
            if(!ll_isEmpty(listaPandemia))
            {
                listaAux = ll_filter(listaPandemia, filtrarPaisesExitosos);

                if(listaAux != NULL)
                {
                    guardarCSV(listaAux, "paisesExitosos.csv");
                    printf("\nLista creada con exito en archivo 'paisesExitosos'.\n\n");
                }
                else
                {
                    printf("\nError.\n");
                }
            }
            else
            {
                printf("\nNo hay datos cargados.\n");
            }
            break;
        case 5:
            if(!ll_isEmpty(listaPandemia))
            {
                listaAux = ll_filter(listaPandemia, filtrarPaisesMal);

                if(listaAux != NULL)
                {
                    guardarCSV(listaAux, "paisesMal.csv");
                    printf("\nLista creada con exito en archivo 'paisesMal'.\n\n");
                }
                else
                {
                    printf("\nError.\n");
                }
            }
            else
            {
                printf("\nNo hay datos cargados.\n");
            }
            break;
        case 6:
            if(!ll_isEmpty(listaPandemia))
            {
                if(!ll_sort(listaPandemia, sortPorInfectados, 0))
                {
                    mostrarPaises(listaPandemia);
                }
                else
                {
                    printf("\nError.\n");
                }
            }
            else
            {
                printf("\nNo hay datos cargados.\n");
            }
            break;
        case 7:
            if(!ll_isEmpty(listaPandemia))
            {
                paisMasCastigado(listaPandemia);
            }
            else
            {
                printf("\nNo hay datos cargados.\n");
            }
            break;
        case 8:
            seguir = 1;
            break;
        }
        system("pause");
    }while(seguir ==0);
}

int menu()
{
    int opcion;

    system("cls");
    printf("----Menu----\n");
    printf("1. Cargar archivo.\n");
    printf("2. Imprimir lista.\n");
    printf("3. Asignar estadisticas.\n");
    printf("4. Filtrar paises exitosos.\n");
    printf("5. Filtrar paises en el horno.\n");
    printf("6. Ordenar por nivel de infeccion.\n");
    printf("7. Informar pais mas con mas muertes.\n");
    printf("8. Salir.\n");

    utn_getEntero(&opcion, 2, "Ingrese opcion: ", "\nError ", 1, 8);

    return opcion;
}
