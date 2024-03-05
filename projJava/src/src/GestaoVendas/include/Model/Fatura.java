package GestaoVendas.include.Model;

public interface Fatura {

    /**
     * Getter para a variável codProd
     *
     * @return String com o código do produto
     */
    String getCodProd();

    /**
     * Setter para a variável codProd
     *
     * @param codProd com o código de produto
     */
    void setCodProd(String codProd);

    /**
     * Getter para a variável precoUnit
     *
     * @return double com o preço
     */
    double getPrecoUnit();

    /**
     * Setter para a variável precoUnit
     *
     * @param precoUnit com o preço de uma unidade
     */
    void setPrecoUnit(double precoUnit);

    /**
     * Getter para a variável quantidade
     *
     * @return inteiro com o valor da quantidade
     */
    int getQuantidade();

    /**
     * Setter para a variável quantidade
     *
     * @param quantidade com o valor da quantidade a alterar
     */
    void setQuantidade(int quantidade);

    /**
     * Getter para a variável tipo
     *
     * @return String com o valor do tipo
     */
    String getTipo();

    /**
     * Setter para a variável tipo
     *
     * @param tipo com o valor do tipo a alterar
     */
    void setTipo(String tipo);

    String getCodCli();

    void setCodCli(String codCli);

    /**
     * Getter para a variável mes
     *
     * @return inteiro com o valor do mes
     */
    int getMes();

    /**
     * Setter para a variável mes
     *
     * @param mes com o valor do mês a alterar
     */
    void setMes(int mes);

    /**
     * Getter para a variável filial
     *
     * @return inteiro com o valor da filial
     */
    int getFilial();

    /**
     * Setter para a variável filial
     *
     * @param filial com o valor da filial a alterar
     */
    void setFilial(int filial);

}
