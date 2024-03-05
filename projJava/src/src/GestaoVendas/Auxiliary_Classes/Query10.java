package GestaoVendas.Auxiliary_Classes;

import java.util.ArrayList;
import java.util.List;

public class Query10 {
    private List<Double> fil1;
    private List<Double> fil2;
    private List<Double> fil3;
    private String codProd;

    public Query10(){
        this.fil1 = new ArrayList<>();
        this.fil2 = new ArrayList<>();
        this.fil3 = new ArrayList<>();
        this.codProd = null;

        /*Inicializar as listas com 0 para cada mês*/
        for(int i=0; i < 12; i++){
            fil1.add(i, (double) 0);
            fil2.add(i, (double) 0);
            fil3.add(i, (double) 0);
        }
    }

    public List<Double> getFil1() {
        return fil1;
    }

    public void setFil1(List<Double> fil1) {
        this.fil1 = fil1;
    }

    public List<Double> getFil2() {
        return fil2;
    }

    public void setFil2(List<Double> fil2) {
        this.fil2 = fil2;
    }

    public List<Double> getFil3() {
        return fil3;
    }

    public void setFil3(List<Double> fil3) {
        this.fil3 = fil3;
    }

    public String getCodProd() {
        return codProd;
    }

    public void setCodProd(String codProd) {
        this.codProd = codProd;
    }
}
