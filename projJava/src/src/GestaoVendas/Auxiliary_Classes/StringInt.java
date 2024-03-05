package GestaoVendas.Auxiliary_Classes;


/**
 * Classe auxiliar com uma String e um Inteiro (podia ser substituída por uma Entry<>
 */
public class StringInt {

    /**
     * Variáveis de instância
     */
    private String  str;
    private int itg;


    public String getStr() {
        return str;
    }

    public void setStr(String str) {
        this.str = str;
    }

    public int getItg() {
        return itg;
    }

    public void setItg(int itg) {
        this.itg = itg;
    }

    public StringInt(String str, int itg){
        this.itg = itg;
        this.str = str;
    }

}
