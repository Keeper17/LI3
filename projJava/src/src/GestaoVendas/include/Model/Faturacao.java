package GestaoVendas.include.Model;

import GestaoVendas.Auxiliary_Classes.*;

import java.util.List;
import java.util.Map;

public interface Faturacao {

    /**
     * Adicionar uma Fatura à estrutura faturacao
     *
     * @param f Fatura a adicionar
     */
    void addFatura(Fatura f);

    /**
     * Verificar se uma dada fatura existe na estrutura faturacao
     *
     * @param f Fatura a verificar se existe
     * @return boolean a indicar se a fatura existe ou não
     */
    boolean existeFatura(Fatura f);

    /**
     * Calcula quantas entradas existem na estrutura faturacao
     *
     * @return inteiro com o número de entradas
     */
    int size();

    /**
     * Guarda os códigos dos produtos comprados numa list de Strings
     * @return List com os códigos
     */
    List<String> toListString();

    /**
     * Diz-nos se um certo produto foi comprado
     * @param p Produto a verificar
     * @return se foi ou não comprado
     */
    boolean prodBought(Produto p);

    /**
     * Método para preencher as váriaveis nCompras e tFaturado de cada instância da classe Query4 em prods
     * @param cod código do produto
     * @param prods lista com as instâncias da classe Query4 a alterar
     */
    void query4Aux(String cod, List<Query4> prods);

    /**
     * Método para retornar uma lista de StringInt2 com todos os códigos de produto ordenados pelo número
     * de unidades vendidas e respetivo nº de clientes distintos
     * @return lista com a informação descrita
     */
    List<StringInt2> getInfoQuery6();

    /**
     * Método para obter uma lista de StringDouble com os códigos de cliente de um produto e respetivo valor gasto
     * por cada um
     * @param cod código do produto
     * @return lista com a informação necessária
     */
    List<StringDouble> getInfoQuery9(String cod);

    /**
     * Método para obter uma lista da estrutura auxiliar Query10 com o total faturado mês a mês e filial a filial
     * de um produto
     * @return lista com esta informação para cada produto
     */
    List<Query10> getInfoQuery10();

    /**
     * Método para obter parte das informações da query estatística 2
     * @param sq2 Objeto StatsQ2
     */
    void setInfoStatQuery2Fat(StatsQ2 sq2);

}
