package GestaoVendas;


import GestaoVendas.include.Control.InterfaceGestVendasControl;
import GestaoVendas.include.Model.InterfaceGestVendasModel;
import GestaoVendas.include.View.InterfaceGestVendasView;
import GestaoVendas.src.Control.Control_Imp;
import GestaoVendas.src.Model.Model_Imp;
import GestaoVendas.src.View.View_Imp;

public class GestVendasAppMVC {

    public static void main(String[] args){

        //SGV gestor = new SGV_Imp();
        InterfaceGestVendasModel model = new Model_Imp();

        InterfaceGestVendasView view = new View_Imp();

        InterfaceGestVendasControl control = new Control_Imp();

        control.setView(view);
        control.setModel(model);

        control.start();
    }
}
