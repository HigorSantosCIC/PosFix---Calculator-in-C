#include <stdio.h>
#include <stdlib.h>
#include "head.h"

_elemento* aloca_elemento(double valor){
    _elemento* ponteiro = (_elemento*) malloc(sizeof(_elemento));
    ponteiro->valor = valor;
    ponteiro->anterior = NULL;

    return ponteiro;
}

_stack * alocar_stack(){
    _stack* ptr = (_stack*) malloc(sizeof(_stack));
    ptr->size = 0;
    ptr->topo = NULL;

    return ptr;
}

int IsEmpty(_stack* stack){
    return (stack->size == 0);
}
void push(double valor, _stack* stack){
    _elemento* ptr = aloca_elemento(valor);

    if(IsEmpty(stack)){
        stack->topo = ptr;
    }
    else{
        ptr->anterior = stack->topo;
        stack->topo = ptr;
    }
    stack->size++;
}
double pop(_stack* stack){
    double aux;

    if(IsEmpty(stack)){
        exit(1);
    }
    else{
        _elemento* ptr = stack->topo;
        aux = ptr->valor;
        stack->topo = ptr->anterior;
        free(ptr);
    }
    stack->size--;
    return aux;
}
double top_pilha(_stack* stack){

    if(IsEmpty(stack)){
        printf("Pilha Vazia\n");
        exit(1);
    }
    else{
        _elemento* ptr = stack->topo;
        double aux = ptr->valor;
        return aux;
    }
}
void liberar_pilha(_stack* stack){
    while(!IsEmpty(stack)){
        pop(stack);
    }
    free(stack);
}

void print_pilha(_stack* stack){
    if(IsEmpty(stack)){
        printf("\nPilha Vazia\n");
    }else{

        _elemento* ptr = stack->topo;
        
        int contador = 1;

        while(ptr != NULL){

            printf("\n%d. %.2lf\n",contador, ptr->valor);
            
            contador++;
             
            ptr = ptr->anterior;
        }
    }
}
