#include "livros.h"

Livro criar_livro
(int codigo, char titulo[], char autor[], char genero[], int ano, char editora[], int numeroPaginas){
    
    Livro livro;

    livro.codigo = codigo;

    strcpy(livro.titulo, titulo);

    strcpy(livro.autor, autor);

    strcpy(livro.genero, genero);

    livro.ano = ano;

    strcpy(livro.editora, editora);

    livro.numeroPaginas = numeroPaginas;

    printf("\nLivro %s criado com sucesso!", livro.titulo);

    return livro;
}
