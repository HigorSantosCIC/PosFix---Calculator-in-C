/**
    @file head.h
    @author Higor Gabriel A Santos
 * @brief Funcão para criar, e efetuar operações na pilha
 * 
Permite a criação de uma pilha dinamica que armazena elementos do tipo double. Tem funcao para verificar se é vazia, inserir elemento, retirar elemento, verificar o topo, imprimir os valores inseridos na pilha e liberar a memoria alocada na pilha.
 */


#ifndef CALCULADOR_IMPLEMENTACAO
#define CALCULADOR_IMPLEMENTACAO

typedef struct elemento{
    double valor;               /*!< Double onde fica armazenado os valores inseridos na pilha.*/
    struct elemento* anterior;  /*!< Endereço do item, que vem antes do topo da pilha.*/
}_elemento;

typedef struct stack{
    int size;               /*!< Quantidade de elementos correspondentes a pilha.*/
    _elemento* topo;        /*!< Endereço do elemento no topo da pilha.*/
}_stack;

/**
 * @defgroup stack Pilha
 Função correspondente a pilha.
 @{
 */

//------//

/** @brief Cria uma pilha dinamica que armazena double.
Pilha criada para armazenar valores do tipo double.
* @return Retorna o endereço da pilha alocada. 
*/

_stack* alocar_stack();

//---------//

/**
 * @brief Aloca elemento struct
 
 @return Retorna endereço do elemento alocado. 
 */

_elemento* aloca_elemento(double valor);//ok

//--------//

/**
 * @brief Verifica se a pilha é vazia
 * 
 * @param stack 
 * @return int 
 */
int IsEmpty(_stack* stack);

//--------//

/**
    @defgroup input Inserir/Retirar
    Funçoes que inserem e retiram elementos da pilha.
    @{
  */

/**
 * @brief Insere elemento na pilha.
 * 
 * A função push insere um valor do tipo double no topo da pilha, que e passada como parametro.
 * 
 * @param valor 
 * @param stack
 * @return void 
 */


void push(double valor,_stack* stack);
/**
 * @brief Retira elementos da pilha.
 * 
 * A função pop retira o elemento contido no topo da pilha.
 * @param stack 
 * @return double 
 */

double pop(_stack* stack); // ok
/**
 * @brief Topo da pilha
 * 
 * A função top_pilha, retorna o primeiro elemento da pilha, do tipo double.
 *  
 * @param stack 
 * @return double 
 */
double top_pilha(_stack* stack);
/**
 * @brief Print Pilha.
 * 
 * A função print_pilha, percorre e imprime os valores inseridos na pilha.
 * @param stack 
 */

void print_pilha(_stack* stack);
/**
 * @brief Liberar pilha
 * A função libera_pilha remove de maneira segura os elementos contidos, para depois dar free na pilha.
 * 
 * @param stack 
 */
void liberar_pilha(_stack* stack);//ok

#endif
