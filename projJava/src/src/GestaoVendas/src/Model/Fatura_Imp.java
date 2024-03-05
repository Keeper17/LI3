package GestaoVendas.src.Model;

import GestaoVendas.include.Model.Fatura;

public class Fatura_Imp implements Fatura {

    private String codProd;
    private double precoUnit;
    private int quantidade;
    private String tipo;
    private String codCli;
    private int mes;
    private int filial;

    public Fatura_Imp(String codProd, double precoUnit, int quantidade, String tipo, String codCli, int mes, int filial) {
        this.codProd = codProd;
        this.precoUnit = precoUnit;
        this.quantidade = quantidade;
        this.tipo = tipo;
        this.codCli = codCli;
        this.mes = mes;
        this.filial = filial;
    }

    public Fatura_Imp(Fatura f){
        this.codProd = f.getCodProd();
        this.precoUnit = f.getPrecoUnit();
        this.quantidade = f.getQuantidade();
        this.tipo = f.getTipo();
        this.codCli = f.getCodCli();
        this.mes = f.getMes();
        this.filial = f.getFilial();
    }

    public String getCodProd() {
        return codProd;
    }

    public void setCodProd(String codProd) {
        this.codProd = codProd;
    }

    public double getPrecoUnit() {
        return precoUnit;
    }

    public void setPrecoUnit(double precoUnit) {
        this.precoUnit = precoUnit;
    }

    public int getQuantidade() {
        return quantidade;
    }

    public void setQuantidade(int quantidade) {
        this.quantidade = quantidade;
    }

    public String getTipo() {
        return tipo;
    }

    public void setTipo(String tipo) {
        this.tipo = tipo;
    }

    public String getCodCli() { return codCli; }

    public void setCodCli(String codCli) { this.codCli = codCli; }

    public int getMes() {
        return mes;
    }

    public void setMes(int mes) {
        this.mes = mes;
    }

    public int getFilial() {
        return filial;
    }

    public void setFilial(int filial) {
        this.filial = filial;
    }
}
