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
    raiz->livro->editora, raiz->livro->numeroPaginas);

    exibir_arvore(raiz->sad);
}


// libera a memória dos nós e livros a começar dos níveis mais baixos
void liberar_arvore(No* raiz){
    if (raiz == NULL) return;

    liberar_arvore(raiz->sae);
    liberar_arvore(raiz->sad);
    liberar_livro(*(raiz->livro));
    
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

No* carregar_livros(char* nome_arquivo, No* raiz) {
    char *caminho = (char *)malloc(strlen(nome_arquivo) + 5); // +5 para ".csv" e '\0'
    if (caminho == NULL) {
        printf("Erro ao alocar memória para o nome do arquivo.\n");
        return raiz;
    }
    sprintf(caminho, "%s.csv", nome_arquivo);


    FILE *arquivo = fopen(caminho, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return raiz;
    }

    int codigo, ano, numeroPaginas;
    char *titulo, *autor, *genero, *editora;

    titulo = (char *)malloc(100 * sizeof(char));
    autor = (char *)malloc(100 * sizeof(char)); 
    genero = (char *)malloc(50 * sizeof(char));  
    editora = (char *)malloc(100 * sizeof(char));

    // Inicializar os ponteiros para evitar uso de valores não inicializados
    titulo[0] = '\0';
    autor[0] = '\0';
    genero[0] = '\0';
    editora[0] = '\0';

    while (fscanf(arquivo, "%d, %s, %s, %s, %d, %s, %d\n", &codigo, titulo, autor, genero, &ano, editora, &numeroPaginas) == 7) {

        Livro livro = criar_livro(codigo, titulo, autor, genero, ano, editora, numeroPaginas);

        inserir_livro(&raiz, livro);
    }

    fclose(arquivo);
    return raiz;
}



void escrever_arquivo(FILE *arquivo, No *raiz){
    if (arquivo != NULL && raiz != NULL) {
        fprintf(arquivo, "%d, %s, %s, %s, %d, %s, %d\n", 
            raiz->livro->codigo, 
            raiz->livro->titulo, 
            raiz->livro->autor, 
            raiz->livro->genero, 
            raiz->livro->ano, 
            raiz->livro->editora, 
            raiz->livro->numeroPaginas);

        escrever_arquivo(arquivo, raiz->sae);
        escrever_arquivo(arquivo, raiz->sad);
    }
}


void salvar_arvore(char *nomeArquivo){
    FILE *arquivo;
    arquivo = fopen(nomeArquivo, "w");

    if(arquivo == NULL) printf("Erro ao abrir arquivo");

    escrever_arquivo(arquivo, raizOriginal);
    
    fclose(arquivo);
    return;
}


void opcao_salvamento(){
    int x = -1;
    char *nomeArquivo = "bd.csv";

    printf("Como deseja salvar o estado atual?\
    \n1- Sobreescrever arquivo principal\
    \n2- Salvar em novo arquivo\
    \n0- Cancelar");

    scanf("%d", &x);

    switch (x) {
        case 1:
            salvar_arvore(nomeArquivo);
            break;
        case 2:
            printf("Digite o nome do arquivo: ");
            scanf("%s", nomeArquivo);
            nomeArquivo = strcat(nomeArquivo, ".csv");
            salvar_arvore(nomeArquivo);
            break;
        case 0:
            return;
        default:
            printf("Entrada invalida!");
            break;
    }
    return;
}