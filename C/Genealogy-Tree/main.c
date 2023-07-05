#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Pessoa
{
    char nome[50];
    int idade;
    struct Pessoa **filhos;
    int numFilhos;
};

struct Pessoa* criarPessoa (const char nome[], const int idade, const char nomePai[])
{
    struct Pessoa *result = (struct Pessoa*)malloc(sizeof(struct Pessoa));
    strcpy(result->nome,nome);
    result->idade = idade;
    result->filhos = NULL;
    result->numFilhos = 0;
    return result; 
}

void liberaPessoa (struct Pessoa* p)
{
    if (p->filhos) free(p->filhos);
    free(p);
}

void adicionarFilho (struct Pessoa* filho, const char nomePai[])
{
    struct Pessoa *pai = buscaPessoa()
    ancestral->filhos = (struct Pessoa**)realloc(ancestral->filhos,sizeof(struct Pessoa*)*(ancestral->numFilhos+1));
    ancestral->filhos[ancestral->numFilhos] = filho;
    ancestral->numFilhos++;
}

void imprimePessoa (struct Pessoa *p)
{
    printf("Nome: %s\n",p->nome);
    printf("Idade: %d\n",p->idade);
    printf("Numero de filhos: %u\n",p->numFilhos);
    for (int i = 0; i < p->numFilhos; i++)
        printf("\tNome: %s\n",p->filhos[i]->nome);
}

int main ()
{
    int n, idade;
    char nome[50], nomePai[50];
    scanf("%d",&n);
    scanf("%s %d %s",&nome,&idade,&nomePai);
    struct Pessoa *ancestral = criarPessoa(nome,idade,nomePai);
    
    scanf("%s %d %s",&nome,&idade,&nomePai);
    struct Pessoa *filho1 = criarPessoa(nome,idade);
    adicionarFilho(ancestral,filho1,nomePai);

    scanf("%s %d %s",&nome,&idade,&nomePai);
    struct Pessoa *filho2 = criarPessoa(nome,idade,nomePai);
    adicionarFilho(ancestral,filho2);

    scanf("%s %d %s",&nome,&idade,&nomePai);
    struct Pessoa *filho3 = criarPessoa(nome,idade,nomePai);
    adicionarFilho(ancestral,filho3);

    scanf("%s %d %s",&nome,&idade,&nomePai);
    struct Pessoa *filho4 = criarPessoa(nome,idade,nomePai);
    adicionarFilho(ancestral,filho4);
    
    imprimePessoa(ancestral);

    liberaPessoa(ancestral);
    liberaPessoa(filho1);
    liberaPessoa(filho2);
    liberaPessoa(filho3);
    liberaPessoa(filho4);

    return 0;
}