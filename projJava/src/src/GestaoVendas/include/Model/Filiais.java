package GestaoVendas.include.Model;


import GestaoVendas.Auxiliary_Classes.StatsQ2;
import GestaoVendas.Auxiliary_Classes.StringDouble;
import GestaoVendas.Auxiliary_Classes.StringInt;

import java.util.List;
import java.util.Set;

public interface Filiais {

    /**
     * Adicionar uma Info à estrutura listaFils
     *
     * @param f Filial_Info a adicionar
     * @param c cliente que fez a compra
     */
    void addInfo(Filial_Info f, Cliente c);

    /**
     * Verificar se uma filial de uma Filial_Info existe na estrutura listaFils
     *
     * @param f Filial_Info com o número da filial
     * @return boolean a indicar se a filial existe ou não
     */
    boolean existeFil(Filial_Info f);

    /**
     * Verificar se um Produto de uma Filial_Info existe na estrutura listaFils
     *
     * @param f Filial_Info com o código do Produto
     * @return boolean a indicar se o Produto existe ou não
     */
    boolean existeCliente(Integer f, String cod);

    /**
     * Devolve o número de informações da Filial que guarda
     *
     * @return número de informações da Filial que guarda
     */
    int size();

    /*QUERIES*/

    /**
     * Devolve uma lista com os códigos de produtos comprados por um dado cliente e suas quantidades
     * @param c Cliente em questão
     * @return set com os códigos de produtos comprados por um dado cliente e suas quantidades
     */
    Set<StringInt> getInfoQuery5(Cliente c);

    /**
     * Devolve uma lista com os códigos de clientes e número de produtos diferentes que compraram
     * @return lista com os códigos de clientes e número de produtos diferentes que compraram
     */
    List<StringInt> getInfoQuery8();

    /**
     * Obtenção parcial dos dados para a segunda query
     * @param sq2 Estrutura que vamos preencher
     */
    void setInfoStatQuery2Fil(StatsQ2 sq2);

    /**
     * Devolve o total de Clientes que efetuou compras numa determinada filial
     * @param fil número da filial a analisar
     * @return número de clientes da filial
     */
    int getTotalClientes(Integer fil);

    /**
     * Devolve o total de Vendas efetuadas numa determinada filial
     * @param fil número da filial a analisar
     * @return número de vendas da filial
     */
    int getTotalVendas(Integer fil);

    /**
     * Devolve uma lista com as listas dos maiores compradores ordenados
     * @return Lista de listas com o codigo do cliente e o valor gasto
     */
    List<List<StringDouble>> top3Clientes();
}
