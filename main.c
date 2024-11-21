#include <stdio.h>
#include <stdlib.h>

#include "arvore.c"

No* raizOriginal = NULL;

int main(void){
    int opcao = -1;
    Livro l;
    char *genero = malloc(50 * sizeof(char));
    genero[0] = "\0";

    carregar_livros("bd.csv", raizOriginal);

    Livro l1 = criar_livro(12344, "Livro A", "Autor A", "A", 2024, "Editora A", 200);
    Livro l2 = criar_livro(12345, "Livro B", "Autor B", "B", 2023, "Editora B", 150);
    Livro l3 = criar_livro(12343, "Livro C", "Autor C", "A", 2022, "Editora C", 300);

    inserir_livro(&raizOriginal, l1);
    inserir_livro(&raizOriginal, l2);
    inserir_livro(&raizOriginal, l3);

    printf("\n\nArvore binaria:");
    exibir_arvore(raizOriginal);

    printf("\n\nBuscando:");
    buscar_por_genero(raizOriginal, "A");

    liberar_arvore(raizOriginal);




    while (opcao != 0) {
        //printf("Conexao com o banco de dados realizada com sucesso!");
        printf("\n\nO que deseja fazer? \
                \n1- Adicionar novo livro\
                \n2- Buscar livro por genero\
                \n3- Exibir livros\
                \n4- Carregar arquivo\
                \n5- Salvar estado\
                \n0- Sair");

        printf("\n\nEscolha: ");
        scanf("%d", &opcao);

        system("cls");

        switch (opcao) {
            case 1:
                l = criar_livro(12344, "Livro M", "Autor M", "A", 2024, "Editora M", 200);
                inserir_livro(raizOriginal, l);
                break;
                
            case 2:
                printf("Por qual genero deseja buscar? ");
                scanf("%49s", genero);
                buscar_por_genero(raizOriginal, "A");
                break;

            case 3:
                printf("Opcao 3");
                break;

            case 4:
                printf("Qual o nome do arquivo? (digite sem a extensao dele)  ");   
                char *nomeArquivo;
                scanf("%s", nomeArquivo);
                carregar_livros(nomeArquivo, raizOriginal);
                break;

            case 5:
                opcao_salvamento();
                break;

            case 0:
                printf("Saindo...");
                salvar_arvore("bd.csv");
                liberar_arvore(raizOriginal);
                break;
            
            default:
                printf("\n\nEntrada invalida!");
                break;
        }
        
    }
    

    return 0;
}