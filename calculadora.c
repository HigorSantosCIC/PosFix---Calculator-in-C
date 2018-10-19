#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "head.h"
#include "calculadora.h"

void calculate(_stack* stack, char* dado){
	if(stack->size != 1){
		switch(dado[0]){
				case '+':
					if(dado[1] == '!'){
						while(stack->size > 1){
							push(((pop(stack))+pop(stack)), stack);	
						}
						printf(">%.2lf\n", top_pilha(stack));
					}
					else {
						push(((pop(stack))+pop(stack)), stack);
						printf(">%.2lf\n", top_pilha(stack));
					}
					break;

				case '-':
					if(dado[1] == '!'){
						while(stack->size > 1){
							push(-(pop(stack) - pop(stack)), stack);	
						}
						printf(">%.2lf\n", top_pilha(stack));
					}else{
						push(-(pop(stack) - pop(stack)), stack);
						printf(">%.2lf\n", top_pilha(stack));
					}
						break;
				case '/':
					if(dado[1] == '!'){
						while(stack->size > 1){
							push((1/pop(stack))* pop(stack), stack);
						}
						printf(">%.2lf\n", top_pilha(stack));
					}
					else{
						push((1/pop(stack))* pop(stack), stack);
						printf(">%.2lf\n", top_pilha(stack));
					}
						break;
				case '*':
					if(dado[1] == '!'){
						while(stack->size > 1){
							push(((pop(stack))*pop(stack)), stack);	
						}
						printf(">%.2lf\n", top_pilha(stack));
					}
					else{
						push(((pop(stack))*pop(stack)), stack);
						printf(">%.2lf\n", top_pilha(stack));
					}
					break;
				}
		}  
		else{
			printf("Numero de operandos Insuficientes\n");
			getchar();
		}
}

double converte(char* number){
    double num = 0;
   	int pointposition = strlen(number); 
    for(int i = 0; i < strlen(number); i++){

        if(number[i] == '.' || number[i] == ','){
            pointposition = i;
            break;
        }
	}

    for(int i = 0; i < strlen(number); i++){
        if(number[i] < '0' || number[i] > '9'){
            continue;
		}
        if(i < pointposition){
            num += (number[i] - '0') * pow(10, pointposition - (i + 1));
		}
        else if(i > pointposition){
            num += (number[i] - '0') * pow(10, pointposition - i);
    	}
    	if(number[0] == '-'){
        num *= (double) -1;
	}
}
    return num;
}
