package GestaoVendas.include.Model;

public interface CatClientes {

    /**
     * Adicionar um cliente à estrutura
     *
     * @param c Cliente a adicionar
     */
    void addCliente(Cliente c);

    /**
     * Verificar se um cliente existe
     *
     * @param c Cliente cuja existência queremos verificar
     * @return Se o cliente existe ou não
     */
    boolean existeCliente(Cliente c);

    /**
     * Calcula o Tamanho do catálogo
     * @return Tamanho do catálogo
     */
    int size();


}
