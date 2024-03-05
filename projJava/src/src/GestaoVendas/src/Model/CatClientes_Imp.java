package GestaoVendas.src.Model;

import GestaoVendas.include.Model.CatClientes;
import GestaoVendas.include.Model.Cliente;

import java.util.HashMap;
import java.util.Map;

public class CatClientes_Imp implements CatClientes {

    private Map<String, Cliente> catClientes;


    public CatClientes_Imp(){
        /*Alterar isto para experimentar com TreeMaps*/
        this.catClientes = new HashMap<>();
    }

    public void addCliente(Cliente c) {
        String key = c.getCodCli();
        this.catClientes.put(key, new Cliente_Imp(c));
    }

    public boolean existeCliente(Cliente c){
        boolean flag = false;
        if(c.isValid()){
            flag = this.catClientes.containsKey(c.getCodCli());
        }
        return flag;
    }

    public int size(){
        return this.catClientes.size();
    }
}
