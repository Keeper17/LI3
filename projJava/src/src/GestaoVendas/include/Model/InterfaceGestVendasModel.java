package GestaoVendas.include.Model;

import GestaoVendas.Auxiliary_Classes.*;
import GestaoVendas.Auxiliary_Classes.Exceptions.ModelException;

import java.util.List;
import java.util.Set;

public interface InterfaceGestVendasModel {

    /**
     * Método para ler os ficheiros input do programa e preencher as estruturas
     *
     * @param PrdPath Path para o ficheiro com os Produtos
     * @param CliPath Path para o ficheiro com os Clientes
     * @param SalPath Path para o ficheiro com as Vendas
     */
    void readInputFiles(String PrdPath, String CliPath, String SalPath) throws ModelException;

    /**
     * Getter para a variável pinfo que contém informações sobre os ficheiros lidos
     *
     * @return PopulationInfo classe com as informações dos ficheiros lidos
     */
    PopulationInfo getPinfo();

    /**
     * Função para obter as informações necessárias para a Query Estatística 2
     * @return Objeto com as informações para a Query Est. 2
     */
    StatsQ2 statisticalQ2();


    /**
     * Query 1 (produtos não comprados)
     * @return Lista com os códigos dos produtos não comprados
     */
    List<String> prodsNotBought();

    /**
     * Query4 (informações de produtos mês a mês)
     * @param cod código do produto
     * @return Lista com instâncias da classe Query4 com 3 variáveis para armazenar as informações pedidas
     */
    List<Query4> prodsBoughtByMonth(String cod);
    /**
     * Query 5 (produtos comprados por um cliente e suas quantidade)
     * @param cod Cliente em questão
     * @return Lista com as informações necessárias
     */
    Set<StringInt> clientPurchases(String cod);

    /**
     * Query 6 (produtos mais vendidos e respetivo nº de clientes diferentes que os compraram)
     * @return Lista com a informação pedida
     */
    List<StringInt2> prodsMostBought();

    /**
     * Query 8 (Clientes por número de produtos diferentes comprados)
     * @return Lista com os clientes e o número de produtos comprados por eles.
     */
    List<StringInt> clientsByDiffProdsBought();

    /**
     * Query 9 (Dado um produto, conjunto dos X clientes que mais o compraram e respetivo valor gasto)
     * @param cod código do produto
     * @return Lista com os códigos de cliente e respetivo valor gasto
     */
    List<StringDouble> prodMostBoughtClients(String cod);

    /**
     * Query 10 (Faturação total mês a mês e filial a filial de cada produto)
     * @return lista com esta informação para todos os produtos
     */
    List<Query10> totalFat();



    /*TODO Meter os interfaces das queries aqui depois*/

}
