package GestaoVendas.src.Model;

//import javafx.util.Pair;

import GestaoVendas.Auxiliary_Classes.Comparators.ComparatorQuery9;
import GestaoVendas.Auxiliary_Classes.StringDouble;
import GestaoVendas.include.Model.Cliente;
import GestaoVendas.include.Model.Filiais;
import GestaoVendas.include.Model.Filial_Info;
import GestaoVendas.Auxiliary_Classes.StatsQ2;
import GestaoVendas.Auxiliary_Classes.StringInt;
import GestaoVendas.Auxiliary_Classes.Comparators.ComparatorQuery5;

import java.util.*;

public class Filiais_Imp implements Filiais {


    /* nº fil  ,     codCliente, infos*/
    private Map<Integer, Map<String, List<Filial_Info>>> listaFils;


    public Filiais_Imp() {
        this.listaFils = new HashMap<>();
    }

    public void addInfo(Filial_Info f, Cliente c) {
        String cod = c.getCodCli();
        Integer fil = f.getFilial();

        /*Se nao existe filial cria-a*/
        if (!existeFil(f))
            this.listaFils.put(fil, new HashMap<>());

        if (existeCliente(fil, cod)) {       /*Se existe cliente adiciona à lista de infos*/
            this.listaFils.get(fil).get(cod).add(new Filial_Info_Imp(f));
        } else {                       /*Se nao existe cliente cria um map associado ao produto e adiciona-o*/
            this.listaFils.get(fil).put(cod, new ArrayList<>());
            this.listaFils.get(fil).get(cod).add(new Filial_Info_Imp(f));
        }
    }

    public boolean existeFil(Filial_Info f) {
        boolean flag;
        flag = this.listaFils.containsKey(f.getFilial());
        return flag;
    }

    public boolean existeCliente(Integer f, String cod) {
        return this.listaFils.get(f).containsKey(cod);
    }

    public int size() {
        int size = 0;
        for (Map.Entry<Integer, Map<String, List<Filial_Info>>> e1 : listaFils.entrySet()) {
            for (Map.Entry<String, List<Filial_Info>> e2 : e1.getValue().entrySet()) {
                size += e2.getValue().size();
            }
        }
        return size;
    }


    /*QUERIES*/

    public Set<StringInt> getInfoQuery5(Cliente c) {

        Map<String, Integer> m = new TreeMap<>();
        String cod = c.getCodCli();

        for (Map.Entry<Integer, Map<String, List<Filial_Info>>> e1 : this.listaFils.entrySet()) {

            if (e1.getValue().containsKey(cod)) {

                List<Filial_Info> lfi = e1.getValue().get(cod);

                for (Filial_Info f : lfi) {

                    if (m.containsKey(f.getCodProd())) {
                        int q = m.get(f.getCodProd());
                        q += f.getQuantidade();
                        m.replace(f.getCodProd(), q);
                    } else {
                        m.put(f.getCodProd(), f.getQuantidade());
                    }
                }
            }
        }

        Set<StringInt> ts = new TreeSet<>(new ComparatorQuery5());

        for (Map.Entry<String, Integer> e : m.entrySet()) {
            ts.add(new StringInt(e.getKey(), e.getValue()));
        }

        return ts;

    }

    public List<StringInt> getInfoQuery8() {

        Map<String, Map<String, Integer>> m = new HashMap<>();

        //Procurar nas filiais
        for (Map.Entry<Integer, Map<String, List<Filial_Info>>> e1 : this.listaFils.entrySet()) {

            //Procurar na filial
            for (Map.Entry<String, List<Filial_Info>> e2 : e1.getValue().entrySet()) {

                String cod = e2.getKey();
                List<Filial_Info> list = e2.getValue();

                //Inicializar a entrada do cliente em questão
                if (!m.containsKey(cod)) {
                    m.put(cod, new HashMap<>());
                }

                //Procurar na informação do cliente
                for (Filial_Info fi : list) {

                    //Adiciona um novo produto ao map se ele não existir
                    if (!m.get(cod).containsKey(fi.getCodProd())) {
                        m.get(cod).put(fi.getCodProd(), 1);
                    }

                }

            }

        }

        List<StringInt> list = new ArrayList<>();

        //Percorrer o map
        for (Map.Entry<String, Map<String, Integer>> e1 : m.entrySet()) {
            int sum = 0;
            //Percorrer cada entrada (cliente) do map
            for (Map.Entry<String, Integer> e2 : e1.getValue().entrySet()) {
                sum += e2.getValue();
            }
            list.add(new StringInt(e1.getKey(), sum));
        }

        //Ordenar a lista por ordem decrescente (mesmo comparator que a query 5)
        list.sort(new ComparatorQuery5());


        return list;
    }

