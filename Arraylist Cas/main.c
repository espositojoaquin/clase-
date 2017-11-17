#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    int Arch;
    ArrayList* lista;
    EClub* aux;
    lista = al_newArrayList();
    int i;
    cargarBinario(aux,lista);
    FILE* archivo;

    while(seguir=='s')
    {
        printf("1- Agregar Equipo\n");
        printf("2- Listar clubes\n");
        printf("3- Descender club\n");
        printf("4- Modificar datos del club\n");
        printf("5- Eliminar todos los equipos\n");
        printf("6- Ingresar un equipo en la posicion especificada\n");
        printf("7- Ordenar por posicion\n");
        printf("8  Cargar Equipos\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            agregarClub(lista,aux);

            break;
        case 2:

            if(lista->isEmpty(lista))
            {
                printf("No se han cargado equipos\n");
            }
            else
            {
                mostrarClub(lista,aux);
            }

            break;
        case 3:
            EliminarClub(lista,aux);

            break;
        case 4:
            ModifocarClub(lista,aux);

            break;
        case 5:
            lista->clear(lista);
            if(lista->clear(lista)==0)
            {
                printf("Todos los equipos fueron eliminados");
            }
            break;
        case 6:
            PosicionEspecificada(lista,aux);

            break;
        case 7:
            lista->sort(lista,comparaPersonas,1);
            mostrarClub(lista,aux);
            break;
        case 8: Arch=LeerEquipos(archivo,lista);
                if(Arch==0)
                {
                    printf("\n Error al abrir el archivo\n");
                }
                else
                {
                    printf("\n Archivo cargado con exito\n");

                }

            break;
        case 9:
            seguir = 'n';
            break;
        default:
            printf("Ingreso una opcion incorrecta! \n");
            break;
        }
    }



    return 0;
}
