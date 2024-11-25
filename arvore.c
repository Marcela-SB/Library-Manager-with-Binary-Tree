#include "arvore.h"

extern No* raizOriginal;

No* inicializar_arvore(){
    No *n = (No*) malloc(sizeof(No));

    n->livro = NULL;
    n->sae = NULL;
    n->sad = NULL;

    return n;
}


// adiciona livro a um nó
void inserir_livro(No** raiz, Livro livro) {
    if (*raiz == NULL) {
        // Aloca um novo nó
        *raiz = inicializar_arvore();
        (*raiz)->livro = (Livro*) malloc(sizeof(Livro));
        *(*raiz)->livro = livro; // Copia o livro para o nó
        (*raiz)->sae = NULL;
        (*raiz)->sad = NULL;

        // Confirma a inserção
        printf("\nLivro inserido: %s (Codigo: %d)", livro.titulo, livro.codigo);
        return;
    }

    // Lógica de inserção com base no código do livro
    if (livro.codigo < (*raiz)->livro->codigo) {
        inserir_livro(&((*raiz)->sae), livro);
    } 
    else {
        inserir_livro(&((*raiz)->sad), livro);
    }
}



// imprime a arvore em ordem
void exibir_arvore(No* raiz){
    if (raiz == NULL || raiz->livro == NULL) return;
    
    exibir_arvore(raiz->sae);
    
    printf("\n%d (Titulo: %s, Autor: %s, Genero: %s, Ano: %d, Editora: %s, N. Paginas: %d)",
    raiz->livro->codigo, 
    raiz->livro->titulo, 
    raiz->livro->autor,
    raiz->livro->genero, 
    raiz->livro->ano, 
    raiz->livro->editora, 
    raiz->livro->numeroPaginas);

    exibir_arvore(raiz->sad);
}


// libera a memória dos nós e livros a começar dos níveis mais baixos
void liberar_arvore(No* raiz){
    if (raiz == NULL) return;

    liberar_arvore(raiz->sae);
    liberar_arvore(raiz->sad);
    
    free(raiz->livro);
    free(raiz);
}


// busca e exibe os livros do gênero requisitado
void buscar_por_genero(No* raiz, char genero[]) {
    if (raiz == NULL) return;

    if (strcmp(raiz->livro->genero, genero) == 0) {
        printf("\n%s, de %s", raiz->livro->titulo, raiz->livro->autor);
    }
    buscar_por_genero(raiz->sae, genero);
    buscar_por_genero(raiz->sad, genero);
    
}

