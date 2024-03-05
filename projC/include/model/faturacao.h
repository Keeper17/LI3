#ifndef __MOD_FATURACAO__
#define __MOD_FATURACAO__

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "bool.h"
#include "listas.h"

#define MAXBUFSIZE 128
#define LEFT -1
#define BAL 0
#define RIGHT 1

/**
 * @file faturacao.h
 * Funções relacionadas com as informações da faturação.
 *
 */

/**
 * @brief Esta estrutura contém variáveis para armazenar alguns valores das linhas de vendas
 *
 * Esses valores são o preço, a quantidade, o tipo, o mês e a filial
 */
typedef struct fatura *Faturacao;

/**
 * @brief Esta estrutura representa uma AVL, ordenada pelo código do produto
 *
 * Além do código do produto cada nodo contém também uma lista de structs fatura, em que
 * a variável t corresponde ao seu tamanho. A variável bal permite o balanceamento da árvore
 * e left e right são apontadores para os "ramos" da esquerda e direita da árvore
 */
typedef struct avlFaturacao *AVLFat;

/**
 * @brief Esta estrutura representa uma Hash Table de structs avlFaturacao
 *
 * Esta estrutura é inicializada com 26 posições na Hash Table (para cada letra do alfabeto)
 */
typedef struct hashFaturacao *HashTableFat;

/**
 * @brief Calcula a posição da Hash Table hashFaturacao corresponde ao código de produto
 *
 * @param[in] produto O código de produto
 *
 * @return Int correspondente à posição na Hash Table (ou seja à AVL) à qual o código de produto corresponde
 */
int hashF(char* produto);

/**
 * @brief Iniciliza o primeiro elemento de uma lista de structs fatura
 *
 * @param[in] campos Lista de strings contendo a informação de uma linha do ficheiro das vendas
 *
 * @return Faturacao* apontador para uma lista de structs fatura
 */
Faturacao* initFat(char* campos[]);

/**
 * @brief Adiciona uma struct fatura à lista de structs fatura
 *
 * @param[in] f apontador para a lista de structs fatura
 * @param[in] campos Lista de strings contendo a informação de uma linha do ficheiro das vendas
 * @param[in] size posição onde vai adicionar a nova struct fatura
 *
 * @return Faturacao* apontador para uma lista de structs fatura
 */
Faturacao* addFat(Faturacao* f, char* campos[], int size);

/**
 * @brief Muda a posição dos nodos da árvore para que esta fique balanceada
 *
 * @param[in] fat apontador para a struct avlFaturacao
 *
 * @return AVLFat apontador para struct avlFaturacao alterada
 */
AVLFat rotateLeftFat (AVLFat fat);

/**
 * @brief Muda a posição dos nodos da árvore para que esta fique balanceada
 *
 * @param[out] fat apontador para a struct avlFaturacao
 *
 * @return AVLFat apontador para struct avlFaturacao alterada
 */
AVLFat rotateRightFat (AVLFat fat);

/**
 * @brief Verifica o balanceamneto da AVL e corrige se for necessário
 *
 * @param[out] fat apontador para a struct avlFaturacao
 *
 * @return apontador para struct avlFaturacao alterada
 */
AVLFat fixRightFat (AVLFat fat);

/**
 * @brief Verifica o balanceamneto da AVL e corrige se for necessário
 *
 * @param[out] fat apontador para a struct avlFaturacao
 *
 * @return AVLFat apontador para struct avlFaturacao alterada
 */
AVLFat fixLeftFat (AVLFat fat);

/**
 * @brief Insere um novo nodo na estrutura avlFaturacao
 *
 * @param[out] fat apontador para a struct avlFaturacao
 * @param[in] campos Lista de strings contendo a informação de uma linha do ficheiro das vendas
 * @param[in] g apontador para um inteiro
 * @param[in] u apontador para um inteiro
 *
 * @return AVLFat apontador para a struct avlFaturacao com o novo nodo
 */
AVLFat insertFaturaRec(AVLFat fat, char* campos[], int *g, int *u);

/**
 * @brief Define dois inteiros e chama a função insertFaturaRec
 *
 * @param[out] *fat apontador para a struct avlFaturacao
 * @param[in] campos Lista de strings contendo a informação de uma linha do ficheiro das vendas
 *
 * @return AVLFat apontador para a struct avlFaturacao com o novo nodo
 */
AVLFat insertFatura(AVLFat *fat, char* campos[]);

/**
 * @brief Determina a posição na HashTableFat a adicionar o novo elemento
 *
 * @param[out] f apontador para a struct hashFaturacao
 * @param[in] campos Lista de strings contendo a informação de uma linha do ficheiro das vendas
 *
 * @return HashTableFat com o novo elemento adicionado
 */
HashTableFat insertHashTableFat(HashTableFat f, char* campos[]);

/**
 * @brief Inicializa a struct HashTableFat
 *
 * Aloca a memória necessária para a struct HashTableFat (com 26 posições na listaAVLFat)
 * Inicializa cada elemento da listaAVLFat a NULL
 *
 * @return HashTableFat inicializada
 */
HashTableFat initHashTableFat ();

