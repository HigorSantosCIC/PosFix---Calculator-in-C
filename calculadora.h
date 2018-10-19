/**
	@file calculadora.h
	@author Higor Gabriel A Santos
	@brief Funções que executam operações dos modos, na calculadora. 
    Tranformação de infixa para pos-fixa, validação da entrada na calculadora modo expressao, avaliação e execução da expressao, conversão da entrada do tipo string para double, e realização das operações basicas referentes ao modo calculador.
*/

#ifndef CALCULADORA_H
#define CALCULADORA_H
#include "head.h"
#include <stdbool.h>

/**
 * @brief Função das operações basicas
 * 
 * A função calcula as operações de adição, subtração, divisao e multiplicação do modo calculadora.
 * 
 * @param stack 
 * @param char* 
 */
void calculate(_stack* stack, char* dado);
/**
 * @brief Funçao para modularizar o menu do modo calculadora
 * 
 */
void menucal();
/**
 * @brief Funçao para modularizar o menu do modo expressao.
 * 
 */
void menuexpr();
/**
 * @brief Conversão
 * 
 * A função converte a entrada do tipo string para uma saida do tipo double.
 * 
 * @param char* 
 * @return double 
 */
double converte(char* number);
/**
 * @brief Avalia se a expressão esta correta.
 * 
 * A funçao recebe uma string, ja na notação pos fixa e retorna a resposta da operação contida na expressao no formato de double.
 * 
 * @param str 
 * @return double 
 */
double avalia(const char* str);
/**
 * @brief Analise Booleana 
 * 
 * A funçao recebe uma expressao e analisa se ela é verdadeira ou falsa, com um retorno booleano.
 * 
 * @param str 
 * @return true 
 * @return false 
 */
bool Avaliar_expressao(const char* str);
/**
 * @brief Funçao que converte de infixa para pos fixa
A funçao recebe uma string, e transforma para a notaçao pos-fixa
 * @param str 
 * @return char* 
 */
char* change(const char* str);//in to pos

#endif
