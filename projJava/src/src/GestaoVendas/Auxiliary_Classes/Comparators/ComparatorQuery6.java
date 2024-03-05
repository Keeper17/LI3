package GestaoVendas.Auxiliary_Classes.Comparators;

import GestaoVendas.Auxiliary_Classes.StringInt2;

import java.util.Comparator;

public class ComparatorQuery6 implements Comparator<StringInt2> {

    /**
     * Método Compare (Ordem Decrescente)
     * @param si1 instância da classe auxiliar StringInt2
     * @param si2 instância da classe auxiliar StringInt2
     * @return inteiro
     */
    public int compare(StringInt2 si1, StringInt2 si2){
        return si2.getItg2() - si1.getItg2();
    }

}
