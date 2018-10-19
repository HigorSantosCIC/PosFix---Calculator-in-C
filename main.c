#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "head.h"
#include "calculadora.h"
#include <string.h>
#include <math.h>

int main(){
    
	while(1){

	int choose;

    printf("1 ->Modo Calculadora:\n2 ->Modo Expressao:\n3 -> Sair do programa\n");

    scanf("%d", &choose);
    getchar();
	system("clear");
    switch(choose){
		case 1:
			menucal();
			break;
		case 2:
			menuexpr();
			break;
		case 3:
			printf("Ate Logo\n");
			return 0;
		default:
			printf("Insira uma opçao valida:\n");
			}
	}
					
			return 0;
}