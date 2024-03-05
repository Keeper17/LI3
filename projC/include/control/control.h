#ifndef __MOD_CONTROL__
#define __MOD_CONTROL__

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../model/listas.h"
#include "../model/produtos.h"
#include "../model/clientes.h"
#include "../model/filial.h"
#include "../model/faturacao.h"
#include "../view/view.h"

/**
 * @file control.h
 * Funções relacionadas com o SGV, queries e manipulação do input do utilizador.
 *
 */

/** @brief Estrutura auxiliar no programa, onde guardamos a informação dos Clientes, Produtos, Filiais, Faturação e ficheiros de leitura.*/
typedef struct sgv *SGV;
/** @brief Estrutura auxiliar ao struct sgv onde guardamos a informação dos ficheiros lidos.*/
typedef struct fileInfo *FI;

/** @brief Função de inicialição da estrutura SGV
* @return SGV inicializado.
*/
SGV initSGV();
/** @brief Função de libertação de memória da estrutura SGV.
* @param[in] gestor SGV a ser libertado.
*/
void destroySGV(SGV gestor);

/*Interface pedida*/

/** @brief (1) Função de preenchimento da estrutura SGV a partir dos ficheiros dados.
* @param[out] gestor SGV a ser preenchido.
* @param[in] clientes Path do ficheiro com a informação dos clientes.
* @param[in] produtos Path do ficheiro com a informação dos produtos.
* @param[in] vendas Path do ficheiro com a informação das vendas.
*/
SGV loadSGVFromFiles(SGV gestor, char* clientes, char* produtos, char* vendas);
/** @brief (2) Função para obter a lista dos produtos começados por uma dada letra.
* @param[in] sgv SGV com a informação dos produtos.
* @param[in] letter Letra inicial dos produtos que queremos encontrar.
* @return Estrutura Array com todos os produtos começados pela letra dada.
*/
Array getProductStartedByLetter(SGV sgv, char letter);
/** @brief (3) Função para obter onúmero total de vendas e o total faturado com um produto num dado mês
 * @param[in] sgv SGV com a informação dos Produtos
 * @param[in] productID onde está o código do produto
 * @param[in] month número do mês
 * @return sgv
 */
SGV getProductSalesAndProfit(SGV sgv, char* productID, int month);
/** @brief (4) Função para obter a lista dos produtos nunca comprados numa dada filial.
* @param[in] sgv SGV onde está guardada a informação dos produtos.
* @param[in] branchID Filial onde vamos procurar os produtos.
* @return Estrutura Array com a lista dos produtos procurados.
*/
Array getProductsNeverBought(SGV sgv, int branchID);
/** @brief (5) Função para obter a lista dos clientes que compraram em todas as filiais.
* @param[in] sgv SGV onde está guardada a informação dos clientes.
* @return Estrutura Array com a lista dos clientes encontrados.
*/
Array getClientsOfAllBranches(SGV sgv);
/** @brief (6) Função para obter o número de Clientes que nunca compraram e Produtos nunca vendidos.
* @param[in] sgv SGV onde a informação que queremos percorrer está guardada.
* @return Estrutura Pair contendo os dois números procurados.
*/
Pair getClientsAndProductsNeverBoughtCount(SGV sgv);
/** @brief (7) Função para obter a quantidade de produtos comprados pelo cliente mês a mês.
* @param[in] sgv SGV onde está guardada a informação das filiais.
* @return Array com as compras efetuadas em cada mês e em cada filial.
*/
int* getProductsBoughtByClient(SGV sgv, char* clientID);
/** @brief (8) Função para obter o total de vendas e o total faturado num intervalo de meses
 * @param[in] sgv SGV onde está guardada a informação do módulo Faturaçãonce
 * @param[in] minMonth mês de início do intervalo
 * @param[in] maxMonth mês de fim do intervalo
 * @return Pair2 estrutura onde fica guardado um inteiro e um double
 */
