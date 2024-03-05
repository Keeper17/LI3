package GestaoVendas.include.Control;

import GestaoVendas.include.Model.InterfaceGestVendasModel;
import GestaoVendas.include.View.InterfaceGestVendasView;

public interface InterfaceGestVendasControl {

    /**
     * Getter da variável view
     * @return InterfaceGestVendasView com a instância da view
     */
    InterfaceGestVendasView getView();

    /**
     * Setter da variável view
     * @param view instância a alterar na variável view
     */
    void setView(InterfaceGestVendasView view);

    /**
     * Getter da variável model
     * @return InterfaceGestVendasModel com a instância de model
     */
    InterfaceGestVendasModel getModel();

    /**
     * Setter da variável model
     * @param model instâcnia a alterar na variável model
     */
    void setModel(InterfaceGestVendasModel model);

    /**
     * Inicializa a aplicação pedindo à View para apresentar o menu e fica num ciclo infinito até a variável model ser null
     */
    void start();

    /**
     * Regista a opção do utilizador e executa à query respetiva
     * @return da variável model
     */
    InterfaceGestVendasModel menu();

    /*READ INPUT FILES*/

    /**
     * Função para preencher o SGV dado
     * @return o SGV preenchido
     */
    InterfaceGestVendasModel readInputFiles();

    /*STATISTICAL QUERIES*/

    /**
     * Query para mostrar informação relativa aos dados contidos nos ficheiros input do SGV atual
     */
    void queryEst1();

    void queryEst2();

    //TODO


    /*INTERACTIVE QUERIES*/

    /**
     * Query 1 (produtos não comprados)
     */
    void queryInt1();

    /**
     * Query 4 (nª de compras, nº de clientes e total faturado de um produto para todos os meses)
     */
    void queryInt4();

    /**
     * Query 5 (produtos mais comprados por um cliente e respetiva quantidade)
     */
    void queryInt5();

    /**
     * Query 6 (produtos mais vendidos e respetivo nº de clientes diferentes que os compraram)
     */
    void queryInt6();

    /**
     * Query 8 (Clientes por número de produtos diferentes comprados)
     */
    void queryInt8();

    /**
     * Query 9 (Dado um produto, conjunto dos X clientes que mais o compraram e respetivo valor gasto)
     */
    void queryInt9();

    /**
     * Query 10 (Faturação total mês a mês e filial a filial de cada produto)
     */
    void queryInt10();

    //TODO

}
