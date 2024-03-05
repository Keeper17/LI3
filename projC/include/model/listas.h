#ifndef __MOD_LISTAS__
#define __MOD_LISTAS__

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bool.h"

#define BAL 0
#define ESQ -1
#define DIR 1

/**
 * @file listas.h
 * Funções e estruturas para guardar informações para as queries.
 *
 */

/** @brief Estrutura de dados que guarda um array de strings e o seu tamanho*/
typedef struct arrayGenerico* Array;
/** @brief Estrutura que guarda um array de strings e um de inteiros de tamanhos iguais, juntamente com os seus tamanho.*/
typedef struct arrayGenerico2* Array2;
/** @brief Estrutura que guarda um array de strings e um de reais de tamanhos iguais, juntamente com os seus tamanho.*/
typedef struct arrayGenerico3* Array3;
/** @brief Estrutura que guarda um array de strings e 3 matrizes de inteiros (com 2 linhas), juntamente com os seus tamnhos.*/
typedef struct arrayGenerico4* Array4;
/** @brief AVL com um string e um inteiro em cada nodo, utilizada para ordenação. */
typedef struct avl* AVL;
/** @brief AVL com um string e um real em cada nodo, utilizada para ordenação.*/
typedef struct avlF* AVLF;
/** @brief Estrutura que representa um par de inteiros.*/
typedef struct pair* Pair;
/** @brief Estrutura que representa um par cujo primeiro elemento é um inteiro e o segundo um double.*/
typedef struct pair2* Pair2;
/** @brief Estrutura que guarda 2 arrays de strings juntamente com os seus tamanhos*/
typedef struct codsNP* Cods;

/* A R R A Y */

/** @brief Função de inicialização da estrutura Array
* @return Um apontador para Array inicializado.
*/
Array initArray();
/** @brief Função de inserção de uma string no Array.
* @param[out] a Array onde vamos fazer a inserção.
* @param[in] c String a ser inserida.
*/
Array addToArray(Array a, char* c);
/** @brief Função de libertação da memória de um apontador para Array.
* @param[in] a Apontador Array a libertar.
*/
void freeArray(Array a);
/** @brief Getter do atributo array.
* @param[in] a Array cujo atirbuto array queremos obter.
* @return atributo array.
*/
char** getArray(Array a);
/** @brief Getter do atributo tam.
* @param[in] a Array cujo atirbuto tam queremos obter.
* @return atributo tam.
*/
int getTam(Array a);

/* A R R A Y 2 */

/** @brief Função de inicialização da estrutura Array2
* @return Um apontador para Array2 inicializado.
*/
Array2 initArray2();
/** @brief Função para verificar se uma dada string já existe no atributo arrayC. Se existir, devolve a posição do mesmo, caso contrário devolve -1.
* @param[in] s Array2 onde vamos procurar.
* @param[in] string String cuja existência vamos verificar.
* @return Inteiro que nos diz a posição onde a string foi encontrada, ou -1 caso não seja.
*/
int existeString(Array2 s, char* string);
/** @brief Função de inserção de uma string no Array2, bem como do seu valor.
* @param[out] a Array2 onde vamos fazer a inserção.
* @param[in] c String a ser inserida.
* @param[in] q Valor a ser inserido.
*/
Array2 simpleAddToArray2(Array2 a, char* c, int q);
/** @brief Função de inserção de uma string no Array2, bem como do seu valor. Caso ela já exista, em vez de ser adicionada apenas é somado o novo valor ao antigo.
* @param[out] a Array2 onde vamos fazer a inserção.
* @param[in] c String a ser inserida ou atulizada.
* @param[in] q Valor a ser inserido.
*/
Array2 addToArray2(Array2 a, char* c, int q);
/** @brief Getter do atributo arrayC.
* @param[in] a Array2 cujo atirbuto arrayC queremos obter.
* @return atributo arrayC.
*/
char** getArray2C(Array2 a);
/** @brief Getter do atributo arrayI.
* @param[in] a Array2 cujo atirbuto arrayI queremos obter.
* @return atributo arrayI.
*/
int* getArray2I(Array2 a);
/** @brief Getter do atributo tam.
* @param[in] a Array2 cujo atirbuto tam queremos obter.
* @return atributo tam.
*/
int getTam2(Array2 a);
/** @brief Função de libertação da memória de um apontador para Array2.
* @param[in] a Apontador Array2 a libertar.
*/
void freeArray2(Array2 a);
/** @brief Função de libertação de uma porção de memória do Array2.
* @param[in] a Apontador Array2 a libertar.
* @param[in] tam Tamanho com que o arrayC e arrayI ficarão depois da libertação da memória.
*/
Array2 freeArray2Tam(Array2 a, int tam);
/** @brief Função de ordenação do Array2 por ordem decrescente, utilizando uma AVL.
* @param[out] ar Array2 a ser ordenado.
*/
Array2 sortArray2Dec(Array2 ar);

