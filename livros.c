#include "livros.h"

Livro criar_livro
(int codigo, char *titulo, char *autor, char *genero, int ano, char *editora, int numeroPaginas){
    
    Livro livro;

    livro.codigo = codigo;

    livro.titulo = (char *) malloc(strlen(titulo) + 1);
    strcpy(livro.titulo, titulo);

    livro.autor = (char *) malloc(strlen(autor) + 1);
    strcpy(livro.autor, autor);

    livro.genero = (char *) malloc(strlen(genero) + 1);
    strcpy(livro.genero, genero);

    livro.ano = ano;

    livro.editora = (char *) malloc(strlen(editora) + 1);
    strcpy(livro.editora, editora);

    livro.numeroPaginas = numeroPaginas;

    printf("\nLivro %s criado com sucesso!", livro.titulo);

    return livro;
}

void liberar_livro(Livro livro) {
    free(livro.titulo);
    free(livro.autor);
    free(livro.genero);
    free(livro.editora);
}