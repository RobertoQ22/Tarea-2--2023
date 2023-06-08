#include "prototipos.h"
#include <stdio.h>
#include <string.h>

// Implementaciones generales:
void presentacion() {
  printf("----Servicio de streaming----\n");
  printf("---------Bienvenido---------\n");
}
void menu() {
  printf("1. [Listo]Ingresar pelicula\n");
  printf("2. Ingresar serie\n");
  printf("3. [Listo]Reproducir pelicula\n");
  printf("4. Reproducir serie\n");
  printf("5. [Listo]Buscar pelicula\n");
  printf("6. Buscar serie\n");
  printf("7. [Listo]Eliminar pelicula\n");
  printf("8. Eliminar serie\n");
  printf("9. Salir\n");
}

// Implemetaciones para pelicula:

int primero(Pelicula movie) { return 1; }

bool vacia(Pelicula movie) { return (movie == NULL); }

void insertaOrdenado(char titulo[30], Pelicula &movie) {
  struct pelicula *nuevaPelicula = new pelicula;
  strcpy(nuevaPelicula->titulo, titulo);
  nuevaPelicula->reproducciones = 0;
  nuevaPelicula->primero = NULL;
  nuevaPelicula->next = NULL;

  if (movie == NULL) {
    movie = nuevaPelicula;
  } else if (strcmp(titulo, movie->titulo) < 0) {
    nuevaPelicula->next = movie;
    movie = nuevaPelicula;
  } else {
    Pelicula actual = movie;
    Pelicula siguiente = NULL;
    siguiente = movie->next;
    while (siguiente != NULL && strcmp(titulo, siguiente->titulo) > 0) {
      actual = siguiente;
      siguiente = siguiente->next;
    }

    actual->next = nuevaPelicula;
    nuevaPelicula->next = siguiente;
  }
}

void imprimepeliculas(Pelicula movie) {
  Pelicula copiamovie = movie;
  int contador = 1;
  if (vacia(movie)) {
    printf("No hay peliculas en el catalogo\n");
  } else {
    printf("Catalogo de peliculas:\n");
    while (copiamovie != NULL) {
      printf("%d.- %s\n", contador, copiamovie->titulo);
      copiamovie = copiamovie->next;
      contador++;
    }
  }
}

void imprimedatos(Pelicula movie) {
  Pelicula copiamovie = movie;
  int contador = 1;
  if (vacia(movie)) {
    printf("No hay peliculas en el catalogo\n");
  } else {
    printf("Historial de peliculas:\n\n");
    while (copiamovie != NULL) {
      printf("Pelicula: %s", copiamovie->titulo);
      printf("Reproducciones: %d\n", copiamovie->reproducciones);

      if (copiamovie->primero == NULL) {
        printf("Ningun usuario ha reproducido esta pelicula\n\n");
      } else {
        Usuario copiausuario = copiamovie->primero;
        printf("Usuarios que han reproducido esta pelicula:\n");
        while (copiausuario != NULL) {
          printf("%d.- ID: %d -> Nombre: %s\n", contador, copiausuario->id,
                 copiausuario->nombre);
          copiausuario = copiausuario->sgte;
          contador++;
        }
      }

      copiamovie = copiamovie->next;
    }
  }
}

bool comprobar(char nombre[30], Pelicula movie) {
  while (movie != NULL) {
    if (strcmp(movie->titulo, nombre) == 0) {
      return true;
    }
    movie = movie->next;
  }
  return false;
}

bool comprobarinverso(char nombre[30], Pelicula movie) {
  while (movie != NULL) {
    if (strcmp(movie->titulo, nombre) == 0) {
      return false;
    }
    movie = movie->next;
  }
  return true;
}

void reproduccion(char title[30], char nombre[25], int ident, Pelicula &movie) {

  Usuario nuevousuario = new usuario;
  nuevousuario->id = ident;
  strcpy(nuevousuario->nombre, nombre);
  nuevousuario->sgte = NULL;

  Pelicula copiamovie = movie;
  while (copiamovie != NULL) {
    if (strcmp(copiamovie->titulo, title) == 0) {
      copiamovie->reproducciones++;

      if (copiamovie->primero == NULL) {
        copiamovie->primero = nuevousuario;
      } else {
        Usuario copiausuario = copiamovie->primero;
        while (copiausuario->sgte != NULL) {
          copiausuario = copiausuario->sgte;
        }
        copiausuario->sgte = nuevousuario;
      }
    }
    copiamovie = copiamovie->next;
  }
  printf("Reproduciendo...\n");
}

void buscador(char buscado[30], Pelicula movie) {
  Pelicula copiamovie = movie;
  int contador = 1;
  printf("Catalogo de peliculas:\n");
  while (copiamovie != NULL) {
    if (strcmp(copiamovie->titulo, buscado) == 0) {
      printf("--> %d.- %s", contador, copiamovie->titulo);
    } else {
      printf("%d.- %s", contador, copiamovie->titulo);
    }
    copiamovie = copiamovie->next;
    contador++;
  }
}

void elimina(char eliminar[30], Pelicula &movie) {
  Pelicula copiamovie = movie;
  Pelicula borrar = NULL;
  Pelicula anterior = NULL;
  Pelicula respaldo = NULL;
  
  while (copiamovie != NULL) {
    if(copiamovie->reproducciones >= 5){
      printf("No se puede eliminar este titulo\n\n");
      return;
    }
    if (strcmp(copiamovie->titulo, eliminar) == 0) {
      if (anterior == NULL) {
        borrar = movie;
        respaldo = copiamovie->next;
      } else {
        borrar = copiamovie;
        anterior->next = copiamovie->next;
      }
      borrar->next = NULL;
      delete borrar;
      printf("La película se eliminó correctamente.\n");
      return;
    }

    anterior = copiamovie;
    copiamovie = copiamovie->next;
  }
}
// Implementaciones para Serie
