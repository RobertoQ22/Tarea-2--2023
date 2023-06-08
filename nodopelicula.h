#ifndef PELICULA_H
#define PELICULA_H

struct pelicula{
    char titulo[30];
    int reproducciones;
    struct usuario* primero;
    struct pelicula* next;
};
#define Pelicula pelicula*
#endif