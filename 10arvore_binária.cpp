#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct no
{
    int conteudo;
    struct no *esquerda, *direita;

} No;

typedef struct
{
    No *raiz;
} ArvBinaria;

void inserirEsquerda(No *no, int valor)
{
    if (no->esquerda == NULL)
    {
        No *novoNo = (No *)malloc(sizeof(No));
        novoNo->conteudo = valor;
        novoNo->esquerda = NULL;
        novoNo->direita = NULL;
        no->esquerda = novoNo;
    }
    else
    {
        if (valor < no->esquerda->conteudo)
        {
            inserirEsquerda(no->esquerda, valor);
        }
        else
        {
            inserirEsquerda(no->direita, valor);
        }
    }
}

void inserirDireita(No *no, int valor)
{
    if (no->direita == NULL)
    {
        No *novoNo = (No *)malloc(sizeof(No));
        novoNo->conteudo = valor;
        novoNo->esquerda = NULL;
        novoNo->direita = NULL;
        no->direita = novoNo;
    }
    else
    {
        if (valor > no->direita->conteudo)
        {
            inserirDireita(no->direita, valor);
        }
        else
        {
            inserirEsquerda(no->esquerda, valor);
        }
    }
}

void inserir(ArvBinaria *arv, int valor)
{
    if (arv->raiz == NULL)
    {
        No *novoNo = (No *)malloc(sizeof(No));
        novoNo->conteudo = valor;
        novoNo->esquerda = NULL;
        novoNo->direita = NULL;
        arv->raiz = novoNo;
    }
    else
    {
        if (valor < arv->raiz->conteudo)
        {
            inserirEsquerda(arv->raiz, valor);
        }
        else
        {
            inserirDireita(arv->raiz, valor);
        }
    }
}
void imprimir(No *raiz)
{
    if (raiz != NULL)
    {
        printf("%d ", raiz->conteudo);
        imprimir(raiz->esquerda);
        imprimir(raiz->direita);
    }
}

int main()
{
    int op, valor;
    ArvBinaria arv;
    arv.raiz = NULL;

    do
{
    printf("\nMENU:\n0 = SAIR\n1 = inserir\n2 = criar arvore aleatoria\n3 = Imprimir");
    scanf("%d", &op);

    switch (op)
    {
        case 0:
            printf("\nSaindo...");
            break;
        case 1:
            printf("insira o valor: ");
            scanf("%d", &valor);
            inserir(&arv, valor);
            break;
        case 2:
            srand(time(NULL));
            for (int i = 0; i < 10; i++) {
                int valor = rand() % 100;
                inserir(&arv, valor);
            }
            printf("\nArvore aleatoria criada.");
            break;
        case 3:
            printf("\nImprimindo...\n");
            imprimir(arv.raiz);
            break;
        default:
            printf("\nOpcao invalida!\n");
            break;
    }
} while (op != 0);

}