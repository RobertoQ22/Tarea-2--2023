#ifndef USUARIO_H
#define USUARIO_H

struct usuario{
    int id;
    char nombre[25];
    struct usuario* sgte;
};

#define Usuario usuario*

#endif