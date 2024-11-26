#ifndef ARQUIVO_H
#define ARQUIVO_H

#include "arvore.c"


No* carregar_livros(char nome_arquivo[], No** raiz);

void escrever_arquivo(FILE *arquivo, No *raiz);

void salvar_arvore(char nomeArquivo[], No *raiz);

void opcao_salvamento();

#endif