#include "livros.h"

Livro *criar_livro_manualmente(){
    int codigo, ano, numeroPaginas;
    char *titulo, *autor, *genero, *editora;

    Livro *livro = (Livro *) malloc(sizeof(Livro));

    printf("Insira o código do livro: ");
    scanf("%d",codigo);
    livro->codigo = codigo;

    printf("Insira o título do livro: ");
    livro->titulo = titulo;

    printf("Insira o nome do autor: ");
    livro->autor = autor;

    printf("Insira o genero do livro: ");
    livro->genero = genero;

    printf("Insira o ano de publicação: ");
    scanf("%d",ano);
    livro->ano = ano;

    printf("Insira o nome da editora: ");
    livro->editora = editora;

    printf("Insira o número total de páginas: ");
    scanf("%d",numeroPaginas);
    livro->numeroPaginas = numeroPaginas;

    return livro;
}

Livro *criar_livro
(int codigo, char *titulo, char *autor, char *genero, int ano, char *editora, int numeroPaginas){
    
    Livro *livro = (Livro *) malloc(sizeof(Livro));

    livro->codigo = codigo;
    livro->titulo = (char *) malloc(strlen(titulo) + 1);
    livro->autor = (char *) malloc(strlen(autor) + 1);
    livro->genero = (char *) malloc(strlen(genero) + 1);
    livro->ano = ano;
    livro->editora = (char *) malloc(strlen(editora) + 1);
    livro->numeroPaginas = numeroPaginas;

    return livro;
}

void liberar_livro(Livro *livro) {
    free(livro->titulo);
    free(livro->autor);
    free(livro->genero);
    free(livro->editora);
    free(livro);
}