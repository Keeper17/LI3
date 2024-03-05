package GestaoVendas.include.Model;

public interface Filial_Info {

    /**
     * Getter para a variável codProd
     *
     * @return String com o código do Produto
     */
    String getCodProd();

    /**
     * Setter para a variável codProd
     *
     * @param codProd com o código do Produto
     */
    void setCodProd(String codProd);

    /**
     * Setter para a variável quantidade
     *
     * @return inteiro com o valor da quantidade
     */
    Integer getQuantidade();

    /**
     * Setter para a variável quantidade
     *
     * @param quantidade com o valor da quantidade a alterar
     */
    void setQuantidade(Integer quantidade);

    /**
     * Getter para a variável preco
     *
     * @return float com o preço
     */
    float getPreco();

    /**
     * Setter para a variável preco
     *
     * @param preco com o calor do preço
     */
    void setPreco(float preco);

    /**
     * Getter para a variável tipo
     *
     * @return String com o tipo
     */
    String getTipo();

    /**
     * Setter para a variável tipo
     *
     * @param tipo a alterar
     */
    void setTipo(String tipo);

    int getMes();

    void setMes(int mes);

    /**
     * Getter para a variável filial
     *
     * @return Número da filial
     */
    Integer getFilial();

    /**
     * Setter para a variável filial
     *
     * @param filial Número da filial
     */
    void setFilial(Integer filial);
}
