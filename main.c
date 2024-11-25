#include <stdio.h>
#include <stdlib.h>

#include "arquivo.c"

No* raizOriginal = NULL;

int main(void){
    int opcao = -1;
    Livro l;
    char genero[50] = "\0";

    carregar_livros("bd", &raizOriginal);


    while (opcao != 0) { 
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
                l = criar_livro_manualmente();
                inserir_livro(&raizOriginal, l);
                break;
                
            case 2:
                printf("Por qual genero deseja buscar? ");
                fgets(genero, 49, stdin);
                buscar_por_genero(raizOriginal, genero);
                break;

            case 3:
                exibir_arvore(raizOriginal);
                break;

            case 4:
                printf("Qual o nome do arquivo? (digite sem a extensao dele)  ");   
                char nomeArquivo[50];
                fgets(nomeArquivo, 49, stdin);
                carregar_livros(nomeArquivo, &raizOriginal);
                break;

            case 5:
                opcao_salvamento();
                break;

            case 0:
                printf("Saindo...");
                salvar_arvore("bd.csv", raizOriginal);
                liberar_arvore(raizOriginal);
                break;
            
            default:
                printf("\n\nEntrada invalida!");
                break;
        }
        
    }
    
    return 0;
}