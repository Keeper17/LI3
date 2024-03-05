package GestaoVendas.include.Model;

import java.util.List;

public interface CatProdutos {

    /**
     * Adicionar um produto ao Catálogo
     * @param p Produto a adicionar
     */
    void addProduto(Produto p);

    /**
     * Verificar se um dado produto existe no catálogo
     * @param p Produto cuja existência queremos verifcar
     * @return Se o produto existe ou não
     */
    boolean existeProduto(Produto p);

    /**
     * Função que devolve o tamanho do catálogo de produtos
     * @return o tamanho do catálogo de produtos
     */
    int size();

    /**
     * Função que passa os códigos de produto para uma list de strings
     * @return Uma List de Strings com os códigos
     */
    List<String> toListString();

}
