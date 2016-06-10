#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <ctype.h>
#include <string.h>
#include "Funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;

    while(seguir=='s')
    {

        system("cls");
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Generar pagina web\n");
        printf("4- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                system("cls");
                IngresoPelicula();
            break;

            case 2:
                system("cls");
                BajaDePelicula();
            break;

            case 3:
                system("cls");
                GenerarPagWeb();
                printf("Pagina Generada");
                system("pause");
            break;

            case 4:
                seguir = 'n';
            break;
        }
    }

    return 0;
}


;
