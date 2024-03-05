package GestaoVendas.src.Control;

import GestaoVendas.Auxiliary_Classes.*;
import GestaoVendas.Auxiliary_Classes.Exceptions.ModelException;
import GestaoVendas.include.Control.InterfaceGestVendasControl;
import GestaoVendas.include.Model.InterfaceGestVendasModel;
import GestaoVendas.include.View.InterfaceGestVendasView;
import GestaoVendas.src.Model.Model_Imp;

import java.util.ArrayList;
import java.util.List;
import java.util.Set;

public class Control_Imp implements InterfaceGestVendasControl {
    private InterfaceGestVendasView view;
    private InterfaceGestVendasModel model;


    public InterfaceGestVendasView getView() {
        return view;
    }

    public void setView(InterfaceGestVendasView view) {
        this.view = view;
    }

    public InterfaceGestVendasModel getModel() {
        return model;
    }

    public void setModel(InterfaceGestVendasModel model) {
        this.model = model;
    }

    public void start(){
        do{
            this.view.printMenu();
            this.model = menu();
        }while(this.model != null);
    }

    public InterfaceGestVendasModel menu(){

        String opcao;
        opcao = Input.lerString();

        switch(opcao.trim().charAt(0)){
            case 'a' : { this.queryEst1(); break; }
            case 'b' : { this.queryEst2(); break; }
            case '0' : { this.model = readInputFiles(); break; }
            case '1' : {
                switch (opcao.trim().charAt(1)) {
                    case '\n': { this.queryInt1(); break; }
                    case '0': { this.queryInt10(); break; }
                    default: break;
                }
                break;
            }
            case '2' : break;
            case '3' : break;
            case '4' : { this.queryInt4(); break; }
            case '5' : { this.queryInt5(); break; }
            case '6' : { this.queryInt6(); break; }
            case '7' : break;
            case '8' : { this.queryInt8(); break; }
            case '9' : { this.queryInt9(); break; }
            case 'q' : return null;
            default : break;
        }

        return model;
    }



    /*READ INPUT FILES*/

    public InterfaceGestVendasModel readInputFiles(){

        /*Apagar o que estava no SGV até agora, se alguma coisa, e reinicializá-lo*/
        this.model = null;
        this.model = new Model_Imp();

        String inst;

        view.printRIF1();
        inst = Input.lerString();

        switch (inst.trim().charAt(0)){
            case 'd' : {
                try{
                    model.readInputFiles("Input_Files/Produtos.txt", "Input_Files/Clientes.txt", "Input_Files/Vendas_1M.txt");
                    view.printRIF_Suc();
                }
                catch (ModelException e){
                    view.printRIF_Fail(e.getMessage());
                }
                break;
            }
            case 'n' : {
                String pp, cp, vp;
                view.printRIF2();
                pp = Input.lerString();
                cp = Input.lerString();
                vp = Input.lerString();

                try{
                    model.readInputFiles(pp,cp,vp);
                    view.printRIF_Suc();
                }catch (ModelException e){
                    view.printRIF_Fail(e.getMessage());
                }
                break;
            }
            default: {
                view.printRIF_Fail("NO INPUT FILES");
            }
        }

        return model;
    }

    /*QUERIES ESTATÍSTICAS*/

    public void queryEst1(){

        view.printQE1(this.model.getPinfo());

    }

    public void queryEst2(){
        StatsQ2 sq2 = model.statisticalQ2();

        view.printQE2(sq2);
    }


    /*QUERIES INTERATIVAS*/

    public void queryInt1(){
        List<String> l = this.model.prodsNotBought();
        this.iterateStringList(l);
    }


    public void queryInt4(){
        view.printQI4();
        String cod = Input.lerString();

        //Query4_Imp[] array = new Query4_Imp[12];
        List<Query4> prods; //Arrays.asList(array);

        prods = this.model.prodsBoughtByMonth(cod);

        view.printQI4R(prods);
    }


    public void queryInt5(){

        view.printQI5();

        String cod = Input.lerString();

        Set<StringInt> s = this.model.clientPurchases(cod);

        if(s != null){
            List<StringInt> s2 = new ArrayList<>(s);
            this.iterateStringIntList(s2);
        }
        else{
            this.view.printQI5F();
        }

    }

