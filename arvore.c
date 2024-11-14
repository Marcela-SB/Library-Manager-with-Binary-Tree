#include "arvore.h"


No* inicializar_arvore(){
    No *n = (No*) malloc(sizeof(No));

    n->livro = NULL;
    n->sae = NULL;
    n->sad = NULL;

    return n;
}





// libera a memória dos nós e livros a começar dos níveis mais baixos
void liberar_arvore(No* raiz){
    liberar_arvore(raiz->sae);
    liberar_arvore(raiz->sad);
    liberar_livro(raiz->livro);
    liberar_arvore(raiz);
}