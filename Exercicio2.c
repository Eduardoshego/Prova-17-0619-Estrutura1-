#include <stdio.h>
#include <stdlib.h>

struct pilha{
    float valor;
    struct pilha *prox;
};
typedef struct pilha Pilha;


int contador;
Pilha *topo;

void Criar_Pilha()
{
    topo = NULL;
    contador = 0;
    printf("Pilha criada com sucesso\n");
}

int Pilha_vazia()
{
    if (topo == NULL)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void Push(int val)
{
    Pilha *nova = (Pilha *)malloc(sizeof(Pilha)); //cria uma nova celula para empilhar
    if (nova == NULL)
    { //verifica se a celula foi criada.
        printf("\nErro ao criar pilha memoria insuficiente\n");
    }
    else
    {
        nova->valor = val;
        nova->prox = topo;
        topo = nova;
        contador++;
        printf("Elemento(s) inseridos na pilha:%2.f\n quantidade:%d\n",nova->valor,contador );
        
    }
}

void Pop()
{
    if (topo == NULL)
    {
        printf("Erro a pilha está vazia");
    }
    else
    {
        Pilha *temp;
        float aux;
        aux = topo->valor;
        temp = topo;
        topo = topo->prox;
        temp->prox = NULL;
        free(temp);
        printf("Elemento removido da pilha: %f\n na posição: %d ",aux,contador);
        contador--;
        printf("\nQuantidade de elementos na pilha %d:\n",contador);

    }
}


void main(){
    Criar_Pilha();
    Push(9);
    Push(3);
    Push(5);
    Pop();
    Push(10);
    Pop();
    Pop();
    Push(12);


}