    public void queryInt6(){
        view.printQI6();
        int num = Input.lerInt();

        List<StringInt2> l = this.model.prodsMostBought();

        if(num < l.size()){
            l = l.subList(0, num);
        }

        this.iterateStringIntList2(l);
    }

    public void queryInt8(){

        view.printQI8();

        int size = Input.lerInt();

        List<StringInt> l = model.clientsByDiffProdsBought();

        if(size < l.size()){
            l = l.subList(0, size);
        }

        this.iterateStringIntList(l);

    }

    public void queryInt9(){
        view.printQI9a();
        String cod = Input.lerString();
        view.printQI9b();
        int num = Input.lerInt();

        List<StringDouble> l = this.model.prodMostBoughtClients(cod);

        if (num < l.size()) {
            l = l.subList(0, num);
        }

        this.iterateStringDoubleList(l);
    }

    public void queryInt10(){
        List<Query10> list = this.model.totalFat();

        this.iterateListQuery10(list);
    }

    /*FUNÇÕES AUXILIARES*/

    private void iterateStringList( List<String> l ){

        int step = 20;
        int page = 0;
        char inst;

        //Print list size, always
        view.printSize(l.size());

        //Print part of a list
        //first, the beginning
        view.printBigList(l, page, step);


        //then, print the rest
        while((inst = Input.lerString().charAt(0)) != 'q'){
            switch(inst){
                case 'a' : {
                    if(page > 0) page--;
                    break;
                }
                case 'p' : {
                    if(((page+1) * step) < l.size()) page++;
                    break;
                }
                default : break;
            }
            //Print list size, always
            view.printSize(l.size());
            view.printBigList(l, page * step, (page+1) * step);
        }
    }

    private void iterateStringIntList( List<StringInt> l ){
        int step = 20;
        int page = 0;
        char inst;

        //Print list size, always
        view.printSize(l.size());

        //Print part of a list
        //first, the beginning
        view.printBigListSI(l, page, step);

        //then, print the rest
        while((inst = Input.lerString().charAt(0)) != 'q'){
            switch(inst){
                case 'a' : {
                    if(page > 0) page--;
                    break;
                }
                case 'p' : {
                    if(((page+1) * step) < l.size()) page++;
                    break;
                }
                default : break;
            }
            //Print list size, always
            view.printSize(l.size());
            view.printBigListSI(l, page * step, (page+1) * step);
        }
    }

    private void iterateStringIntList2( List<StringInt2> l ) {
        int step = 20;
        int page = 0;
        char inst;

        //Print list size, always
        view.printSize(l.size());

        //Print part of a list
        //first, the beginning
        view.printBigListSI2(l, page, step);

        //then, print the rest
        while ((inst = Input.lerString().charAt(0)) != 'q') {
            switch (inst) {
                case 'a': {
                    if (page > 0) page--;
                    break;
                }
                case 'p': {
                    if (((page + 1) * step) < l.size()) page++;
                    break;
                }
                default:
                    break;
            }
            //Print list size, always
            view.printSize(l.size());
            view.printBigListSI2(l, page * step, (page + 1) * step);
        }
    }

    private void iterateStringDoubleList( List<StringDouble> l ){
        int step = 20;
        int page = 0;
        char inst;

        //Print list size, always
        view.printSize(l.size());

        //Print part of a list
        //first, the beginning
        view.printBigListSD(l, page, step);

        //then, print the rest
        while((inst = Input.lerString().charAt(0)) != 'q'){
            switch(inst){
                case 'a' : {
                    if(page > 0) page--;
                    break;
                }
                case 'p' : {
                    if(((page+1) * step) < l.size()) page++;
                    break;
                }
                default : break;
            }
            //Print list size, always
            view.printSize(l.size());
            view.printBigListSD(l, page * step, (page+1) * step);
        }
    }

    private void iterateListQuery10(List<Query10> list){
        int i = 0;
        char inst;

        view.printCodProd(list.get(i).getCodProd());

        view.printOneEntry(list, i);

        while((inst = Input.lerString().charAt(0)) != 'q'){
            switch (inst){
                case 'a' : {
                    if (i > 0) i--;
                    break;
                }
                case 'p' : {
                    if ((i+1) < list.size()) i++;
                    break;
                }
                default : break;
            }
            view.printCodProd(list.get(i).getCodProd());
            view.printOneEntry(list, i);
        }
    }

}