Pair2 getSalesAndProfit(SGV sgv, int minMonth, int maxMonth);
/** @brief (9) Função para obter os codigos dos clientes que compraram dado produto.
* @param[in] sgv SGV onde está guardada a informação das filiais.
* @param[in] productID Código do produto a procurar.
* @param[in] branch Número da filial onde se vai procurar.
* @return Estrutura Cods que contem as listas dos clientes que compraram o produto, bem como os seus tamanhos.
*/
Cods getProductBuyers (SGV sgv, char* productID, int branch);
/** @brief (10) Função para obter os produtos mais comprados por um cliente num dado mês.
* @param[in] sgv SGV onde a informação está guardada.
* @param[in] clientID Código do cliente a procurar.
* @param[in] month Mês que queremos verificar.
* @return Estrutura Array2 com os códigos dos N produtos mais comprados e respetivo número de compras.
*/
Array2 getClientFavoriteProducts(SGV sgv, char* clientID, int month);
/** @brief (11) Função para obter uma lista dos N produtos mais vendidos, indicando o total de cliente e unidades vendidaas, filial a filial.
 * @param[in] sgv SGV onde estão as estruturas que vamos ter de percorrer (faturação e filiais).
 * @param[in] limit número de produtos mais vendidos a mostrar ao Utilizador.
 * @return Array4 estrutura onde estão armazenados todos os dados necessários a apresentar.
 */
Array4 getTopSelledProducts(SGV sgv, int limit);
/** @brief (12) Função para obter os N produtos em que um dado cliente gastou mais dinheiro.
* @param[in] sgv SGV onde está guardada a informação.
* @param[in] clientID Código de cliente a procurar.
* @param[in] limit O número máximo de produtos que queremos encontrar.
* @return Estrutura Array3 com os N produtos em que gastou mais dinheiro e o total gasto em cada um.
*/
Array3 getClientTopProfitProducts(SGV sgv, char* clientID, int limit);
/** @brief (13) Função para obter a informação dos ficheiros lidos.
* @param[in] sgv SGV onde está guardada a informação dos ficheiros.
* @return Estrutura com a informação dos ficheiros.
*/
FI getCurrentFilesInfo(SGV sgv);

/** @brief Função para preencher o Catálogo de Produtos de um SGV.
* @param[out] gestor SGV a preencher.
* @param[in] pathProds Path para o ficheiro com a informação dos produtos.
*/
SGV lerProdutos(SGV gestor, char*pathProds);
/** @brief Função para preencher o Catálogo de Clientes de um SGV.
* @param[out] gestor SGV a preencher.
* @param[in] pathClientes Path para o ficheiro com a informação dos clientes.
*/
SGV lerClientes(SGV gestor, char* pathClientes);
/** @brief Função para preencher as Filiais e Faturação de um SGV.
* @param[out] gestor SGV a preencher.
* @param[in] pathVendas Path para o ficheiro com a informação das vendas.
*/
SGV lerVendas(SGV gestor, char* pathVendas);

/** @brief chamada da query 1, que trata do input do utilizador.
* @param[out] gestor SGV que vai ser tratado.
*/
SGV query1(SGV gestor);
/** @brief chamada da query 2, que trata do input do utilizador.
* @param[out] gestor SGV que vai ser tratado.
*/
SGV query2(SGV gestor);
/** @brief chamada da query 3, que trata do input do utilizador.
* @param[out] gestor SGV que vai ser tratado.
*/
SGV query3(SGV gestor);
/** @brief chamada da query 4, que trata do input do utilizador.
* @param[out] gestor SGV que vai ser tratado.
*/
SGV query4(SGV gestor);
/** @brief chamada da query 5, que trata do input do utilizador.
* @param[out] gestor SGV que vai ser tratado.
*/
SGV query5(SGV gestor);
/** @brief chamada da query 6.
* @param[out] gestor SGV que vai ser tratado.
*/
SGV query6(SGV gestor);
/** @brief chamada da query 7, que trata do input do utilizador.
* @param[out] gestor SGV que vai ser tratado.
*/
SGV query7(SGV gestor);
/** @brief chamada da query 8, que trata do input do utilizador.
* @param[out] gestor SGV que vai ser tratado.
*/
SGV query8(SGV gestor);
/** @brief chamada da query 9, que trata do input do utilizador.
* @param[out] gestor SGV que vai ser tratado.
*/
SGV query9(SGV gestor);
/** @brief chamada da query 10, que trata do input do utilizador.
* @param[out] gestor SGV que vai ser tratado.
*/
SGV query10(SGV gestor);
/** @brief chamada da query 11, que trata do input do utilizador.
* @param[out] gestor SGV que vai ser tratado.
*/
SGV query11(SGV gestor);
/** @brief chamada da query 12, que trata do input do utilizador.
* @param[out] gestor SGV que vai ser tratado.
*/
SGV query12(SGV gestor);
/** @brief chamada da query 13.
* @param[out] gestor SGV que vai ser tratado.
*/
SGV query13(SGV gestor);

/** @brief Função do menu, onde vai ser tratado o input inicial do utilizador.
* @param[out] gestor SGV a ser tratado, destruído ou inicializado.
*/
SGV menu(SGV gestor);

#endif
