#include "livros.h"

extern No* raizOriginal;

int validar_codigo(No* raiz, int codigo){
    if (raiz == NULL) return 0;

    if (raiz->livro->codigo == codigo) {
        return 1;
    }
    buscar_codigo(raiz->sae, codigo);
    buscar_codigo(raiz->sad, codigo);
}

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

Livro criar_livro_manualmente(){
    int c, y, p;  
    char t[100], a[50], g[50], e[50]; 

    printf("\n\nInsira as informacoes do livro...\n");

    printf("Código: ");
    scanf("%d", &c);
    if (validar_codigo(raizOriginal, c) == 1) {
        printf("\nLivro com código %d já existe!", c);
        return;
    }
    
    printf("Título: ");
    fgets(t, 99, stdin);

    printf("Autor: ");
    fgets(a, 49, stdin);
    
    printf("Genero: ");
    fgets(g, 49, stdin);

    printf("Ano: ");
    scanf("%d", &y);

    printf("Editora: ");
    fgets(e, 49, stdin);

    printf("N. Paginas: ");
    scanf("%d", &p);

    return criar_livro (c, t, a, g, y, e, p);
}