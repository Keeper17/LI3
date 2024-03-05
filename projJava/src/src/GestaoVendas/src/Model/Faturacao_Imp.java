package GestaoVendas.src.Model;

import GestaoVendas.Auxiliary_Classes.*;
import GestaoVendas.Auxiliary_Classes.Comparators.ComparatorQuery6;
import GestaoVendas.Auxiliary_Classes.Comparators.ComparatorQuery9;
import GestaoVendas.include.Model.Fatura;
import GestaoVendas.include.Model.Faturacao;
import GestaoVendas.include.Model.Produto;

import java.util.*;

public class Faturacao_Imp implements Faturacao {

    private Map<String, List<Fatura>> faturacao;

    public Faturacao_Imp() {
        this.faturacao = new HashMap<>();
    }

    public void addFatura(Fatura f){
        String key = f.getCodProd();
        if (existeFatura(f)){
            this.faturacao.get(key).add(new Fatura_Imp(f));
        }
        else {
            this.faturacao.put(key, new ArrayList<>());
            this.faturacao.get(key).add(new Fatura_Imp(f));
        }
    }

    public boolean existeFatura(Fatura f){
        boolean flag;
        flag = this.faturacao.containsKey(f.getCodProd());
        return flag;
    }

    public int size(){
        int size = 0;
        for(Map.Entry<String, List<Fatura>> e : faturacao.entrySet()){
            size += e.getValue().size();
        }
        return size;
    }

    public List<String> toListString(){
        List<String> l = new ArrayList<>();

        for(Map.Entry<String, List<Fatura>> e : this.faturacao.entrySet()){
            l.add(e.getKey());
        }

        return l;
    }

    public boolean prodBought(Produto p){
        return this.faturacao.containsKey(p.getCodProd());
    }

    public void query4Aux(String cod, List<Query4> prods){
        Query4 e = new Query4_Imp();
        int pos;
        List<StringInt> clientes = new ArrayList<>();
        boolean flag = false;

        List<Fatura> fats = this.faturacao.get(cod);

        for(Fatura f : fats){
            pos = f.getMes() - 1;

            e.setnCompras(prods.get(pos).getnCompras() + f.getQuantidade());

            for(StringInt c : clientes){
                if (c.getItg() == f.getMes() && c.getStr().equals(f.getCodCli())){
                    flag = true;
                    break;
                }
            }
            if(!flag){
                e.setnClientes(prods.get(pos).getnClientes() + 1);
                clientes.add(new StringInt(f.getCodCli(), f.getMes()));
            }

            e.settFaturado(prods.get(pos).gettFaturado() + (f.getQuantidade() * f.getPrecoUnit()));
            prods.set(pos, e);
            e = new Query4_Imp();
        }
    }

    public List<StringInt2> getInfoQuery6(){
        List<StringInt2> list = new ArrayList<>();
        int quant = 0;
        int nCli = 0;
        List<String> clientes = new ArrayList<>();

        for(Map.Entry<String, List<Fatura>> e : this.faturacao.entrySet()){
            List<Fatura> fats = e.getValue();

            for(Fatura f : fats){
                quant += f.getQuantidade();
                if (!clientes.contains(f.getCodCli())){
                    nCli++;
                    clientes.add(f.getCodCli());
                }
            }
            list.add(new StringInt2(e.getKey(), nCli, quant));
            quant=nCli=0;
            clientes = new ArrayList<>();
        }

        list.sort(new ComparatorQuery6());
        return list;
    }

    public List<StringDouble> getInfoQuery9(String cod){
        Map<String, StringDouble> map = new HashMap<>();
        List<String> clientes = new ArrayList<>();

        List<Fatura> fats = this.faturacao.get(cod);

        for(Fatura f : fats){
            StringDouble sd = new StringDouble(f.getCodCli(), f.getQuantidade() * f.getPrecoUnit());
            if(clientes.contains(f.getCodCli())){
                sd.setDb(map.get(f.getCodCli()).getDb() + sd.getDb());
                map.replace(f.getCodCli(), sd);
                clientes.add(f.getCodCli());
            }
            else map.put(f.getCodCli(), sd);
        }

        List<StringDouble> list = new ArrayList<>();

        for (Map.Entry<String, StringDouble> e : map.entrySet())
            list.add(e.getValue());

        list.sort(new ComparatorQuery9());
        return list;
    }

    public List<Query10> getInfoQuery10(){
        List<Query10> list = new ArrayList<>();
        int pos;
        List<Double> d;

        //Percorrer o Map das Faturas
        for(Map.Entry<String, List<Fatura>> e1 : this.faturacao.entrySet()) {
            Query10 q = new Query10();

            //Percorrer a lista de Faturas de cada código de produto
            for (Fatura f : e1.getValue()) {
                pos = f.getMes() - 1;
                if (f.getFilial() == 1){
                    d = q.getFil1();
                    d.set(pos, d.get(pos) + (f.getPrecoUnit() * f.getQuantidade()));
                    q.setFil1(d);
                }
                else if(f.getFilial() == 2){
                    d = q.getFil2();
                    d.set(pos, d.get(pos) + (f.getPrecoUnit() * f.getQuantidade()));
                    q.setFil2(d);
                }
                else {
                    d = q.getFil3();
                    d.set(pos, d.get(pos) + (f.getPrecoUnit() * f.getQuantidade()));
                    q.setFil3(d);
                }
            }
            q.setCodProd(e1.getKey());
            list.add(q);
        }
        return list;
    }

    public void setInfoStatQuery2Fat(StatsQ2 sq2){

        Map<String, Boolean[][]> tmp = new HashMap<>();

        //Percorrer o Map das Faturas
        for(Map.Entry<String, List<Fatura>> e1 : this.faturacao.entrySet()){

            //Percorrer a lista de Faturas de cada código de produto
            for(Fatura f : e1.getValue()){

                /*
                if(tmp.containsKey(f.getCodProd())){
                    tmp.put(f.getCodProd(), new Boolean[3][12]);
                }
                else{
                    Boolean[][] tmp2 = tmp.get(f.getCodProd());
                    tmp2[f.getFilial()-1][f.getMes()-1] = true;
                    tmp.replace(f.getCodProd(), tmp2);
                }*/

                sq2.fatMes[f.getMes()-1] += f.getPrecoUnit() * f.getQuantidade();
                sq2.numCompras[f.getMes()-1] += f.getQuantidade();
            }
        }
    }

}