/**
 * @brief Percorre uma struct avlFaturacao e vai armazenando em variáveis o total de vendas e o total faturado
 *
 * @param[in] fat apontador para a struct avlFaturacao
 * @param[in] código do produto
 * @param[in] número do mês
 * @param[out] vals lista onde fica armazenado o total de vendas e o total faturado dos dois tipos
 */
void query3FatAux(AVLFat fat, char* produto, int mes, double vals[]);

/**
 * @brief Calcula a posição da HashTableFat corresponde ao código de produto recebido e chama a função query3FatAux
 *
 * @param[in] fat apontador para a struct hashFaturacao
 * @param[in] código do produto
 * @param[in] número do mês
 * @param[out] vals lista onde fica armazenado o total de vendas e o total faturado dos dois tipos
 */
void query3Fat(HashTableFat fat, char* produto, int mes, double vals[]);

/**
 * @brief Mesmo objetivo que a função query3FatAux mas distinguindo também as 3 filiais para os totais
 *
 * @param[in] fat apontador para a struct avlFaturacao
 * @param[in] código do produto
 * @param[in] número do mês
 * @param[out] fils lista onde ficam armazenados os vários valores pretendidos
 *
 * @see query3fatAux
 */
void query3fatFilAux(AVLFat fat, char* produto, int mes, double fils[]);

/**
 * @brief Mesmo objetivo que a função query3Fat mas distinguindo também as 3 filiais para os totais
 *
 * @param[in] fat apontador para a struct hashFaturacao
 * @param[in] código do produto
 * @param[in] número do mês
 * @param[out] fils lista onde ficam armazenados os vários valores pretendidos
 *
 * @see query3Fat
 */
void query3fatFil(HashTableFat fat, char* produto, int mes, double fils[]);

/**
 * @brief Percorre uma struct avlFaturacao e adicionada a uma struct Array os códigos de produto que ninguém comprou
 *
 * @param[in] f apontador para a struct avlFaturacao
 * @param[out] ar apontador para uma struct arrayGenerico
 * @param[in] fil número da filial
 *
 * @return Array com os códigos de produto que ninguém comprou
 */
Array query4FatAux(AVLFat f, Array ar, int fil);

/**
 * @brief Percorre a listaAVLFat presente na struct HashTableFat e chama a função query4FatAux
 *
 * @param[in] f apontador para a struct hashFaturacao
 * @param[out] ar apontador para uma struct arrayGenerico
 * @param[in] fil número da filial
 *
 * @return Array com os códigos de produto que ninguém comprou
 */
Array query4Fat(HashTableFat f, Array ar, int fil);

/**
 * @brief Percorre uma struct avlFaturacao e armazena em variáveis o total de vendas e o total faturado num intervalo de meses
 *
 * @param[in] fat apontador para a struct avlFaturacao
 * @param[in] mesI mes inicial do intervalo
 * @param[in] mesF mes final do intervalo
 * @param[out] vendas apontador para um inteiro onde fica armazenado o total de vendas
 * @param[out] totalFat apontador para um double onde fica armazenado o total faturado
 */
void query8FatAux(AVLFat fat, int mesI, int mesF, int* vendas, double* totalFat);

/**
 * @brief Percorre a listaAVLFat presente na struct HashTableFat e chama a função query8FatAux
 *
 * @param[in] fat apontador para a struct hashFaturacao
 * @param[in] mesI mes inicial do intervalo
 * @param[in] mesF mes final do intervalo
 * @param[out] vendas apontador para um inteiro onde fica armazenado o total de vendas
 * @param[out] totalFat apontador para um double onde fica armazenado o total faturado
 */
void query8Fat(HashTableFat fat, int mesI, int mesF, int* vendas, double* totalFat);

/**
 * @brief Percorre uma struct avlFaturacao e adiciona a uma struct Array2 um código de produto e quantas vezes esse produto foi vendido
 *
 * @param[in] fat apontador para a struct avlFaturacao
 * @param[out] array apontador para a struct arrayGenerico2
 *
 * @return Array2 com os códigos de produto dessa AVLFat e correspondente número a indicar quantas vezes foi vendido
 */
Array2 query11FatAux(AVLFat fat, Array2 array);

/**
 * @brief Percorre a listaAVLFat presente na struct HashTableFat e chama a função query11FatAux
 *
 * @param[in] fat apontador para a struct hashFaturacao
 * @param[out] array apontador para a struct arrayGenerico2
 *
 * @return Array2 com todos os códigos de produto e correspondente número a indicar quantas vezes foi vendido
 */
Array2 query11Fat(HashTableFat fat, Array2 array);

/**
 * @brief Função que liberta o espaço das estruturas fatura de um nodo da AVLFat.
 *
 * @param[in] fat árvore cuja memória vamos libertar
 * @param[in] número de estruturas do tipo fatura presentes no nodo cuja memória vai ser libertada
 */
void freeFatura(AVLFat fat, int t);
/**
 * @brief Função que liberta o espaço em memória de uma árvore AVLFat
 *
 * @param[in] fat árvore cuja memória vamos libertar
 */
void freeAVLFat(AVLFat fat);
/**
 * @brief Função que liberta o espaço em memória da estrutura HashTableFat
 *
 * @param[in] fat estrutura HashTableFat cuja memória vamos libertar
 */
void freeFatHash(HashTableFat fat);

#endif
