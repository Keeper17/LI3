package GestaoVendas.src.Model;

import GestaoVendas.include.Model.Produto;

public class Produto_Imp implements Produto {

    String codProd;

    /*Construtor*/
    public Produto_Imp(String c){
        this.codProd = c;
    }

    public Produto_Imp(Produto p){
        this.codProd = p.getCodProd();
    }

    public String getCodProd(){
        return this.codProd;
    }

    public void setCodProd(String c){
        this.codProd = c;
    }

    public boolean isValid(){
        return this.codProd.matches("[A-Z]{2}[1-9][0-9]{3}");
    }

}
