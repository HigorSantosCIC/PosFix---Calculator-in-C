#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "head.h"
#include <stdbool.h>
#include "calculadora.h"
#include <math.h>

char* change(const char* str){

	_stack* stack = alocar_stack();
	char ptr[3000];
	char* output;
	output = (char*) calloc(3000, sizeof(char));

	strcpy(ptr, str);
	char aux[2];
	aux[1] = '\0';
    for(int i = 0; i < strlen(ptr) + 1; i++){
        switch(ptr[i]){
           //maior prioridade
            case '*':
            case '/':
                if(!IsEmpty(stack) && ((top_pilha(stack) == '*') || (top_pilha(stack) == '/'))){
					aux[0] = (char) pop(stack);
                	strcat(output,aux);                                                     
                }
                push(ptr[i], stack);
				(char) top_pilha(stack);
				strcat(output, " "); //add
                break;
            //menor prioridade
            case '+':
            case '-':
                    if(!IsEmpty(stack) && top_pilha(stack) != '(' && top_pilha(stack) != '[' && top_pilha(stack) != '{'){
                        aux[0] = (char)pop(stack);
                        strcat(output,aux);
                    }
                    push((double)ptr[i], stack);
                    (char) top_pilha(stack);
                    strcat(output, " "); //add
                break;

            // INCIOS DE ESCOPO
            case '(':
            case '[':
            case '{':
            	push(ptr[i], stack);		
				(char) top_pilha(stack);
                break;

            // FINS DE ESCOPO
            case ')':
			case ']':
			case '}':
				if(!IsEmpty(stack)){ 
	            	while(top_pilha(stack) != '[' && top_pilha(stack) != '(' && top_pilha(stack) != '{'){
						aux[0] = (char) pop(stack);
  						strcat(output,aux);
					}
					pop(stack);
    			}        	
            	break;
			// case 0 até case 9 -> add
            case '0':	
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
			case '.':
                    if(ptr[i] == '.') strcat(output, ".");
                    else{ 
                        aux[0] = (char) ptr[i];
                        strcat(output,aux);
                    }
                break;
			default:
				strcat(output," ");
				break;
        }
    }
		while(!IsEmpty(stack)){
			aux[0] = (char) pop(stack);
			strcat(output, aux);
		}
    free(stack);
    return output;
 }


double avalia(const char* str){

    _stack* stack = alocar_stack();
    char ptr[3000];
    strcpy(ptr, str);
    char aux[2];
    double soma = 0;
    double divisor = 10;
    int flag = 0;
    aux[1] = '\0';
        for(int i = 0;i < (strlen(ptr) + 1) && ptr[i] != '\0'; i++){
            switch(ptr[i]){
                case '0':
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                case '.':
                    if(ptr[i] == '.') flag = 1;
                    else{
                    if(flag == 0){
                        soma = soma * 10;
                        soma += ptr[i] - 48;
                    }else{
                        soma += (ptr[i] - 48) / divisor;
                        divisor *= 10;
                    }}
                break;
                case ' ':
                case '+':
                case '-':
                case '*':
                case '/':
                    if(i > 0 && (ptr[i-1] >= '0' && ptr[i-1] <= '9')){
                        push(soma, stack);
                        soma = 0;
                        flag = 0;
                        divisor = 10;
                    }
                    if(ptr[i] == '+')
                        push(((pop(stack))+pop(stack)), stack);
                    else if(ptr[i] == '-'){
                        push(-(pop(stack) - pop(stack)), stack);}
                    else if(ptr[i] == '*')
                        push(((pop(stack))*pop(stack)), stack);
                    else if(ptr[i] == '/')      
                        push((1/pop(stack))* pop(stack), stack);
                    break;
                default:    
                    break;
            }
        }
        double x = pop(stack);
        liberar_pilha(stack);   
        return x;     
}

bool Avaliar_expressao(const char* str){
    _stack* stack = alocar_stack();
    char ptr[3000];
    strcpy(ptr, str);

    for(int i = 0; i < strlen(ptr)+1; i++){

        switch(ptr[i]){
            case '(':
            case '[':
            case '{':
                push((double) ptr[i] ,stack);
                break;
            case ')':
            case ']':
            case '}':

                if(IsEmpty(stack)){
                    liberar_pilha(stack);
                    return false;
                }
                else if(ptr[i] == ')' && '(' != pop(stack)) {
                    liberar_pilha(stack);
                    return false;
                }
                else if(ptr[i] == '}' && '{' != pop(stack)){
                    liberar_pilha(stack);
                    return false;
                }
                else if(ptr[i] == ']' && '[' != pop(stack)){
                    liberar_pilha(stack);
                    return false;
                }
                break;

                default:
                    break;
        }
    }
    if(IsEmpty(stack)){
       liberar_pilha(stack);
        return true;
    }else{
        liberar_pilha(stack);
        return false;
    }
}

//menu modos

void menucal(){

    _stack* pi = alocar_stack();

    printf("Modo Calculadora:\n");
    if(IsEmpty(pi)){
        printf("Pilha Vazia\n");
    }
    printf("Pressione 'Q' para sair do programa\n\n");

    while(1){
        char dado[3000];
        double x;
        scanf("%2999[^\n]c", dado);
        getchar();
        switch(dado[0]) {
            case 'Q':
                printf("Programa Finalizado\n\n");
                liberar_pilha(pi);
                exit(1);
            case '+':
            case '-':
            case '*':
            case '/':
                if(IsEmpty(pi)){
                    printf("Nao e possivel realizar a operacao\n");
                }
                else{
                    calculate(pi, dado);
                    system("clear");
                    print_pilha(pi);
                }
                break;
            default:
            if((dado[0] >= '0' && dado[0] <= '9')){
                x = converte(dado);
                push(x, pi);
                system("clear");
                print_pilha(pi);
            }
                break;
        }
    }
    liberar_pilha(pi);
}

void menuexpr(){
    char* aux;
    char expressao[3000];

    _stack* express = alocar_stack();

    printf("Pressione Q para sair do programa\n");
    while(expressao != "Q"){    
        int dado;
        printf("Insira sua expressao:\n");
        scanf("%3000[^\n]s", expressao);
        getchar();

            if(expressao[0] == 'Q'){
                printf("Programa Finalizado\n\n");
                liberar_pilha(express);
                exit(1);
            }

        bool x = Avaliar_expressao(expressao);

        if(x == false){
            printf("\nExpressao Invalida\n");
        }
        else if (x == true){
            printf("\nExpressao Valida\n");
        }

        if(x == true){
            aux = change(expressao);
            //printf(">%s\n", aux);
            printf(">%0.2lf\n\n", avalia(aux));
            free(aux);
        }           
    }
    liberar_pilha(express);
}
    

