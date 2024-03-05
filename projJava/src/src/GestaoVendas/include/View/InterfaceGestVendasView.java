package GestaoVendas.include.View;


import GestaoVendas.Auxiliary_Classes.*;
import GestaoVendas.include.Model.PopulationInfo;

import java.util.List;

public interface InterfaceGestVendasView {

    /**
     * Print do menu principal da aplicação com as várias queries
     */
    void printMenu();

    /*READ INPUT FILES*/

    /**
     * Print a perguntar se se usa os ficheiros default ou não
     */
    void printRIF1();

    /**
     * Print de pedido de informações para os paths dos ficheiros a ler
     */
    void printRIF2();

    /**
     * Print de falha no preenchimento das estruturas
     * @param e String com informação da exceção lançada
     */
    void printRIF_Fail(String e);

    /**
     * Print de sucesso no preenchimento das estruturas
     */
    void printRIF_Suc();


    /*STATISTICAL QUERIES*/

    /**
     * Print das informações dos ficheiros lidos
     * @param p Informação de População
     */
    void printQE1(PopulationInfo p);

    /**
     * Print das informações da query estatístcia 2
     * @param sq2 Informações a imprimir
     */
    void printQE2(StatsQ2 sq2);




    /*INTERACTIVE QUERIES*/

    /**
     * Print para perguntar qual o código de produto o utilizador quer analizar
     */
    void printQI4();

    /**
     * Print para dar a resposta à query 4
     * @param prods lista onde os valores a dar print estão armazenados
     */
    void printQI4R(List<Query4> prods);

    /**
     * Print para pedir input da query 5
     */
    void printQI5();

    /**
     * Print para o caso da query 5 falhar
     */
    void printQI5F();

  /**
    * Print para perguntar quantos produtos deseja ver
    */
   void printQI6();

    /**
     * Print para pedir informação da query 8
     */
    void printQI8();

    /**
     * Print para perguntar qual o código de produto que pretende analisar
     */
    void printQI9a();

    /**
     * Print para pedir o número de clientes que deseja ver
     */
    void printQI9b();

    void printOneEntry(List<Query10> l, int i);

    /*PRINTS GENÉRICOS*/

    /**
     * Print de um inteiro
     * @param x Inteiro a mostrar
     */
    void printSize(int x);

    /**
     * Print parcial de uma lista grande
     * @param l Lista grande
     * @param start Índice de início da impressão
     * @param end Índice de fim
     */
    void printBigList(List<String> l, int start, int end);

    /**
     * Print parcial de uma lista grande de StringInt
     * @param l Lista a dar print
     * @param start início
     * @param end fim
     */
    void printBigListSI(List<StringInt> l, int start, int end);

    /**
     * Print parcial de uma lista grande de StringInt2
     * @param l Lista a dar print
     * @param start início
     * @param end fim
     */
    void printBigListSI2(List<StringInt2> l, int start, int end);

    /**
     * Print parcial de uma lista grande de StringDouble
     * @param l lista a dar print
     * @param start início
     * @param end fim
     */
    void printBigListSD(List<StringDouble> l, int start, int end);

    /**
     * Print de uma string
     * @param cod String a apresentar
     */
    void printCodProd(String cod);
}
