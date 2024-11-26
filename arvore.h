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

void exibir_arvore(No* raiz);

void liberar_arvore(No* raiz);

void buscar_por_genero(No* raiz, char genero[]);

int validar_codigo(No* raiz, int codigo);
Livro criar_livro_manualmente();

#endif