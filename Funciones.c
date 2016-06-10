#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <ctype.h>
#include <string.h>
#include "Funciones.h"



void IngresoPelicula(){
    EMovie LPeliculas;
    FILE *Archivo;

            fflush(stdin);
            printf("\n Ingrese el nombre de la pelicula: ");
            gets(LPeliculas.titulo);
            fflush(stdin);
            printf("\n Ingrese el genero de la pelicula: ");
            gets(LPeliculas.genero);
            printf("\n Ingrese la duracion de la pelicula: ");
            scanf("/i",&LPeliculas.duracion);
            printf("\n Ingrese la descripcion de la pelicula: ");
            fflush(stdin);
            gets(LPeliculas.descripcion);
            printf("\n Ingrese el puntage de la pelicula: ");
            LPeliculas.puntaje=ValidarPuntaje();
            printf("\n Ingrese el Link de la Imagen");
            fflush(stdin);
            gets(LPeliculas.linkImagen);

    if((Archivo=fopen("Archivo.dat","rb"))==NULL){
        if(Archivo=fopen("Archivo.dat","wb")==NULL){
            printf("No se pudo Abrir el archivo");
            exit(1);
        }
    }

    fseek(Archivo,0,SEEK_END);
    fwrite(&LPeliculas,sizeof(EMovie),0L,Archivo);
    fclose(Archivo);

}

void BajaDePelicula(){
    char busqueda[40];
    FILE *Archivo;
    EMovie Pelicula,PeliculaVacia;

    PeliculaVacia.descripcion[0]='\0';
    PeliculaVacia.genero[0]='\0';
    PeliculaVacia.linkImagen[0]='\0';
    PeliculaVacia.duracion=0;
    PeliculaVacia.puntaje=0;
    PeliculaVacia.titulo[0]='\0';

    system("cls");
    printf("Ingrese la pelicula a borrar: ");
    fflush(stdin);
    gets(busqueda);

    if((Archivo=fopen("Archivo.dat","rb"))==NULL){
        printf("No se pudo Abrir el archivo");
    }
    else{
        rewind(Archivo);
        while(feof(Archivo)!=0){
            fread(&Pelicula,sizeof(EMovie),1,Archivo);
            if(strcmp(Pelicula.titulo,busqueda)==0){
                fseek(&Archivo,(long)sizeof(EMovie),SEEK_CUR);
                fwrite(&PeliculaVacia,sizeof(EMovie),0,Archivo);
            }
        }
    }
    fclose(Archivo);
}
void GenerarPagWeb(){
    FILE *Pagina;
    FILE *Archivo;
    EMovie Pelicula;
    char Inicio[400]="<!DOCTYPE html><!-- Template by Quackit.com --><html lang='en'><head><meta charset='utf-8'><meta http-equiv='X-UA-Compatible' content='IE=edge'><meta name='viewport' content='width=device-width, initial-scale=1'><!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags --><title>Lista peliculas</title><!-- Bootstrap Core CSS --><link href='css/bootstrap.min.css' rel='stylesheet'><!-- Custom CSS: You can use this stylesheet to override any Bootstrap styles and/or apply your own styles --><link href='css/custom.css' rel='stylesheet'><!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries --><!-- WARNING: Respond.js doesn't work if you view the page via file:// --><!--[if lt IE 9]><script src='https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script><script src='https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script><![endif]--></head><body><div class='container'><div class='row'>";
    char PreImagen[1000]="<article class='col-md-4 article-intro'><a href='#'><img class='img-responsive img-rounded' src='";
    char ImagenATitulo[100]="'alt=''></a><h3><a href='#'>";
    char TituloAGenero[30]="</a></h3><ul><li>";
    char GenToPuntToDur[11]="</li><li>";
    char DurADescr[30]="</li></ul><p>";
    char EndDescr[30]=".</p></article>";
    char EndPagina[400]=" </div><!-- /.row --></div><!-- /.container --><!-- jQuery --><script src='js/jquery-1.11.3.min.js'></script><!-- Bootstrap Core JavaScript --><script src='js/bootstrap.min.js'></script><!-- IE10 viewport bug workaround --><script src='js/ie10-viewport-bug-workaround.js'></script><!-- Placeholder Images --><script src='js/holder.min.js'></script></body></html>";

    if((Archivo=fopen("Archivo.dat","rb"))==NULL){
        printf("No se pudo Abrir el archivo Binario");
    }
    if((Pagina=fopen("Pagina.html","w"))==NULL){
        printf("No se pudo Abrir el archivo Pagina");
        exit (1);
    }

    fprintf(Pagina,"%s",Inicio);
    rewind(Archivo);
    while(feof(Archivo)!=0){
        fread(&Pelicula,sizeof(EMovie),1,Archivo);
        fprintf(Pagina,"%s %s %s %s %s %s %s %i %s %.2f %s %s ",PreImagen,Pelicula.linkImagen,ImagenATitulo,Pelicula.titulo,TituloAGenero,Pelicula.genero,GenToPuntToDur,Pelicula.duracion,GenToPuntToDur,Pelicula.puntaje,DurADescr,Pelicula.descripcion,EndDescr);
    }
    fprintf(Pagina,"%s",EndPagina);
    fclose(Archivo);
    fclose(Pagina);
}


float ValidarPuntaje(){
    float numero=-1;
    while(numero<=0){
        scanf("%f",&numero);
        if(numero>10){
            numero=-1;
            scanf("\n Error: Reingrese puntage:");
        }
    }
    return numero;
}
