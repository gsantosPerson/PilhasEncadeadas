#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int valor;
    struct No *prox;
}No;

typedef struct Pilha{
    struct No *topo;
}Pilha;

Pilha *criar(){
    Pilha *p = malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}

int push(Pilha *p, int valor){
    No *empilhar = malloc(sizeof(No));

    empilhar->valor = valor;
    empilhar->prox = p->topo;
    p->topo = empilhar;



    return 1;
}

int isEmpty(Pilha *p){
    return p->topo == NULL;
}

int pop(Pilha *p){
    No *desempilhar = p->topo;

    if(isEmpty(p)){
        printf("\nPilha vazia\n");
        return 0;
    }

    int valor = desempilhar->valor;

    p->topo = desempilhar->prox;

    return valor;


}

void imprimir(Pilha *p){
        No *mostrar = p->topo;

        if(isEmpty(p)){
            fprintf(stderr, "\nPilha vazia\n");
        }

        while(mostrar != NULL){
                printf("%d ", mostrar->valor);
                mostrar = mostrar->prox;
            }
        return;
        }

int main(){

int tam = 5, valor;
Pilha *p = criar();

for(int i = 0; i < tam; i++){
    printf("Valor: ");
    scanf("%d", &valor);
    push(p, valor);
}

pop(p);
imprimir(p);

return 0;

}
