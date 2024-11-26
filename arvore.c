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
void buscar_por_genero_aux(No* raiz, char genero[], boolean* encontrado) {
    if (raiz == NULL) return;

    if (strcmp(raiz->livro->genero, genero) == 0) {
        printf("\n%s, de %s;", raiz->livro->titulo, raiz->livro->autor);
        *encontrado = TRUE; 
    }

    buscar_por_genero_aux(raiz->sae, genero, encontrado);
    buscar_por_genero_aux(raiz->sad, genero, encontrado);
}
void buscar_por_genero(No* raiz, char genero[]) {
    boolean encontrado = FALSE; 
    buscar_por_genero_aux(raiz, genero, &encontrado);

    if (!encontrado) {
        printf("Nao ha livros com esse genero");
    }
}



int validar_codigo(No* raiz, int codigo){
    if (raiz == NULL) return 0;

    if (raiz->livro->codigo == codigo) {
        return 1;
    }
    validar_codigo(raiz->sae, codigo);
    validar_codigo(raiz->sad, codigo);

    return 0;
}

Livro criar_livro_manualmente(){
    int c, y, p;  
    char t[100], a[50], g[50], e[50];
    Livro livro_vazio = {0};

    printf("\n\nInsira as informacoes do livro...\n");

    printf("Codigo: ");
    scanf("%d", &c);
    getchar();
    if (validar_codigo(raizOriginal, c) == 1) {
        printf("\nLivro com codigo %d já existe!", c);
        return livro_vazio;
    }
    
    printf("Titulo: ");
    fgets(t, 99, stdin);
    t[strcspn(t, "\n")] = '\0';

    printf("Autor: ");
    fgets(a, 49, stdin);
    a[strcspn(a, "\n")] = '\0';
    
    printf("Genero: ");
    fgets(g, 49, stdin);
    g[strcspn(g, "\n")] = '\0';

    printf("Ano: ");
    scanf("%d", &y);
    getchar();

    printf("Editora: ");
    fgets(e, 49, stdin);
    e[strcspn(e, "\n")] = '\0';

    printf("N. Paginas: ");
    scanf("%d", &p);
    getchar();

    return criar_livro (c, t, a, g, y, e, p);
}