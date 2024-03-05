#ifndef __MOD_PRODUTOS__
#define __MOD_PRODUTOS__

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/model/bool.h"
#include "../../include/model/listas.h"

#define MAXBUFSIZE 128
#define LEFT -1
#define BAL 0
#define RIGHT 1

/**
 * @file produtos.h
 * Funções relacionadas com as informações dos produtos.
 *
 */

/* E S T R U T U R A S */

/** @brief Árvore Binária AVL onde são guardados os códigos de produtos, juntamente com um
* booleano que nos diz se o produto foi, ou não comprado.
*/
typedef struct avlProdutos* AVLProds;
/** @brief Estrutura semelhante a uma Hash Table onde guardamos os apontadores para as árvores dos
* produtos, sendo que guarda 26 árvores, 1 para cada letra do alfabeto.
*/
typedef struct hashProdutos* CatProds;

/* F U N Ç Õ E S  A U X I L I A R E S*/

/** @brief Função de validação de um produto
* @param[in] prod Um código de produto a ser validado.
* @return bool Um booleano que nos informa se o código é válido ou não
*/
bool validaProduto(char* prod);
/** @brief Hash para o Catálogo de Produtos
* @param[in] prod Um código de produto
* @return int O hash desse produto
*/
int hashP(char* prod);
/** @brief Funçãode verificação da existência de um produto no catálogo de produtos
* @param[in] prod Um código de produto
* @param[in] cp O catálogo de produtos onde vamos procurar
* @return bool Se o código existe ou não.
*/
bool existeProduto(char* prod, CatProds cp);
/** @brief Função de auxílio à atualização do estado de um produto. Quando o código é encontrado numa struct avlProds, o valor é atualizado para true.
*   @param[in] ap A AVLProds onde vamos procurar.
*   @param[in] cod O código a procurar.
*/
void updateExistePAux(AVLProds ap, char* cod);
/** @brief Função de atualização do estado de um produto.
*   @param[in] c O Catálogo de Produtos onde vamos procurar.
*   @param[in] cod O código a procurar.
*/
void updateExisteP(CatProds c, char* cod);

/* Q U E R I E S */

/** @brief Função auxiliar de procura para a query 2. Esta percorre todos os nodos da AVL, adicionando todos os produtos que encontra ao Array passado.
*   @param[in] a A AVL que vamos percorrer.
*   @param[in] ar O Array onde vamos guardar os produtos.
*   @return O Array com os produtos.
*/
Array query2ProdAux(AVLProds a, Array ar);
/** @brief Função de travessia para a query 2. Esta percorre todas as AVLs do Catálogo de Produtos.
*   @param[in] c O Catálogo que vamos percorrer.
*   @param[in] ar O Array onde vamos guardar os produtos.
*   @return O Array com os produtos.
*/
Array query2Prod(CatProds c, char a, Array ar);

/** @brief Função de travessia para a query 4. Esta percorre uma AVL, adicionando ao Array todos os produtos não vendidos.
*   @param[in] c A AVL que vamos percorrer.
*   @param[in] ar O Array onde vamos guardar os produtos.
*   @return O Array com os produtos.
*/
Array query4ProdAux(AVLProds a, Array ar);
/** @brief Função de travessia para a query 4. Esta percorre todas as AVLs do Catálogo de Produtos.
*   @param[in] c O Catálogo que vamos percorrer.
*   @param[in] ar O Array onde vamos guardar os produtos.
*   @return O Array com os produtos.
*/
Array query4Prod(CatProds c, Array ar);

/** @brief Função de travessia para a query 6. Esta percorre uma AVL, contando o número de produtos não vendidos.
*   @param[in] a A AVL que vamos percorrer.
*   @param[in] s Um apontador para um inteiro onde vamos guardar o número de produtos não vendidos.
*/
void query6ProdAux(AVLProds a, int *s);
/** @brief Função de travessia para a query 6. Esta percorre todas as AVLs do Catálogo de Produtos.
*   @param[in] c O Catálogo que vamos percorrer.
*   @return O número de produtos não comprados.
*/
int query6Prod(CatProds c);

/* I N S E R Ç Ã O */

/** @brief Função de inserção numa árvore de procura balanceada.
*   @param[in] prods A árvore onde vamos inserir um código
*   @param[in] prod O código que vamos inserir.
*   @return A árvore nova com o novo código inserido e balanceada.
*/
AVLProds insertAVLProduto(AVLProds *prods, char* prod);
/** @brief Função de inserção num Catálogo de Produtos.
*   @param[in] cp O Catálogo onde vai ser feita a inserção.
*   @param[in] prod O código que vamos inserir.
*   @return O Catálogo com o novo produto inserido.
*/
CatProds insertCatProds(CatProds cp, char* produto);

/* L I B E R T A Ç Ã O  D E  M E M Ó R I A */

/** @brief Função libertação de memória de uma AVL de produtos.
*   @param[in] avlProds A árvore cuja memória vamos libertar
*/
void freeAVLProdutos(AVLProds avlProds);
/** @brief Função libertação de memória de um Catálogo de Produtos.
*   @param[in] cp O Catálogo cuja memória vamos libertar
*/
void freeCatProds(CatProds cp);

/* I N I C I A L I Z A Ç Ã O */

/** @brief Função de Inicialização de um Catálogo de produtos.
*   @return Um novo catálogo de produtos
*/
CatProds initCatProds();

#endif