/* A R R A Y 3 */

/** @brief Função de inicialização da estrutura Array3
* @return Um apontador para Array3 inicializado.
*/
Array3 initArray3();
/** @brief Função para verificar se uma dada string já existe no atributo arrayC. Se existir, devolve a posição do mesmo, caso contrário devolve -1.
* @param[in] s Array3 onde vamos procurar.
* @param[in] string String cuja existência vamos verificar.
* @return Inteiro que nos diz a posição onde a string foi encontrada, ou -1 caso não seja.
*/
int existeString3(Array3 s, char* string);
/** @brief Função de inserção de uma string no Array3, bem como do seu valor.
* @param[out] a Array3 onde vamos fazer a inserção.
* @param[in] c String a ser inserida.
* @param[in] q Valor a ser inserido.
*/
Array3 simpleAddToArray3(Array3 a, char* c, float q);
/** @brief Função de inserção de uma string no Array3, bem como do seu valor. Caso ela já exista, em vez de ser adicionada apenas é somado o novo valor ao antigo.
* @param[out] a Array3 onde vamos fazer a inserção.
* @param[in] c String a ser inserida ou atulizada.
* @param[in] q Valor a ser inserido.
*/
Array3 addToArray3(Array3 a, char* c, float q);
/** @brief Getter do atributo arrayC.
* @param[in] a Array3 cujo atributo arrayC queremos obter.
* @return atributo arrayC.
*/
char** getArray3C(Array3 a);
/** @brief Getter do atributo arrayR.
* @param[in] a Array3 cujo atirbuto arrayR queremos obter.
* @return atributo arrayR.
*/
float* getArray3R(Array3 a);
/** @brief Getter do atributo tam.
* @param[in] a Array3 cujo atirbuto tam queremos obter.
* @return atributo tam.
*/
int getTam3(Array3 a);
/** @brief Função de libertação da memória de um apontador para Array3.
* @param[in] a Apontador Array3 a libertar.
*/
void freeArray3(Array3 a);
/** @brief Função de libertação de uma porção de memória do Array3.
* @param[in] a Apontador Array3 a libertar.
* @param[in] tam Tamanho com que o arrayC e arrayR ficarão depois da libertação da memória.
*/
Array3 freeArray3Tam(Array3 a, int tam);
/** @brief Função de ordenação do Array2 por ordem decrescente, utilizando uma AVLF.
* @param[out] ar Array3 a ser ordenado.
*/
Array3 sortArray3Dec(Array3 ar);

/* A R R A Y 4 */

/** @brief Função de inicialização da estrutura Array4
 * @param[in] tamanho tamanho que as listas presentes nesta estrutura vão ter
 * @return Um apontador para Array4 inicializado.
 */
Array4 initArray4(int tamanho);
/** @brief Função para preencher a lista arrayC da estrutura Array4 com os valores da lista também arrayC da estrutura Array2 passada como argumento.
 * @param[out] ar apontador para uma estrutura Array4
 * @param[in] array apontador para uma estrutura Array2
 * @return Array4 apontador para a estrutura Array4 passada como argumento com as alterações descritas.
 */
Array4 preencheProdutosArray4(Array4 ar, Array2 array);
/** @brief Função que verifica se um código de produto existe numa dada posição da lista arrayC da estrutura Array4 passada como argumento
 * @param[in] ar apontador para uma estrutura Array4
 * @param[in] prod código do produto a verificar se existe
 * @param[in] pos posição na lista arrayC da estrutura Array4 que o produto tem de existir
 * return bool se existe ou não
 */
bool verificaProdArray4(Array4 ar, char* prod, int pos);
/** @brief Função que incrementa por 1 a linha 0 e a coluna recebida como argumento de uma das matrizes da estrutura Array4 (dependente da filial)
 * @param[in] ar apontador para uma estrutura Array4
 * @param[in] pos coluna da matriz no qual a linha 0 vai ser incrementada por 1
 * @param[in] fil filial que indica qual das 3 matrizes (uma para cada filial) é que se vai modificar
 * @return Array4 apontador para a estrutura Array4 passada como argumento com as alterações descritas.
 */
