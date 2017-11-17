
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Funciones.h"

EClub* newClub()
{
    EClub* aux;
    aux = (EClub*) malloc (sizeof(EClub));
    return aux;
}
EClub* newClubParametros( char nombre[],int posicion,int seguidores,char apodo[])
{
    EClub* Club;
    ArrayList* lista;

    Club = newClub();
    if(Club!=NULL)
    {
        strcpy(Club->nombre,nombre);
        Club->posicion=posicion;
        Club->seguidores=seguidores;
        strcpy(Club->apodo,apodo);


    }

    return Club;
}
int cargarBinario( EClub* Club,ArrayList* lista)
{
    int retorno=-1;
    FILE* bin;
    bin=fopen("Club.dat","rb");
    /* if(bin==NULL)
     {
         bin=fopen("Club.dat","wb");
         if(bin==NULL)
         {
             printf("No se pudo abrir el archivo");
             system("pause");
             return retorno;
         }
     }*/
    fread(Club,sizeof(EClub),al_len(lista),bin);
    retorno=0;
    fclose(bin);
    return retorno;
}
void generarBinario(ArrayList* lista,  EClub* aux)
{
    int i;
    FILE* bin;
    bin = fopen("Club.dat","wb");

    if(bin != NULL)
    {
        for(i=0; i<al_len(lista); i++)
        {
            aux = newClub();
            aux = al_get(lista,i);
            fwrite(aux, sizeof(EClub),al_len(lista),bin);
        }
        printf("Archivo generado correctamente!\n");
    }
    else
    {
        printf("Ha ocurrido un error!\n");
    }
    fclose(bin);

}
/*void guardarBinario(EClub* club,ArrayList* lista)
{
    FILE* pClub;
    int i;
    pClub=fopen("bin.dat","wb");
    if(pClub==NULL)
    {
        printf("Error al abrir el archivo binario\n");
        exit(1);
    }
    for(i=0;i<al_len(lista);i++)
    {    club=newClub();
        fwrite(club,sizeof(EClub*),al_len(lista),pClub);
    }

    printf("\nArchivo binario guardado con exito!\n");
    fclose(pClub);
}*/

void agregarClub(ArrayList* lista,EClub* club)
{
    char nombre[50],apodo[50];
    int posicion,seguidores;
    int i,j;
    EClub* equipo;


    printf("\nPor favor ingrese el nombre del Club\n ");
    fflush(stdin);
    gets(nombre);

    printf("\nPor favor ingrese el apodo del Club\n ");
    fflush(stdin);
    gets(apodo);

    printf("\Por favor ingrese la cantidad de seguidores\n");
    scanf("%d",&seguidores);

    printf("\Por favor ingrese la posicion de su equipo \n");
    scanf("%d",&equipo->posicion);

     posicion=equipo->posicion;
    /* for(j=0; j<tam; j++)
             {
                 if((movie+j)->estado!=-1)
                 {

                     while((movie+i)->id==(movie+j)->id)
                     {
                         printf("\nEste Codigo ya fue registrado Por favor ingrese otro: ");
                         scanf("%d",&(movie+i)->id);
                         system("pause");
                         system("cls");
                     }

                 }


             }*/
    for(i=0; i<lista->len(lista); i++)
    {
        club=(EClub*)lista->get(lista,i);
        for(j=0; j<lista->len(lista); j++)
        {
            equipo=(EClub*)lista->get(lista,j);
            while(equipo->posicion==club->posicion||posicion<1||posicion>22)
            {

                printf("\n Por favor ingrese una posicion diferente\n");
                scanf("%d",&equipo->posicion);



            }
        }



        //posicion=club->posicion;

    }
    // VerificacionPos(lista,club,posicion);
    club=newClubParametros(nombre,posicion,seguidores,apodo);

    if(club!=NULL)
    {
        lista->add(lista,club);
        generarBinario(lista,club);

    }


}
void mostrarClub(ArrayList* lista,EClub* club)
{
    int i;
    printf("Tabla de posiciones \n");
    printf("Equipos\t\t Apodo\t Posicion\t\tSeguidores\n");
    for(i=0; i<lista->len(lista); i++)
    {
        club=(EClub*)lista->get(lista,i);
        if(club!=NULL)
        {
            printf("\n %s\t\t %20s\t %d\t\%d\n",club->nombre,club->apodo,club->posicion,club->seguidores);
        }
        else
        {
            printf("\nNo hay equipos ingresados");
        }
    }
}
void EliminarClub(ArrayList* lista, EClub* club)
{
    club=newClub();

    char respuesta;
    int i,posicion;
    int auxI=-1;

    printf("\nIngrese la posicion del equipo que desea eliminar\n");
    scanf("%d",&posicion);

    for(i=0; i<lista->len(lista); i++)
    {
        club=(EClub*)lista->get(lista,i);
        if(club->posicion==posicion)
        {
            auxI=i;
            break;
        }
    }
    if(auxI==-1)
    {
        printf("\nClub inexistente\n");
    }
    else
    {
        club=(EClub*)lista->get(lista,auxI);
        printf("\n %s\t %s\t %d\t %d\n",club->nombre,club->apodo,club->posicion,club->seguidores);

        printf("\nDesea eliminar este Club??(s/n)\n");
        fflush(stdin);
        scanf("%c",&respuesta);
        if(respuesta=='s')
        {
            lista->remove(lista,auxI);
            printf("Club eliminado");
            generarBinario(lista,club);

        }
        else
        {
            printf("\nEliminacion cancelada\n");
        }
    }
}

