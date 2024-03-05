package GestaoVendas.Auxiliary_Classes.Comparators;

import GestaoVendas.Auxiliary_Classes.StringInt;

import java.util.Comparator;

/**
 * Comparator para StringInt, ordem DECRESCENTE
 */

public class ComparatorQuery5 implements Comparator<StringInt> {

    /**
     * Método Compare (Ordem Decrescente, then Alfabetical)
     */
    public int compare(StringInt si1, StringInt si2){
        if(si1.getItg() != si2.getItg())
            return si2.getItg() - si1.getItg();
        else
            return si1.getStr().compareTo(si2.getStr());
    }
}
