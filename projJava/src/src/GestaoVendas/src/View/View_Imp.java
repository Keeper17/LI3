package GestaoVendas.src.View;

import GestaoVendas.Auxiliary_Classes.*;
import GestaoVendas.include.View.InterfaceGestVendasView;
import GestaoVendas.include.Model.PopulationInfo;

import java.util.List;
import java.util.Map;

public class View_Imp implements InterfaceGestVendasView {

    /*A cor é só para adicionar um bocado de flair à query stat 2, para se destacar mais do resto*/
    private static final String ANSI_RESET = "\u001B[0m";
    private static final String ANSI_BLUE = "\u001B[34m";


    /*BIG BRUH MOMENT*/
    public void printMenu(){
        System.out.print(" \n------------------------------- Bem Vindo ao SGV -------------------------------\n");
        System.out.print("Selecione uma opção:\n\n");
        System.out.print("0 - Ler ficheiros input\n\n");
        System.out.print("Consultas Estatísticas\n\n");
        System.out.print("a - Apresentar dados do último ficheiro de vendas lido\n");
        System.out.print("b - Apresentar números gerais dos dados atuais já registados\n\n");
        System.out.print("Consultas Interativas\n\n");
        System.out.print("1 - Produtos nunca comprados\n");
        System.out.print("2 - TODO\n");
        System.out.print("3 - TODO\n");
        System.out.print("4 - Dado um produto, nº de compras, por quantos clientes diferentes e total faturado, mês a mês\n");
        System.out.print("5 - Produtos que um cliente mais comprou\n");
        System.out.print("6 - X produtos mais vendidos e respetivo total de clientes distintos que os compraram\n");
        System.out.print("7 - TODO\n");
        System.out.print("8 - N clientes que mais produtos diferentes compraram\n");
        System.out.print("9 - Dado um produto, conjunto dos X clientes que mais o compraram e respetivo valor gasto\n");
        System.out.print("10 - Faturação total mês a mês e filial a filial de cada produto\n\n");
        System.out.print("q - Terminar o programa\n");
    }



    /*READ INPUT FILES*/

    public void printRIF1(){
        System.out.println("Preencher SGV com os ficheiros default (d) ou inserir novos ficheiros (n)?");
    }

    public void printRIF2(){
        System.out.println("Insira o path para os ficheiros input (Produtos, Clientes, Vendas):");
    }

    public void printRIF_Suc(){
        System.out.println("Ficheiros lidos com sucesso!");
    }

    public void printRIF_Fail(String e){
        System.out.println("Não foi possível ler o ficheiro " + e + "!");
    }



    /*QUERIES ESTATÍSTICAS*/

    public void printQE1(PopulationInfo p){
        System.out.println("Informação dos ficheiros lidos: \n");

        System.out.println("Produtos: " + p.getPrdPath());
        System.out.println("Total: " + p.getPt() + "   Válidos: " + p.getPv() + '\n');

        System.out.println("Clientes: " + p.getCliPath());
        System.out.println("Total: " + p.getCt() + "   Válidos: " + p.getCv() + '\n');

        System.out.println("Vendas: " + p.getVndPath());
        System.out.println("Total: " + p.getVt() + "   Válidos: " + p.getVv() + '\n');
    }

    public void printQE2(StatsQ2 sq2){
        System.out.println(ANSI_BLUE+ sq2.toString() + ANSI_RESET);
    }



    /*QUERIES INTERATIVAS*/

    public void printQI4(){
        System.out.println("Indique o código de produto que pretende analisar");
    }

    public void printQI4R(List<Query4> prods){
        System.out.printf("Mês       %s               %s                 %s\n","Compras","Nº Clientes", "Tfaturado" );
        System.out.printf("JAN         %-12d            %-11d              %-10f\n",prods.get(0).getnCompras(),prods.get(0).getnClientes(),prods.get(0).gettFaturado());
        System.out.printf("FEV         %-12d            %-11d              %-10f\n",prods.get(1).getnCompras(),prods.get(1).getnClientes(),prods.get(1).gettFaturado());
        System.out.printf("MAR         %-12d            %-11d              %-10f\n",prods.get(2).getnCompras(),prods.get(2).getnClientes(),prods.get(2).gettFaturado());
        System.out.printf("ABR         %-12d            %-11d              %-10f\n",prods.get(3).getnCompras(),prods.get(3).getnClientes(),prods.get(3).gettFaturado());
        System.out.printf("MAI         %-12d            %-11d              %-10f\n",prods.get(4).getnCompras(),prods.get(4).getnClientes(),prods.get(4).gettFaturado());
        System.out.printf("JUN         %-12d            %-11d              %-10f\n",prods.get(5).getnCompras(),prods.get(5).getnClientes(),prods.get(5).gettFaturado());
        System.out.printf("JUL         %-12d            %-11d              %-10f\n",prods.get(6).getnCompras(),prods.get(6).getnClientes(),prods.get(6).gettFaturado());
        System.out.printf("AGO         %-12d            %-11d              %-10f\n",prods.get(7).getnCompras(),prods.get(7).getnClientes(),prods.get(7).gettFaturado());
        System.out.printf("SET         %-12d            %-11d              %-10f\n",prods.get(8).getnCompras(),prods.get(8).getnClientes(),prods.get(8).gettFaturado());
        System.out.printf("OUT         %-12d            %-11d              %-10f\n",prods.get(9).getnCompras(),prods.get(9).getnClientes(),prods.get(9).gettFaturado());
        System.out.printf("NOV         %-12d            %-11d              %-10f\n",prods.get(10).getnCompras(),prods.get(10).getnClientes(),prods.get(10).gettFaturado());
        System.out.printf("DEZ         %-12d            %-11d              %-10f\n",prods.get(11).getnCompras(),prods.get(11).getnClientes(),prods.get(11).gettFaturado());
    }