void ModifocarClub(ArrayList* lista, EClub* club)
{
    club=newClub();

    char respuesta;
    int i,posicion;
    int auxI=-1;

    printf("\nIngrese la posicion del equipo que desea Modificar\n");
    scanf("%d",&posicion);

    for(i=0; i<lista->len(lista); i++)
    {
        club=(EClub*)lista->get(lista,i);
        if(club->posicion==posicion)
        {
            auxI=i;
            break;
        }
    }
    if(auxI==-1)
    {
        printf("\nClub inexistente\n");
    }
    else
    {
        club=(EClub*)lista->get(lista,auxI);
        printf("\n %s\t %s\t %d\t %d\n",club->nombre,club->apodo,club->posicion,club->seguidores);
        printf("\nDesea modificar este Club??(s/n)\n");
        fflush(stdin);
        scanf("%c",&respuesta);
        if(respuesta=='s')
        {


            printf("\nPor favor ingrese el nombre del Club\n ");
            fflush(stdin);
            gets(club->nombre);

            printf("\nPor favor ingrese el apodo del Club\n ");
            fflush(stdin);
            gets(club->apodo);

            printf("\Por favor ingrese la cantidad de seguidores\n");
            scanf("%d",&club->seguidores);

            printf("\Por favor ingrese la posicion de su equipo \n");
            scanf("%d",&club->posicion);

            club=(EClub*)lista->set(lista,auxI,club);

            generarBinario(lista,club);

        }
        else
        {
            printf("\nModificacion cancelada cancelada\n");
        }


    }

}
void PosicionEspecificada(ArrayList* lista, EClub* club)
{
    int i;
    int auxi,posicion;

    printf("\nPor favor ingrese el nombre del Club\n ");
    fflush(stdin);
    gets(club->nombre);

    printf("\nPor favor ingrese el apodo del Club\n ");
    fflush(stdin);
    gets(club->apodo);

    printf("\Por favor ingrese la cantidad de seguidores\n");
    scanf("%d",&club->seguidores);

    printf("\nPor favor ingrese la posicion donde quiere ubicar su club");
    scanf("%d",&posicion);
    //club->posicion=posicion;

    for(i=0; i<lista->len(lista); i++)
    {
        club=(EClub*)lista->get(lista,i);
        if(club->posicion==posicion)
        {
            auxi=i;
            break;

        }
    }
    printf("\ni=%d\n",auxi);

    lista->set(lista,auxi,club);

    lista->push(lista,auxi,club);

    if(lista->push(lista,auxi,club)==0)
    {
        printf("\nSu club fue insertado correctamente");
    }
    else
    {
        printf("\n No se ha podido añadir este nuevo equipo");
    }


}

int comparaPersonas(void* club,void* Equipo)
{

    if(((EClub*)club)->posicion > ((EClub*)Equipo)->posicion)
    {
        return 1;
    }
    if(((EClub*)club)->posicion < ((EClub*)Equipo)->posicion)
    {
        return -1;
    }
    return 0;
}
//*******************************************************
int LeerEquipos( FILE* Archivo,ArrayList* lista)
{
    char  posicion[500],nombre[500], apodo[500],seguidores[500];
    EClub* Equipo;
    int retorno;
    Archivo=fopen("data.csv","r");
    if(Archivo==NULL||lista==NULL)
    {
        retorno=0;
    }
    else
    {

        fscanf(Archivo, " %[^,],%[^,],%[^,],%[^\n]\n",nombre,apodo,posicion,seguidores);

        while(!feof(Archivo))
        {
            fscanf(Archivo, " %[^,],%[^,],%[^,],%[^\n]\n",nombre,apodo,posicion,seguidores);

            Equipo=newClubParametros(nombre,posicion,seguidores,apodo);
            if(Equipo!=NULL)
            {


                Equipo->posicion=atoi(posicion);
                strcpy(Equipo->nombre,nombre);
                strcpy(Equipo->apodo,apodo);
                Equipo->seguidores=atoi(seguidores);

                al_add(lista,Equipo);


            }

        }

        retorno=1;
    }


    fclose(Archivo);

    return retorno;


}
void VerificacionPos(ArrayList* lista,EClub* club,int aux)
{
    int i;

    for(i=0; i<lista->len(lista); i++)
    {
        club=(EClub*)lista->get(lista,i);

        if(aux!=club->posicion&&aux<1&&aux>22)
        {
            aux=club->posicion;
            break;
        }
        else
        {
            printf("\n Por favor ingrese una posicion diferente\n");
            scanf("%d",&aux);
            break;

        }


    }
}







