package GestaoVendas.include.Model;

public interface PopulationInfo {

    /**
     * Getter para o path do ficheiro produtos
     * @return path para o ficheiro produtos
     */
    String getPrdPath();

    /**
     * Setter para o path do ficheiro produtos
     * @param prdPath Novo path para o ficheiro produtos
     */
    void setPrdPath(String prdPath);

    /**
     * Getter para o path do ficheiro clientes
     * @return path para o ficheiro clientes
     */
    String getCliPath();

    /**
     * Setter para o path do ficheiro clientes
     * @param cliPath Novo path para o ficheiro clientes
     */
    void setCliPath(String cliPath);

    /**
     * Getter para o path do ficheiro vendas
     * @return path para o ficheiro vendas
     */
    String getVndPath();

    /**
     * Setter para o path do ficheiro vendas
     * @param vndPath Novo path para o ficheiro vendas
     */
    void setVndPath(String vndPath);

    /**
     * Getter para o valor de produtos lidos
     * @return valor de produtos lidos
     */
    int getPt();

    /**
     * Setter para o total de produtos lidos
     * @param pt Novo total
     */
    void setPt(int pt);

    /**
     * Getter para o valor de clientes lidos
     * @return valor de clientes lidos
     */
    int getCt();

    /**
     * Setter para o total de clientes lidos
     * @param ct Novo total
     */
    void setCt(int ct);

    /**
     * Getter para o valor de vendas lidas
     * @return valor de vendas lidas
     */
    int getVt();

    /**
     * Setter para o total de vendas lidas
     * @param vt Novo total
     */
    void setVt(int vt);

    /**
     * Getter do número de produtos válidos
     * @return número de produtos válidos
     */
    int getPv();

    /**
     * Setter para o valor de produtos válidos
     * @param pv novo valor de produtos válidos
     */
    void setPv(int pv);

    /**
     * Getter do número de clientes válidos
     * @return número de clientes válidos
     */
    int getCv();

    /**
     * Setter para o valor de clientes válidos
     * @param cv novo valor de clientes válidos
     */
    void setCv(int cv);

    /**
     * Getter do número de vendas válidas
     * @return número de vendas válidas
     */
    int getVv();

    /**
     * Setter para o valor de vendas válidas
     * @param vv novo valor de vendas válidas
     */
    void setVv(int vv);

}
