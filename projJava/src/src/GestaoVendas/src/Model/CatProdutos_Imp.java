package GestaoVendas.src.Model;

import GestaoVendas.include.Model.CatProdutos;
import GestaoVendas.include.Model.Produto;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class CatProdutos_Imp implements CatProdutos {

    private Map<String, Produto> catProds;

    public CatProdutos_Imp(){
        //Modificar isto para experimentar com TreeMap
        catProds = new HashMap<>();
    }

    public void addProduto(Produto p){
        String cod = p.getCodProd();
        catProds.put(cod, new Produto_Imp(p));
    }

    public boolean existeProduto(Produto p){
        boolean flag = false;
        if(p.isValid()){
            flag = this.catProds.containsKey(p.getCodProd());
        }
        return flag;
    }

    public int size(){
        return this.catProds.size();
    }

    public List<String> toListString(){
        List<String> l = new ArrayList<>();
        for(Map.Entry<String, Produto> e : catProds.entrySet()){
            l.add(e.getKey());
        }
        return l;
    }

}