    public void printQI5() { System.out.println("Insira um código de cliente: "); }

    public void printQI5F() { System.out.println("Código inválido!\n"); }

    public void printQI6(){
        System.out.println("Insira o número de produtos que deseja ver: ");
    }

    public void printQI8()  {
        System.out.print("Insira o número de clientes que deseja ver: ");
    }

    public void printQI9a() {
        System.out.println("Insira o código de produto que pretende analisar: ");
    }

    public void printQI9b(){
        System.out.println("Insira o número de clientes que deseja ver: ");
    }

    public void printOneEntry(List<Query10> l, int i){
        System.out.println("Mês         Filial1                 Filial2                  Filial3");
        System.out.printf("JAN         %-12.2f            %-11.2f              %-10.2f\n", l.get(i).getFil1().get(0), l.get(i).getFil2().get(0), l.get(i).getFil3().get(0));
        System.out.printf("FEV         %-12.2f            %-11.2f              %-10.2f\n", l.get(i).getFil1().get(1), l.get(i).getFil2().get(1), l.get(i).getFil3().get(1));
        System.out.printf("MAR         %-12.2f            %-11.2f              %-10.2f\n", l.get(i).getFil1().get(2), l.get(i).getFil2().get(2), l.get(i).getFil3().get(2));
        System.out.printf("ABR         %-12.2f            %-11.2f              %-10.2f\n", l.get(i).getFil1().get(3), l.get(i).getFil2().get(3), l.get(i).getFil3().get(3));
        System.out.printf("MAI         %-12.2f            %-11.2f              %-10.2f\n", l.get(i).getFil1().get(4), l.get(i).getFil2().get(4), l.get(i).getFil3().get(4));
        System.out.printf("JUN         %-12.2f            %-11.2f              %-10.2f\n", l.get(i).getFil1().get(5), l.get(i).getFil2().get(5), l.get(i).getFil3().get(5));
        System.out.printf("JUL         %-12.2f            %-11.2f              %-10.2f\n", l.get(i).getFil1().get(6), l.get(i).getFil2().get(6), l.get(i).getFil3().get(6));
        System.out.printf("AGO         %-12.2f            %-11.2f              %-10.2f\n", l.get(i).getFil1().get(7), l.get(i).getFil2().get(7), l.get(i).getFil3().get(7));
        System.out.printf("SET         %-12.2f            %-11.2f              %-10.2f\n", l.get(i).getFil1().get(8), l.get(i).getFil2().get(8), l.get(i).getFil3().get(8));
        System.out.printf("OUT         %-12.2f            %-11.2f              %-10.2f\n", l.get(i).getFil1().get(9), l.get(i).getFil2().get(9), l.get(i).getFil3().get(9));
        System.out.printf("NOV         %-12.2f            %-11.2f              %-10.2f\n", l.get(i).getFil1().get(10), l.get(i).getFil2().get(10), l.get(i).getFil3().get(10));
        System.out.printf("DEZ         %-12.2f            %-11.2f              %-10.2f\n", l.get(i).getFil1().get(11), l.get(i).getFil2().get(11), l.get(i).getFil3().get(11));
        System.out.println("Página anterior (a) Próxima página (p) Sair (q)");
    }

    /*PRINTS GENÉRICOS*/

    public void printBigList(List<String> l, int start, int end){
        for(int i = start; i < end && i < l.size(); i++){
            System.out.println(l.get(i));
        }
        System.out.println("Página anterior (a) Próxima página (p) Sair (q)");
    }

    public void printBigListSI(List<StringInt> l, int start, int end){
        for(int i = start; i < end && i < l.size(); i++){
            System.out.println(l.get(i).getStr() + "   " + l.get(i).getItg());
        }
        System.out.println("Página anterior (a) Próxima página (p) Sair (q)");
    }

    public void printBigListSI2(List<StringInt2> l, int start, int end){
        for(int i = start; i < end && i < l.size(); i++){
            System.out.println(l.get(i).getStr() + "   " + l.get(i).getItg1());
        }
        System.out.println("Página anterior (a) Próxima página (p) Sair (q)");
    }

    public void printBigListSD(List<StringDouble> l, int start, int end){
        for(int i = start; i < end && i < l.size(); i++){
            System.out.println(l.get(i).getStr() + "   " + l.get(i).getDb());
        }
        System.out.println("Página anterior (a) Próxima página (p) Sair (q)");
    }

    public void printSize(int x){
        System.out.println("Tamanho: " + x);
    }

    public void printCodProd(String cod) { System.out.println("Produto: " + cod); }
}
