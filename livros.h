#ifndef LIVROS_H
#define LIVROS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct livro Livro;

struct livro {
    int codigo;  
    char *titulo;
    char *autor; 
    char *genero;
    int ano;
    char *editora; 
    int numeroPaginas;
};


Livro criar_livro(int codigo, char *titulo, char *autor, char *genero, int ano, char *editora, int numeroPaginas);
void liberar_livro(Livro livro);

#endif