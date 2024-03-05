#ifndef __MOD_VIEW__
#define __MOD_VIEW__

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <ctype.h>
#include "../model/listas.h"

/**
 * @file view.h
 * Funções relacionadas com o output para o Utilizador.
 *
 */

/**
 * @brief Obtem a largura do Terminal.
 * @return largura do Terminal.
 */
int getBashWidth();

/**
 * @brief Obtem a altura do Terminal.
 * @return altura do Terminal.
 */
int getBashHeight();

/**
 * @brief Print para erros genéricos.
 */
void printErro();

/**
 * @brief Print do menu principal.
 */
void printMenu();

/*Query1*/
/**
 * @brief Pergunta se quer abrir os ficheiros default ou outros.
 */
void printQ1A();

/**
 * @brief Pede os novos ficheiros a ler.
 */
void printQ1B();

/**
 * @brief Informa que os ficheiros foram lidos com sucesso.
 */
void printQ1C();

/**
 * @brief Informa que está a abrir os ficheiros default.
 */
void printQ1Def();

/*Query 2*/
/**
 * @brief Pede para inserir uma letra.
 */
void printQ2A();

/**
 * @brief Faz print do total de elementos no array, e das opções para navegar na lista.
 * @param[in] produtos Lista com os codigos a imprimir.
 * @param[in] size Tamanho total da lista.
 * @param[in] start  Posição onde começa a impressão do array visível.
 * @param[in] end Posição onde acaba a impressão do array visível.
 */
void printQ2B(char** produtos, int size, int start, int end);

/*Query 3*/
/**
 * @brief Pede para inserir um mês.
 */
void printQ3A();

/**
 * @brief Pede para inserir um código de produto .
 */
void printQ3B();

/**
 * @brief Pergunta se quer resultado global ou por filial.
 */
void printQ3C();

/**
 * @brief Imprime a informação sobre o produto numa filial.
 * @param[in] vals Array de inteiros com os totais de vendas e o total faturado.
 */
void printR3(double vals[]);

/**
 * @brief Imprime a informação sobre o produto de forma global.
 * @param[in] fils Array de inteiros com os totais de vendas e total faturado em cada filial.
 */
void printR4(double fils[]);

/*Query 4*/
/**
 * @brief Pergunta qual a filial a analisar.
 */
void printQ4();

/*Query 6*/
/**
 * @brief Imprime o total de clientes e de produtos.
 * @param[in] sp Número total de produtos.
 * @param[in] sc Número total de clientes.
 */
void printQ6(int sp, int sc);

/*Query 7*/
/**
 * @brief Pede para inserir um codigo de cliente.
 */
void printQ7();

/**
 * @brief Imprime a informação sobre as compras efetuadas pelo cliente.
 * @param[in] f Array de inteiros com os dados organizados por mês e filial.
 */
void printQ7R(int *f);

/**
 * @brief Print para voltar ao menu inicial.
 */
void printQ7F();

/*Query 8*/
/**
 * @brief Pede para inserir o mês de inicio do intervalo.
 */
void printQ8A();

/**
 * @brief Pede para inserir o mês de fim do intervalo.
 */
void printQ8B();

/**
 * @brief Imprime a informação sobre as vendas e total faturado no intervalo.
 * @param[in] mesI Mês de inicio do intervalo.
 * @param[in] mesF Mês de fim do intervalo.
 * @param[in] vendas Total de vendas do intervalo.
 * @param[in] totalFat Total faturado no intervalo.
 */
void print8R(int mesI, int mesF, int vendas, double totalFat);

/*Query 9*/
/**
 * @brief Pede para inserir um codigo de produto.
 */
void printQ9C();

/**
 * @brief Pede para inserir a filial a analisar.
 */
void printQ9F();

/**
 * @brief Imprime o total de vendas de um dado produto, bem como os clientes que a efetuaram, diferenciado N de P.
 * @param[in] tN Número total de vendas N.
 * @param[in] tP Número total de vendas P.
 * @param[in] cN Lista dos clientes que compraram o produto em N.
 * @param[in] cP Lista dos clientes que compraram o produto em P.
 */
void printQ9R(int tN, int tP, char** cN, char** cP);

/*Query 10*/
/**
 * @brief Pede para inserir um codigo de cliente.
 */
void printQ10A();

/**
 * @brief Pede para inserir um mês.
 */
void printQ10B();

/**
 * @brief Faz print do total de elementos no array, e das opções para navegar na lista.
 * @param[in] produtos Lista com os codigos a imprimir.
 * @param[in] quants Quantidades dos produtos comprados.
 * @param[in] size Tamanho total da lista.
 * @param[in] start  Posição onde começa a impressão do array visível.
 * @param[in] end Posição onde acaba a impressão do array visível.
 */
void printQ10C(char** produtos, int* quants, int size, int start, int end);

/*Query 11*/
/**
 * @brief Pede para inserir quantos produtos dos mais vendidos quer ver.
 */
void printQ11();

/**
 * @brief Print inicial dos produtos mais vendidos.
 * @param[in] tam Número de produtos a imprimir.
 */
void print11R(int tam);

/**
 * @brief Imprime os produtos mais vendidos, bem como o total de clientes que o compraram e as unidades vendidas, filial a filial.
  * @param[in] produtos Lista dos produtos mais vendidos.
  * @param[in] arrayFil1 Array com a informação referente ao produto na filial 1.
  * @param[in] arrayFil2 Array com a informação referente ao produto na filial 2.
  * @param[in] arrayFil3 Array com a informação referente ao produto na filial 3.
  * @param[in] size Tamanho total da lista.
  * @param[in] start Posição onde começa a impressão do array visível.
  * @param[in] end Posição onde acaba a impressão do array visível.
 */
void print11RB(char** produtos, int** arrayFil1, int** arrayFil2, int** arrayFil3, int size, int start, int end);

/*Query 12*/
/**
 * @brief Pede para inserir quantos produtos dos mais vendidos de um cliente quer ver.
 */
void printQ12A();

/**
 * @brief Faz print do total de elementos no array, e das opções para navegar na lista.
 * @param[in] produtos Lista dos produtos em que o cliente gastou mais.
 * @param[in] fats Valor gasto no respetivo produto.
 * @param[in] size Tamanho total da lista.
 * @param[in] start Posição onde começa a impressão do array visível.
 * @param[in] end Posição onde acaba a impressão do array visível.
 */
 void printQ12(char** produtos, float* fats, int size, int start, int end);

/*Query 13*/
/**
 * @brief Faz print das estatisticas totais dos ficheiros lidos.
 * @param[in] tp Total de produtos.
 * @param[in] tc Total de clientes.
 * @param[in] tv Total de vendas.
 * @param[in] vc Total de clientes válidos.
 * @param[in] vv Total de vendas válidas
 * @param[in] p1 Nome do ficheiro de produtos lido.
 * @param[in] p2 Nome do ficheiro de clientes lido.
 * @param[in] p3 Nome do ficheiro de vendas lido.
 */
void printQ13(int tp, int tc, int tv, int vp, int vc, int vv, char* p1, char* p2, char *p3);
/**
 * @brief Informa que o SGV não está inicializado.
 */
 void printAviso();

#endif
