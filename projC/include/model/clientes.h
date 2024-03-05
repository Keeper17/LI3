#ifndef __MOD_CLIENTES__
#define __MOD_CLIENTES__

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bool.h"
#include "listas.h"

#define MAXBUFSIZE 128
#define LEFT -1
#define BAL 0
#define RIGHT 1

/**
 * @file clientes.h
 * Funções relacionadas com as informações dos clientes.
 *
 */

/* E S T R U T U R A S */

/** @brief Árvore Binária AVL onde são guardados os códigos de clientes, juntamente com um
* booleano que nos diz se o cliente comprou ou não.
*/
typedef struct avlClientes* AVLClientes;
/** @brief Estrutura semelhante a uma Hash Table onde guardamos os apontadores para as árvores dos clientes, sendo que guarda 26 árvores, uma para cada letra do alfabeto.
*/
typedef struct hashClientes* CatClientes;


/* F U N Ç Õ E S  A U X I L I A R E S*/

/** @brief Função de validação de um cliente
* @param[in] cliente Um código de cliente a ser validado.
* @return bool Um booleano que nos informa se o código é válido ou não
*/
bool validaCliente(char* cliente);
/** @brief Hash para o Catálogo de Clientes
* @param[in] cliente Um código de cliente
* @return int O hash desse cliente
*/
int hashC(char* cliente);
/** @brief Funçãode verificação da existência de um cliente no catálogo de clientes
* @param[in] cliente Um código de cliente
* @param[in] cp O catálogo de clientes onde vamos procurar
* @return bool Se o código existe ou não.
*/
bool existeCliente(char* cod, CatClientes cp);
/** @brief Função de auxílio à atualização do estado de um cliente. Quando o código é encontrado numa struct avlClientes, o valor é atualizado para true.
*   @param[in] ap A AVLClientes onde vamos procurar.
*   @param[in] cod O código a procurar.
*   @return bool Se o Cliente existe ou não.
*/
void updateExisteCAux(AVLClientes ap, char* cod);
/** @brief Função de atualização do estado de um cliente.
*   @param[in] c O Catálogo de Clientes onde vamos procurar.
*   @param[in] cod O código a procurar.
*/
void updateExisteC(CatClientes c, char* cod);
/** @brief Função auxiliar para criar um Array com os clientes que efetuaram compras.
*   @param[in] c AVLClientes onde vamos procurar.
*   @param[in] r Array onde vamos guardar os clientes que efetuaram compras.
*/
void clToArrayAux(AVLClientes c, Array r);
/** @brief Função para criar um Array com os clientes que efetuaram compras.
*   @param[in] c Catálogo com todas as AVLs dos clientes.
*   @param[in] r Array onde vamos guardar os clientes que efetuaram compras.
*   @return Array com os clientes que efetuaram compras.
*/
Array clToArray(CatClientes c, Array r);

/* Q U E R I E S */

/** @brief Função de travessia para a query 6. Esta percorre uma AVL, contando o número de clientes que não compraram.
*   @param[in] a A AVL que vamos percorrer.
*   @param[in] s Um apontador para um inteiro onde vamos guardar o número de clientes que não compraram.
*/
void query6CliAux(AVLClientes a, int *i);
/** @brief Função de travessia para a query 6. Esta percorre todas as AVLs do Catálogo de Clientes.
*   @param[in] c O Catálogo que vamos percorrer.
*   @return O número de clientes que não compraram.
*/
int query6Cli(CatClientes c);

/* I N S E R Ç Ã O */

/** @brief Função de inserção numa árvore de procura balanceada.
*   @param[in] clientes A árvore onde vamos inserir um cliente
*   @param[in] cliente O código que vamos inserir.
*   @return A árvore nova com o novo código inserido e balanceada.
*/
AVLClientes insertAVLClientes(AVLClientes *clientes, char* cliente);
/** @brief Função de inserção num Catálogo de Clientes.
*   @param[in] cc O Catálogo onde vai ser feita a inserção.
*   @param[in] clientes O código que vamos inserir.
*   @return O Catálogo com o novo cliente inserido.
*/
CatClientes insertCatClientes(CatClientes cc, char* clientes);

/* L I B E R T A Ç Ã O  D E  M E M Ó R I A */

/** @brief Função libertação de memória de uma AVL de clientes.
*   @param[in] avlClientes A árvore cuja memória vamos libertar
*/
void freeAVLClientes(AVLClientes avlClientes);
/** @brief Função libertação de memória de um Catálogo de Clientes.
*   @param[in] cc O Catálogo cuja memória vamos libertar
*/
void freeCatClientes(CatClientes cc);

/* I N I C I A L I Z A Ç Ã O */

/** @brief Função de Inicialização de um Catálogo de Clientes.
*   @return Um novo catálogo de clientes
*/
CatClientes initCatClientes();

#endif
