package GestaoVendas.src.Model;

import GestaoVendas.include.Model.Cliente;

public class Cliente_Imp implements Cliente {

    String codCli;

    /*Construtores*/
    public Cliente_Imp(String c){
        codCli = c;
    }

    public Cliente_Imp(Cliente c){
        this.codCli = c.getCodCli();
    }



    public boolean isValid(){
        return this.codCli.matches("[A-Z](([1-4][0-9]{3})|5000)");
    }

    public void setCodCli(String c){
        this.codCli = c;
    }

    public String getCodCli(){
        return this.codCli;
    }

}
