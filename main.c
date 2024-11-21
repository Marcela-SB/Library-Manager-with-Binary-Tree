#include <stdio.h>
#include <stdlib.h>

#include "arvore.c"

int main(void){
    int opcao = -1;
    No* raizOriginal = NULL;

    Livro l1 = criar_livro(12344, "Livro A", "Autor A", "Genero A", 2024, "Editora A", 200);
    Livro l2 = criar_livro(12345, "Livro B", "Autor B", "Genero B", 2023, "Editora B", 150);
    Livro l3 = criar_livro(12343, "Livro C", "Autor C", "Genero A", 2022, "Editora C", 300);

    inserir_livro(&raizOriginal, l1);
    inserir_livro(&raizOriginal, l2);
    inserir_livro(&raizOriginal, l3);

    printf("\n\nArvore binaria:");
    exibir_arvore(raizOriginal);

    printf("\n\nBuscando:");
    buscar_por_genero(raizOriginal, "Genero A");

    liberar_arvore(raizOriginal);




    while (opcao != 0) {
        //printf("Conexao com o banco de dados realizada com sucesso!");
        printf("\n\nO que deseja fazer? \
                \n1- Adicionar novo livro\
                \n2- Buscar livro por genero\
                \n3- Exibir livros\
                \n0- Sair");

        printf("\n\nEscolha: ");
        scanf("%d", &opcao);

        system("cls");

        switch (opcao) {
        case 1:
            printf("Opcao 1");
            break;
        case 2:
            printf("Opcao 2");
            break;
        case 3:
            printf("Opcao 3");
            break;
        case 0:
            printf("Saindo...");
            break;
        
        default:
            printf("\n\nEntrada invalida!");
            break;
        }
        
    }
    

    return 0;
}