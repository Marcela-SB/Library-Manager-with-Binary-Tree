#ifndef ARVORE_H
#define ARVORE_H

#include "livros.c"

typedef struct arvore No;

struct arvore {
    Livro *livro;
    No *sae;
    No *sad;
};

No* inicializar_arvore();

void inserir_livro(No** raiz, Livro livro);

void buscar_por_genero(No* raiz, char genero[]);

No* carregar_livros(char* nome_arquivo, No* raiz);

void exibir_arvore(No* raiz);

void liberar_arvore(No* raiz);

#endif