    public void setInfoStatQuery2Fil(StatsQ2 sq2) {

        int filial = 0;

        for (Map.Entry<Integer, Map<String, List<Filial_Info>>> e1 : this.listaFils.entrySet()) {

            for (Map.Entry<String, List<Filial_Info>> e2 : e1.getValue().entrySet()) {

                Boolean[] tmp = new Boolean[12];
                for (int i = 0; i < 12; i++)
                    tmp[i] = false;

                for (Filial_Info fi : e2.getValue()) {

                    if (!tmp[fi.getMes() - 1]) {
                        tmp[fi.getMes() - 1] = true;
                        sq2.clientesCompras[filial][fi.getMes() - 1]++;
                    }

                }

            }

            filial++;

        }

    }


    //Query 3.2.2 - 2
    public int getTotalClientes(Integer fil) {
        return this.listaFils.get(fil).size();
    }

    public int getTotalVendas(Integer fil) {
        int t = 0;
        Map<String, List<Filial_Info>> cods = this.listaFils.get(fil);
        for (List b : cods.values()) {
            t += b.size();
        }
        return t;
    }

    /*
    //Não sei se deve contar com a primeira filial a 0 ou a 1
    public Pair getTotalVendasEClientes(){
        int t = this.listaFils.size();
        int a = 0, b = 0;
        for( int i = 0; i<=t; i++){
            a += getTotalClientes(i);
            b += getTotalVendas(i);
        }
        return new Pair(a,b);
    }
    */

    //Query 3.2.2 - 3
//    public List<List<Integer>> getInfoQuery3(String codC) {
//        List<Integer> totalCompras = new ArrayList<>();
//        List<Integer> totalProdutos = new ArrayList<>();
//        List<Float> totalGasto = new ArrayList<>();
//        List<String>  produtosC = new ArrayList<>();
//
//        for (int i = 0; i < 12; i++) {
//            totalCompras.add(i, 0);
//            totalProdutos.add(i, 0);
//            totalGasto.add(i, 0);
//        }
//
//        for (Map.Entry<Integer, Map<String, List<Filial_Info>>> e1 : this.listaFils.entrySet()) {
//
//            if (e1.getValue().containsKey(codC)) {
//
//                List<Filial_Info> lfi = e1.getValue().get(codC);
//
//                for (Filial_Info f : lfi) {
//                    Integer mes = f.getMes()-1;
//                    float preco = f.getPreco();
//                    Integer qnt = f.getQuantidade();
//                    String cod = f.getCodProd();
//
//                    if(!produtosC.contains(cod)){
//                        totalProdutos.add(mes,1);
//                        produtosC.add(cod);
//                    }
//                    totalCompras.add(mes,1);
//                    totalGasto.add(mes,preco*qnt);
//                }
//            }
//        }
//
//    }

    //Query 7
    public List<List<StringDouble>> top3Clientes(){
        List<List<StringDouble>> r = new ArrayList<>();

        for (Map.Entry<Integer, Map<String, List<Filial_Info>>> e1 : this.listaFils.entrySet()){
            Map<String, List<Filial_Info>> lF = e1.getValue();
            List<StringDouble> f = new ArrayList<>();

            for( Map.Entry<String, List<Filial_Info>> a1 : lF.entrySet()){
                String cod = a1.getKey();
                float total = 0;

                for (Filial_Info a2 : a1.getValue()){
                    total += (a2.getPreco())*(a2.getQuantidade());
                }
                f.add( new StringDouble(cod,(double)total));
            }
            f.sort(new ComparatorQuery9());
            r.add(f);
        }
        return r;
    }

}
