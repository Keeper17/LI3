#ifndef __MOD_FILIAL__
#define __MOD_FILIAL__

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
 * @file filial.h
 * Funções relacionadas com as informações das filiais.
 *
 */

/**
 * @brief Esta estrutura contém referentes às vendas efetuadas pelo Cliente.
 * Esses valores são o código do produto, a quantidade, o preço, o mês da venda e o seu tipo.
 */
typedef struct info *Fil;

/**
 * @brief Esta estrutura representa uma AVL, ordenada pelo código do cliente.
 * Para além disto, cada nodo contem uma lista de informações referentes ao cliente
 * e o seu tamanho, bem como os apontadores para os outros ramos, e uma variavel bal.
 */
typedef struct avlFilial *AVLFil;

/**
 * @brief Esta estrutura representa uma Hash Table de structs avlFilial.
 * Esta estrutura é inicializada com 78 posições na Hash Table, representando as
 * 26 letras do alfabeto e as 3 filiais
 */
typedef struct filiais *FilHash;

/*-------------------------------------------------------------------------------------------------*/

/**
 * @brief Iniciliza o primeiro elemento de uma lista de structs info.
 * @param[in] campos Lista de strings contendo a informação de uma linha do ficheiro das vendas.
 * @return Fil* apontador para uma lista de structs info.
 */
Fil* initFil ( char* campos[]);

/**
 * @brief Adiciona uma informação à struct.
 * @param[in] campos Lista de strings contendo a informação de uma linha do ficheiro das vendas.
 * @return Fil* apontador para uma lista de structs info.
 */
Fil* addInfo(Fil* f, char* campos[], int size);

/**
 * @brief Insere um novo nodo na árvore.
 * @param[out] f AVL com a informação.
 * @param[in] campos Lista de strings contendo a informação de uma linha do ficheiro das vendas.
 */
AVLFil insertFil(AVLFil *f, char* campos[]);

/**
 * @brief Chama a insertFil para a AVL correta.
 * @param[in] campos Lista de strings contendo a informação de uma linha do ficheiro das vendas.
 * @param[out] f Estrutura onde está guardada toda a informação das filiais.
 */
FilHash insertFilHash(FilHash f, char* campos[]);

/**
 * @brief Inicializa a estrutura principal das filiais.
 * @return f Estrutura inicializada.
 */
FilHash initFilHash();

/** @brief Função de travessia para a query 5. Esta percorre uma AVL, procurando codigos iguais ao recebido.
 *  @param[in] avl A AVL que vamos percorrer.
 *  @param[in] cod Codigo do cliente que vamos procurar.
 *  @return bool Indica se o codigo se encontra na AVL.
 */
bool pertenceFil(AVLFil a, char* cod);

/** @brief Chama a função pertenceFil para um codigo nas três filiais.
 *  @param[in] fil Estrutura onde esta a informação das filiais.
 *  @param[in] cod Codigo do cliente que vamos procurar.
 *  @return bool Indica se o codigo se encontra nas três filiais.
 */
bool query5Aux(FilHash fil, char* cod);

/** @brief Função que chama a pertenceFil, percorrendo um array com todos os clientes que efetuaram compras.
 *  @param[in] fil Estrutura onde esta a informação das filiais.
 *  @param[in] ar Array com os codigos dos clientes que efetuaram compras.
 *  @param[in] res Estrutura onde iremos guardar os codigos dos clientes que compraram nas três filiais.
 */
void query5Fil(FilHash fil, char** ar, int c, Array res);

/** @brief Função que percorre uma arvore, adicionando ao array a quantidade comprada em cada mês por um Cliente.
 *  @param[out] a Array de inteiros onde guardamos a informação das compras.
 *  @param[in] fil AVLFil que vamos percorrer.
 *  @param[in] c codigo do Cliente a procurar.
 *  @param[in] nf Número da filial onde está a procurar.
 */
int* filFil(int* a, AVLFil fil, char* c, int nf);

/** @brief Função que chama a filFil para todas as árvores do codigo recebido.
 *  @param[in] f Array de inteiros onde vamos guardar a informação.
 *  @param[in] fil Estrutura onde esta a informação das filiais.
 *  @param[in] cod Codigo do cliente que vamos procurar.
 */
void query7Fil(int* f,FilHash fil,char* cod);

