package GestaoVendas.include.Model;

public interface Produto {

    /**
     * Getter do Código do Produto
     * @return O código do produto
     */
    String getCodProd();

    /**
     * Setter do atributo codProd
     * @param c Novo código de produto
     */
    void setCodProd(String c);

    /**
     * Função que verifica se o código do produto é válido
     * @return Retorna TRUE se o código é válido
     */
    boolean isValid();
}
