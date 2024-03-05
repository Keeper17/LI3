package GestaoVendas.Auxiliary_Classes;

/**
 *
 * Classe auxiliar para a Query Estatística 2
 *
 */

public class StatsQ2 {

    /**
     * Variáveis de instância
     */
    public Integer[] numCompras;
    public Double[] fatMes;
    public Integer[][] clientesCompras;

    /**
     * Construtor vazio
     */
    public StatsQ2(){
        numCompras = new Integer[12];
        fatMes = new Double[12];
        clientesCompras = new Integer[3][12];

        for(int i = 0; i < 12; i++){
            fatMes[i] = 0.0;
            numCompras[i] = 0;
        }
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 12; j++)
                clientesCompras[i][j] = 0;

    }

    /**
     * Método toString, bastante formatado
     * @return String com todas as informações do objeto
     */
    public String toString(){

        StringBuilder sb = new StringBuilder();

        sb.append("Total de produtos comprados: \n\n");
        sb.append("JAN : ").append(numCompras[0]).append("\n");
        sb.append("FEB : ").append(numCompras[1]).append("\n");
        sb.append("MAR : ").append(numCompras[2]).append("\n");
        sb.append("APR : ").append(numCompras[3]).append("\n");
        sb.append("MAY : ").append(numCompras[4]).append("\n");
        sb.append("JUN : ").append(numCompras[5]).append("\n");
        sb.append("JUL : ").append(numCompras[6]).append("\n");
        sb.append("AUG : ").append(numCompras[7]).append("\n");
        sb.append("SEP : ").append(numCompras[8]).append("\n");
        sb.append("OCT : ").append(numCompras[9]).append("\n");
        sb.append("NOV : ").append(numCompras[10]).append("\n");
        sb.append("DEC : ").append(numCompras[11]).append("\n");


        sb.append("\nTotal faturado: \n\n");
        sb.append("JAN : ").append(fatMes[0]).append("\n");
        sb.append("FEB : ").append(fatMes[1]).append("\n");
        sb.append("MAR : ").append(fatMes[2]).append("\n");
        sb.append("APR : ").append(fatMes[3]).append("\n");
        sb.append("MAY : ").append(fatMes[4]).append("\n");
        sb.append("JUN : ").append(fatMes[5]).append("\n");
        sb.append("JUL : ").append(fatMes[6]).append("\n");
        sb.append("AUG : ").append(fatMes[7]).append("\n");
        sb.append("SEP : ").append(fatMes[8]).append("\n");
        sb.append("OCT : ").append(fatMes[9]).append("\n");
        sb.append("NOV : ").append(fatMes[10]).append("\n");
        sb.append("DEC : ").append(fatMes[11]).append("\n");

        sb.append("\nTotal de clientes: \n\n");
        sb.append("MES            FIL        \n");
        sb.append("          1     2     3       \n");
        sb.append("JAN :").append("  ").append(clientesCompras[0][0]).append(" ").append(clientesCompras[1][0]).append(" ").append(clientesCompras[2][0]).append("\n");
        sb.append("FEB :").append("  ").append(clientesCompras[0][1]).append(" ").append(clientesCompras[1][1]).append(" ").append(clientesCompras[2][1]).append("\n");
        sb.append("MAR :").append("  ").append(clientesCompras[0][2]).append(" ").append(clientesCompras[1][2]).append(" ").append(clientesCompras[2][2]).append("\n");
        sb.append("APR :").append("  ").append(clientesCompras[0][3]).append(" ").append(clientesCompras[1][3]).append(" ").append(clientesCompras[2][3]).append("\n");
        sb.append("MAY :").append("  ").append(clientesCompras[0][4]).append(" ").append(clientesCompras[1][4]).append(" ").append(clientesCompras[2][4]).append("\n");
        sb.append("JUN :").append("  ").append(clientesCompras[0][5]).append(" ").append(clientesCompras[1][5]).append(" ").append(clientesCompras[2][5]).append("\n");
        sb.append("JUL :").append("  ").append(clientesCompras[0][6]).append(" ").append(clientesCompras[1][6]).append(" ").append(clientesCompras[2][6]).append("\n");
        sb.append("AUG :").append("  ").append(clientesCompras[0][7]).append(" ").append(clientesCompras[1][7]).append(" ").append(clientesCompras[2][7]).append("\n");
        sb.append("SEP :").append("  ").append(clientesCompras[0][8]).append(" ").append(clientesCompras[1][8]).append(" ").append(clientesCompras[2][8]).append("\n");
        sb.append("OCT :").append("  ").append(clientesCompras[0][9]).append(" ").append(clientesCompras[1][9]).append(" ").append(clientesCompras[2][9]).append("\n");
        sb.append("NOV :").append("  ").append(clientesCompras[0][10]).append(" ").append(clientesCompras[1][10]).append(" ").append(clientesCompras[2][10]).append("\n");
        sb.append("DEC :").append("  ").append(clientesCompras[0][11]).append(" ").append(clientesCompras[1][11]).append(" ").append(clientesCompras[2][11]).append("\n\n");


        return sb.toString();
    }


}