/** @brief Função auxiliar que percorre uma AVL, adicionando o codigo do cliente à estrutura caso este tenha comprado o produto.
 *  @param[in] avl Estrutura onde esta a informação da filial.
 *  @param[in] codP Codigo do produto que vamos procurar.
 *  @param[in] N Estrutura usada para guardar os codigos dos clientes, diferenciando coompras N de P.
 */
void query9Aux(AVLFil avl, char* codP, Cods N);

/** @brief Função que chama a query7Fil, percorrendo todas as AVLs correspondentes á filial inserida.
 *  @param[in] f Número da filial onde se vai procurar.
 *  @param[in] codP Codigo do Produto a procurar.
 *  @param[in] fil Estrutura com a informação de todas as filiais.
 *  @param[in] N Estrutura usada para guardar os codigos dos clientes, diferenciando coompras N de P.
 */
void query9F(int f, char* codP, FilHash fil, Cods N);

/** @brief Função de travessia para a query 10. Esta percorre uma AVL, adicionando todos os produtos de um cliente ao
 *  Array, caso estes tenham sido comprados no mês dado.
 *  @param[out] ar Array2 onde vamos colocar a informação, e que vamos devolver.
 *  @param[in] avl A AVL que vamos percorrer.
 *  @param[in] m Mês em que vamos procurar.
 *  @param[in] cliente Código de cliente a procurar.
 */
Array2 query10FilAux(Array2 ar, AVLFil avl, int mes, char* cliente);

/** @brief Função de travessia para a query 10. Esta percorre um FilHash, para obter a informação necessária.
 *  @param[out] ar Array2 onde vamos colocar a informação, e que vamos devolver.
 *  @param[in] f A FilHash que vamos percorrer.
 *  @param[in] m Mês em que vamos procurar.
 *  @param[in] cliente Código de cliente a procurar.
 */
Array2 query10Fil(Array2 ar, FilHash f, int mes, char* cliente);

/** @brief Função de travessia para a query 11. Esta percorre uma AVL, para obter a informação necessária.
 *  @param[in] avl A AVL que vamos percorrer.
 *  @param[out] ar Array4 onde vamos colocar a informação, e que vamos devolver.
 *  @param[in] tamanho Tamanho pretendido para o Array4.
 *  @param[in] fil Número da filial em que está a procurar.
 */
Array4 query11FilAux(AVLFil avl, Array4 ar, int tamanho, int fil);

/** @brief Função de travessia para a query 11. Esta percorre um FilHash, para obter a informação necessária.
 *  @param[out] ar Array4 onde vamos colocar a informação, e que vamos devolver.
 *  @param[in] f FilHash que vamos percorrer.
 *  @param[in] tamanho Tamanho pretendido para o Array4.
 */
Array4 query11Fil(FilHash f, Array4 ar, int tamanho);

/** @brief Função de travessia para a query 12. Esta percorre uma AVL, adicionando todos os produtos de um cliente ao
 * Array, juntamente com o dinheiro gasto neles.
 *  @param[out] ar Array3 onde vamos colocar a informação, e que vamos devolver.
 *  @param[in] avl A AVL que vamos percorrer.
 *  @param[in] cliente Código de cliente a procurar.
 */
Array3 query12FilAux(Array3 ar, AVLFil avl, char* cliente);

/** @brief Função de travessia para a query 12. Esta percorre um FilHash, para obter a informação necessária.
 *  @param[out] ar Array3 onde vamos colocar a informação, e que vamos devolver.
 *  @param[in] f A FilHash que vamos percorrer.
 *  @param[in] cliente Código de cliente a procurar.
 */
Array3 query12Fil(Array3 ar, FilHash f, char* cliente);

/** @brief Função que liberta o espaço das infos de um nodo da AVLFil.
 *  @param[in] fil AVL com as infos que queremos dar free.
 *  @param[in] t Número de infos presentes no nodo.
 */
void freeInfo(AVLFil fil,int t);
/** @brief Função que liberta o espaço de uma AVLFil
 *  @param[in] avlF Árvore que queremos dar free.
 */
void freeAVLFil(AVLFil avlF);
/** @brief Função que liberta o espaço da FilHash.
 *  @param[in] f FilHash que queremos dar free.
 */
void freeFilHash(FilHash f);
#endif
