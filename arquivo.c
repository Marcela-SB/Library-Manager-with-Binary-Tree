#include "arquivo.h"


No* carregar_livros(char nome_arquivo[], No** raiz) {
    char caminho[55];
    sprintf(caminho, "%s.csv", nome_arquivo);

    FILE *arquivo = fopen(caminho, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return *raiz;
    }

    int codigo, ano, numeroPaginas;
    char titulo[100], autor[50], genero[50], editora[50];

    while (fscanf(arquivo, "%d, %99[^,], %49[^,], %49[^,], %d, %49[^,], %d", &codigo, titulo, autor, genero, &ano, editora, &numeroPaginas) == 7) {

        if (validar_codigo(raizOriginal, codigo) == 0 || *raiz != NULL) {
            Livro livro = criar_livro(codigo, titulo, autor, genero, ano, editora, numeroPaginas);

            inserir_livro(&raizOriginal, livro);
        }
        
        
    }

    fclose(arquivo);
    printf("\n\nLivros carregados com sucesso!");
    return *raiz;
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


void salvar_arvore(char nomeArquivo[], No *raiz){
    FILE *arquivo;
    arquivo = fopen(nomeArquivo, "w");

    if(arquivo == NULL) printf("Erro ao abrir arquivo");

    escrever_arquivo(arquivo, raiz);
    
    fclose(arquivo);
    printf("\n\nArquivo salvo!");
    return;
}


void opcao_salvamento(){
    int x = -1;
    char nomeArquivo[50], caminhoCompleto[55];

    printf("Como deseja salvar o estado atual?\
    \n1- Sobreescrever arquivo principal\
    \n2- Salvar em novo arquivo\
    \n0- Cancelar\
    \
    \n\n>>> ");

    scanf("%d", &x);
    getchar();

    switch (x) {
        case 1:
            salvar_arvore("bd.csv", raizOriginal);
            break;
        case 2:
            printf("Digite o nome do arquivo: ");
            fgets(nomeArquivo, 49, stdin);
            nomeArquivo[strcspn(nomeArquivo, "\n")] = '\0';
            sprintf(caminhoCompleto, "%s.csv", nomeArquivo);
            salvar_arvore(caminhoCompleto, raizOriginal);
            break;
        case 0:
            return;
        default:
            printf("Entrada invalida!");
            break;
    }
    return;
}