package GestaoVendas.Auxiliary_Classes.Comparators;

import GestaoVendas.Auxiliary_Classes.StringDouble;

import java.util.Comparator;

public class ComparatorQuery9 implements Comparator<StringDouble> {

    public int compare(StringDouble sd1, StringDouble sd2){
        if(sd1.getDb() != sd2.getDb()) {
            if (sd1.getDb() < sd2.getDb()) return 1;
            else return -1;
        }
        else
            return sd1.getStr().compareTo(sd2.getStr());
    }
}
