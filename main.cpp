#include "prototipos.h"
#include <stdio.h>
#include <string.h>

int main() {
  int opcion = 0;
  Pelicula movie = NULL;
  Usuario user = NULL;
  presentacion();
  while (opcion != 9) {
    menu();
    printf("Ingrese una opcion:");
    scanf("%d", &opcion);

    switch (opcion) {

    case 1: {
      getchar();
      char nombrepelicula[30];
      printf("Nombre de la pelicula:");
      fgets(nombrepelicula, sizeof(nombrepelicula), stdin);

      if (comprobar(nombrepelicula, movie)) {
        printf("La pelicula ya existe\n");

      } else {

        insertaOrdenado(nombrepelicula, movie);
        printf("El titulo fue agregado correctamente\n\n");
      }

      break;
    }
    case 2:

      imprimedatos(movie);
      break;

    case 3: {
      getchar();
      char nombre[25];
      int ID;
      char repelicula[30];

      if (vacia(movie)) {
        printf("No hay peliculas en el catalogo.\n\n");
        break;
      }

      imprimepeliculas(movie);
      printf("¿Que pelicula desea reproducir?:\n");
      fgets(repelicula, sizeof(repelicula), stdin);

      while (comprobarinverso(repelicula, movie)) {
        printf("El titulo no existe, ingrese una de la lista:\n");
        imprimepeliculas(movie);
        printf("¿Que pelicula desea reproducir?:\n");
        fgets(repelicula, sizeof(repelicula), stdin);
      }

      printf("Indique su nombre:\n");
      fgets(nombre, sizeof(nombre), stdin);
      printf("Indique su ID:\n");
      scanf("%d", &ID);
      reproduccion(repelicula, nombre, ID, movie);

      break;
    }
    case 4:
      printf("Usted selecciono reproducir serie\n");
      break;

    case 5: {
      getchar();
      char repelicula[30];

      if (vacia(movie)) {
        printf("No hay peliculas en el catalogo.\n\n");
        break;
      }
      printf("¿Que pelicula desea buscar?:\n");
      fgets(repelicula, sizeof(repelicula), stdin);

      if (comprobarinverso(repelicula, movie)) {
        printf("El titulo no existe\n\n");
      } else {
        printf("El titulo existe\n\n");
        buscador(repelicula, movie);
      }
      break;
    }
    case 6:

    case 7:
      getchar();
      char repelicula[30];
      if (vacia(movie)) {
        printf("No hay peliculas en el catalogo.\n\n");
        break;
      }
      imprimepeliculas(movie);
      printf("¿Que pelicula desea eliminar?:\n");
      fgets(repelicula, sizeof(repelicula), stdin);

      while (comprobarinverso(repelicula, movie)) {
        printf("El titulo no existe, ingrese una de la lista:\n");
        imprimepeliculas(movie);
        printf("¿Que pelicula desea reproducir?:\n");
        fgets(repelicula, sizeof(repelicula), stdin);
      }

      elimina(repelicula, movie);

      break;

    case 8:
      printf("Usted selecciono eliminar pelicula\n");
      break;

    case 9:
      printf("¡Hasta luego!\n");
      break;

    default:
      printf("Opcion invalida\n");
    }
  }
}
