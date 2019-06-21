#include<stdio.h>

#define m 10

struct fila{
    int elem[m];
    int comeco, tamanho, fim;
}F;

void Criar_Fila(){
    F.fim=0;
    F.tamanho=0;
    F.comeco=1;
}

void Enqueue(int x){
    if(F.tamanho == m-1){
    printf("Fila cheia\n");
    }
    else{
        F.tamanho++;
        F.fim = (F.fim % (m-1) + 1);
        F.elem[F.fim] = x;
        printf("%d\n",x);
    }
}
void Dequeue(){
    if(F.comeco == 0){
        printf("Fila vazia\n");
}
    else{
     F.comeco = (F.comeco%(m-1)+1);
    }
}

void main(){
    Criar_Fila();
    Enqueue(11);
    Enqueue(8);
    Enqueue(98);
    Enqueue(17);
    Enqueue(87);
    Dequeue();
    Enqueue(10);
    Dequeue();
    Dequeue();
    Enqueue(12);
    Enqueue(12);
    Dequeue();

}