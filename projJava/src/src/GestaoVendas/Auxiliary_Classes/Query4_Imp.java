package GestaoVendas.Auxiliary_Classes;

public class Query4_Imp implements Query4 {
    private int nCompras;
    private int nClientes;
    private double tFaturado;

    public Query4_Imp(){
        this.nCompras = 0;
        this.nClientes = 0;
        this.tFaturado = 0;
    }

    public int getnCompras() {
        return nCompras;
    }

    public void setnCompras(int nCompras) {
        this.nCompras = nCompras;
    }

    public int getnClientes() {
        return nClientes;
    }

    public void setnClientes(int nClientes) {
        this.nClientes = nClientes;
    }

    public double gettFaturado() {
        return tFaturado;
    }

    public void settFaturado(double tFaturado) {
        this.tFaturado = tFaturado;
    }
}
