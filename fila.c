#include<stdio.h>
#include<stdlib.h>

typedef struct no
{
    int dado;
    struct no *proximo;
}no;

no *inicializa_fila()
{
    no *novo_no = (no*) malloc(sizeof(no));
    if(novo_no != NULL)
    {
        return NULL;
    }
}

no *insere_fila(no *fila, int dado)
{
    no *no_atual = fila;
    no *novo_no = (no*) malloc(sizeof(no));
    
    novo_no->dado = dado;  
    novo_no->proximo = NULL;

    if(fila == NULL)
    {
        fila = novo_no;
    }
    else
    {
        while(no_atual->proximo != NULL)
        {
            no_atual = no_atual->proximo;
        }
        no_atual->proximo = novo_no;
    
    }
    return fila;
}
void imprimir_fila(no *fila)
{
    
    for(no *no_atual = fila; no_atual != NULL; no_atual = no_atual->proximo)
    {
        printf("%d\n",no_atual->dado);
    }
}
void tamanho_fila(no *fila)
{
    no *no_atual = fila;
    int tam = 0;
    while(no_atual != NULL)
    {
        tam++;
        no_atual = no_atual->proximo;
    }
    printf("TAMANHO DA FILA = %d",tam);
}
no *remove_fila(no *fila)
{
    no *no_atual = fila;
    no *no_anterior = NULL;
    if(fila == NULL)
    {
        printf("FILA VAZIA!\n");
    }
    else
    {
        if(no_anterior == NULL)
        {
            fila = no_atual->proximo;
            return fila;
        }
    }
    free(no_atual);
}
int main()
{
    no *fila;
    fila = inicializa_fila();
    fila = insere_fila(fila, 15);
    fila = insere_fila(fila, 6);
    fila = insere_fila(fila, 48);
    imprimir_fila(fila);
    fila = remove_fila(fila);
    printf("\nFILA DEPOIS DE REMOVER 1 ELEMENTO\n");
    imprimir_fila(fila);
    tamanho_fila(fila);
    return 0;
}