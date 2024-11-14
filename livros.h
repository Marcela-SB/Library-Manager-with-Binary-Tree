#ifndef LIVROS_H
#define LIVROS_H

#include <stdio.h>
#include <stdlib.h>

typedef struct livro Livro;

struct livro {
    int codigo;         // Identificador único do livro.
    char *titulo;       // Nome do livro.
    char *autor;        // Autor do livro.
    char *genero;       // Gênero do livro.
    int ano;            // Ano de publicação do livro.
    char *editora;      // Nome da editora responsável pela publicação.
    int numeroPaginas;  // Total de páginas do livro.
};

Livro *criar_livro_manualmente();
Livro *criar_livro();
void liberar_livro(Livro *livro);

#endif