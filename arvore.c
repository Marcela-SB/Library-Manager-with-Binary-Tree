
#include "arvore.h"


No* inicializar_arvore(){
    No *n = (No*) malloc(sizeof(No));

    n->livro = NULL;
    n->sae = NULL;
    n->sad = NULL;

    return n;
}

void exibir_arvore(No* raiz){
    printf("\n< %d (Título: %s, Autor: %s)", raiz->livro->codigo, raiz->livro->titulo);
    {
    //printf("\n< %d (Título: %s, Autor: %s, Gênero: %s, Ano: %d, Editora: %s, Nº Páginas: %d)", raiz->livro->codigo, raiz->livro->titulo, raiz->livro->autor, raiz->livro->genero, raiz->livro->ano, raiz->livro->editora, raiz->livro->numeroPaginas);
    }
    exibir_arvore(raiz->sae);
    exibir_arvore(raiz->sad);
    printf(">");
}

// libera a memória dos nós e livros a começar dos níveis mais baixos
void liberar_arvore(No* raiz){
    liberar_arvore(raiz->sae);
    liberar_arvore(raiz->sad);
    liberar_livro(raiz->livro);
    liberar_arvore(raiz);
}