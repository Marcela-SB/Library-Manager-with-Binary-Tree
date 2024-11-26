#ifndef LIVROS_H
#define LIVROS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct livro Livro;

struct livro {
    int codigo;  
    char titulo[100];
    char autor[50]; 
    char genero[50];
    int ano;
    char editora[50]; 
    int numeroPaginas;
};

Livro criar_livro(int codigo, char titulo[], char autor[], char genero[], int ano, char editora[], int numeroPaginas);



#endif