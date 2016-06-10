
typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[100];

}EMovie;


void IngresoPelicula();

void BajaDePelicula();

void GenerarPagWeb();

float ValidarPuntaje();
