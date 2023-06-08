#include "nodopelicula.h"
#include "nodousuario.h"

//Prototipos generales:
void presentacion();
void menu();

//Prototipos de pelicula:
int primero(Pelicula movie);
bool vacia(Pelicula movie);
int fin(Pelicula movie);
void insertaOrdenado(char titulo[30], Pelicula &movie);
void imprimepeliculas(Pelicula movie);
void imprimedatos(Pelicula movie);
bool comprobar(char nombre[30], Pelicula movie);
bool comprobarinverso(char nombre[30], Pelicula movie);
void reproduccion(char nombre[30], Pelicula &movie);
void reproduccion(char title[30], char nombre[25], int ident, Pelicula &movie);
void buscador(char buscado[30], Pelicula movie);
void elimina(char eliminar[30], Pelicula &movie);
//Portitipos de usuario:
