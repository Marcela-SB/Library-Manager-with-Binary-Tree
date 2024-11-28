#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <windows.h>

#include "arquivo.c"

No* raizOriginal = NULL;

int main(void){
    int opcao = -1;
    Livro l;
    char genero[50], nomeArquivo[50];

    carregar_livros("bd", &raizOriginal);

    #ifdef _WIN32
        Sleep(1000);
        printf("\n\n.");
        Sleep(1000);
        printf(".");
        Sleep(1000);
        printf(".");
        Sleep(1000);
    #else
        sleep(1);
        printf("\n\n.");
        sleep(1);
        printf(".");
        sleep(1);
        printf(".");
        sleep(1);
    #endif


    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif


    while (opcao != 0) { 
        printf("\n\n****************************************** \
                \nO que deseja fazer? \
                \n1- Adicionar novo livro\
                \n2- Buscar livro por genero\
                \n3- Exibir livros\
                \n4- Carregar arquivo\
                \n5- Salvar estado\
                \n0- Sair");

        printf("\n\n>>> ");
        scanf("%d", &opcao);
        getchar();

        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif

        switch (opcao) {
            case 1:     // Adicionar novo livro
                l = criar_livro_manualmente(raizOriginal);
                if (l.codigo == 0) { 
                    printf("\nOperacao cancelada.\n");
                } else {
                    inserir_livro(&raizOriginal, l);
                }
                break;
                
            case 2:     // Buscar livro por genero
                printf("Por qual genero deseja buscar?\n\
                >>> ");
                fgets(genero, sizeof(genero), stdin);
                genero[strcspn(genero, "\n")] = '\0';
                buscar_por_genero(raizOriginal, genero);
                break;

            case 3:     // Exibir livros
                exibir_arvore(raizOriginal);
                break;

            case 4:     // Carregar arquivo
                printf("Qual o nome do arquivo? (digite sem a extensao dele) \n>>> ");
                fgets(nomeArquivo, sizeof(nomeArquivo), stdin);
                nomeArquivo[strcspn(nomeArquivo, "\n")] = '\0';
                carregar_livros(nomeArquivo, &raizOriginal);
                break;

            case 5:     // Salvar estado
                opcao_salvamento();
                break;

            case 0:     // Sair
                printf("Salvando banco de dados");

                #ifdef _WIN32
                    Sleep(1000);
                    printf(".");
                    Sleep(1000);
                    printf(".");
                    Sleep(1000);
                    printf(".");
                #else
                    sleep(1);
                    printf(".");
                    sleep(1);
                    printf(".");
                    sleep(1);
                    printf(".");
                #endif

                salvar_arvore("bd.csv", raizOriginal);
                printf("\n\nSaindo...");
                liberar_arvore(raizOriginal);
                break;
            
            default:
                printf("\n\nEntrada invalida!");
                break;
        }
        
    }
    
    return 0;
}