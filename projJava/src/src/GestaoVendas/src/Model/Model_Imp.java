package GestaoVendas.src.Model;

import GestaoVendas.Auxiliary_Classes.Exceptions.ModelException;
import GestaoVendas.include.Model.*;
import GestaoVendas.Auxiliary_Classes.*;


import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;

public class Model_Imp implements InterfaceGestVendasModel {


    /*Variáveis de Instância*/
    private CatProdutos cp;
    private CatClientes cc;
    private Filiais fil;
    private Faturacao fat;
    private PopulationInfo pinfo;

    /*Construtor Vazio*/
    public Model_Imp(){
        cp = new CatProdutos_Imp();
        cc = new CatClientes_Imp();
        fat = new Faturacao_Imp();
        fil = new Filiais_Imp();
        pinfo = new PopulationInfo_Imp();
    }

    /*Implementação a utilizar Buffered Reader*/
    public void readInputFiles(String PrdPath, String CliPath, String SalPath) throws ModelException {

        BufferedReader bf1;
        String line;

        int t = 0;
        int v = 0;

        /*Preencher produtos*/
        try{
            bf1 = new BufferedReader(new FileReader(PrdPath));
            while((line = bf1.readLine()) != null){
                Produto p = new Produto_Imp(line);
                if(p.isValid()){
                    cp.addProduto(p);
                    v++;
                }
                t++;
            }
            this.pinfo.setPt(t);
            this.pinfo.setPv(v);
            bf1.close();
        }
        catch (IOException e){
            throw new ModelException("Produtos");
        }

        t = 0;
        v = 0;

        /*Preencher clientes*/
        try{
            bf1 = new BufferedReader(new FileReader(CliPath));
            while((line = bf1.readLine()) != null){
                Cliente c = new Cliente_Imp(line);
                if(c.isValid()){
                    cc.addCliente(c);
                    v++;
                }
                t++;
            }
            this.pinfo.setCt(t);
            this.pinfo.setCv(v);
            bf1.close();
        }
        catch (IOException e){
            throw new ModelException("Clientes");
        }

        t = 0;
        v = 0;

        /*Preencher Vendas*/
        try{
            bf1 = new BufferedReader(new FileReader(SalPath));
            while((line = bf1.readLine()) != null){
                String[] fields = line.split(" ");
                Fatura f;
                Filial_Info fi;
                if(cc.existeCliente(new Cliente_Imp(fields[4])) && cp.existeProduto(new Produto_Imp(fields[0])) && validateLine(fields)){
                    f = new Fatura_Imp(fields[0], Double.parseDouble(fields[1]), Integer.parseInt(fields[2]),
                            fields[3], fields[4], Integer.parseInt(fields[5]), Integer.parseInt(fields[6]));
                    fi = new Filial_Info_Imp(fields[0], Integer.parseInt(fields[2]), Float.parseFloat(fields[1]),
                            fields[3], Integer.parseInt(fields[5]), Integer.parseInt(fields[6]));
                    fat.addFatura(f);
                    fil.addInfo(fi, new Cliente_Imp(fields[4]));
                    v++;
                }
                t++;
            }
            this.pinfo.setVt(t);
            this.pinfo.setVv(v);
            bf1.close();
        }
        catch (IOException e){
            throw new ModelException("Vendas");
        }

        pinfo.setPrdPath(PrdPath);
        pinfo.setCliPath(CliPath);
        pinfo.setVndPath(SalPath);

    }

    public PopulationInfo getPinfo(){
        return this.pinfo;
    }

    public StatsQ2 statisticalQ2(){

        StatsQ2 sq2 = new StatsQ2();

        fil.setInfoStatQuery2Fil(sq2);
        fat.setInfoStatQuery2Fat(sq2);

        return sq2;
    }

    private boolean validateLine(String[] fields){
        try{
            return Double.parseDouble(fields[1]) > 0 &&
                    Integer.parseInt(fields[2]) > 0 &&
                    (fields[3].compareTo("P") == 0 || fields[3].compareTo("N") == 0) &&
                    (Integer.parseInt(fields[5]) >= 1 && Integer.parseInt(fields[5]) <= 12) &&
                    (Integer.parseInt(fields[6]) >= 1 && Integer.parseInt(fields[6]) <= 3);
        }
        catch(NumberFormatException e){
            return false;
        }
    }

    public List<String> prodsNotBought(){
        List<String> prods = cp.toListString();
        List<String> ret = new ArrayList<>();

        for(String p : prods){
            if(!fat.prodBought(new Produto_Imp(p))){
                ret.add(p);
            }
        }
        java.util.Collections.sort(ret);
        return ret;
    }

    public List<Query4> prodsBoughtByMonth(String cod){
        Query4[] array = new Query4[12];
        for(int i=0; i < array.length; i++)
            array[i] = new Query4_Imp();

        List<Query4> prods = Arrays.asList(array);

        fat.query4Aux(cod, prods);

        return prods;
    }

    public Set<StringInt> clientPurchases(String cod){

        if((new Cliente_Imp(cod)).isValid()){
            return this.fil.getInfoQuery5(new Cliente_Imp(cod));
        }
        else return null;
    }

    public List<StringInt2> prodsMostBought(){
        return this.fat.getInfoQuery6();
    }

    public List<StringInt> clientsByDiffProdsBought(){
        return this.fil.getInfoQuery8();
    }

    public List<StringDouble> prodMostBoughtClients(String cod) { return this.fat.getInfoQuery9(cod); }

    public List<Query10> totalFat() {return this.fat.getInfoQuery10(); }
}