Array4 adicionaCliFil(Array4 ar, int pos, int fil);
/** @brief Função que incrementa pela quantidade a linha 1 e a coluna recebida como argumento de uma das matrizes da estrutura Array4 (dependente da filial)
 * @param[in] ar apontador para uma estrutura Array4
 * @param[in] qtd quantidade a incrementar na posição da matriz
 * @param[in] pos coluna da matriz no qual a linha 1 vai ser incrementada
 * @param[in] fil filial que indica qual das 3 matrizes (uma para cada filial) é que se vai modificar
 * @return Array4 apontador para a estrutura Array4 passada como argumento com as alterações descritas.
 */
Array4 adicionaQntFil(Array4 ar, int qnt, int pos, int fil);
/** @brief Getter do atributo arrayC.
 * @param[in] a Array4 cujo atributo arrayC queremos obter.
 * @return atributo arrayC.
 */
char** getArray4C(Array4 a);
/** @brief Getter do atributo arrayFil1, arrayFil2 ou arrayFil3.
 * @param[in] a Array4 cujo atributo arrayFil 1, 2 ou 3 queremos obter.
 * @param[in] fil filial que indica a matriz a obter
 * @return atributo arrayFil 1, 2 ou 3.
 */
int** getArray4Fil(Array4 a, int fil);
/** @brief Getter do atributo tam.
* @param[in] a Array4 cujo atirbuto tam queremos obter.
* @return atributo tam.
*/
int getTam4(Array4 a);
/** @brief Função de libertação da memória de um apontador para Array4.
* @param[in] a Apontador Array4 a libertar.
*/
void freeArray4(Array4 a);

/* P A I R */

/** @brief Função de inicialização de um Pair.
* @param[in] x Atributo x do pair.
* @param[in] y Atrbuito y do pair.
* @return Um apontador para Pair, com os valores de x e y passados.
*/
Pair initPair(int x, int y);
/** @brief Getter para o atributo x.
* @param[in] p Pair de onde vamos fazer get.
* @return O atributo x de P.
*/
int getX(Pair p);
/** @brief Getter para o atributo y.
* @param[in] p Pair de onde vamos fazer get.
* @return O atributo y de P.
*/
int getY(Pair p);
/** @brief Função para libertação de memória de uma estrutura Pair.
* @param[in] p Pair cuja memória vamos libertar.
*/
void freePair(Pair p);

/* P A I R 2 */

/** @brief Função de inicialização da estrutura Pair2
 * @param[in] x Atributo x do Pair2
 * @param[in] y Atributo y do Pair2
 * @return Pair2 Um apontador para pair2, com os valores de x e y passados como argumento
 */
Pair2 initPair2(int x, double y);
/** @brief Getter para o atributo x.
 * @param[in] p Pair2 onde vamos obter o parâmetro x.
 * @return int O atributo x de p.
 */
int getX2(Pair2 p);
/** @brief Getter para o atributo y.
 * @param[in] p Pair2 onde vamos obter o parâmetro y.
 * @return double O atributo y de p.
 */
double getY2(Pair2 p);
/** @brief Função para libertação de memória de uma estrutura Pair2.
* @param[in] p Pair2 cuja memória vamos libertar.
*/
void freePair2(Pair2 p);

/** @brief Função de inicialização de um Cods.
  * @return Um apontador para Cods
  */
Cods initCods();
/** @brief Função que insere um char* à componente codsN da estrutura Cods.
  * @param[out] c Estrutura onde queremos adicionar o char*.
  * @param[in] cod Código a adicionar a CodsN.
  */
Cods addToCodsN(Cods c, char* cod);
/** @brief Função que insere um char* à componente codsP da estrutura Cods.
  * @param[out] c Estrutura onde queremos adicionar o char*.
  * @param[in] cod Código a adicionar a CodsP.
  */
Cods addToCodsP(Cods c, char* cod);
/** @brief Getter para a lista codsN.
 * @param[in] c Cods de onde vamos fazer get.
 * @return Lista CodsN.
 */
char** getCodsN(Cods c);
/** @brief Getter para a lista codsP.
 * @param[in] c Cods de onde vamos fazer get.
 * @return Lista CodsP.
 */
char** getCodsP(Cods c);
/** @brief Getter para o tamanho da lista codsN.
 * @param[in] c Cods de onde vamos fazer get.
 * @return Tamanho da lista.
 */
int getN(Cods c);
/** @brief Getter para o tamanho da lista codsP.
 * @param[in] c Cods de onde vamos fazer get.
 * @return Tamanho da lista .
 */
int getP(Cods c);
/** @brief Função para libertação de memória de uma estrutura Cods.
* @param[in] c Cods cuja memória vamos libertar.
*/
void freeCods(Cods c);

#endif
