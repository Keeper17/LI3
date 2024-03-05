package GestaoVendas.src.Model;

import GestaoVendas.include.Model.Filial_Info;

public class Filial_Info_Imp implements Filial_Info {
    private String codProd;
    private Integer quantidade;
    private float preco;
    private String tipo;
    private int mes;
    private Integer filial;


    public Filial_Info_Imp(String cod, Integer quantidade, float preco, String tipo, int mes, Integer filial) {
        this.codProd = cod;
        this.quantidade = quantidade;
        this.preco = preco;
        this.tipo = tipo;
        this.mes = mes;
        this.filial = filial;
    }

    public Filial_Info_Imp(Filial_Info f){
        this.codProd = f.getCodProd();
        this.quantidade = f.getQuantidade();
        this.preco = f.getPreco();
        this.tipo = f.getTipo();
        this.mes = f.getMes();
        this.filial = f.getFilial();
    }

    public String getCodProd() {
        return codProd;
    }

    public void setCodProd(String codProd) {
        this.codProd = codProd;
    }

    public Integer getQuantidade() {
        return quantidade;
    }

    public void setQuantidade(Integer quantidade) {
        this.quantidade = quantidade;
    }

    public float getPreco() {
        return preco;
    }

    public void setPreco(float preco) {
        this.preco = preco;
    }

    public String getTipo() {
        return tipo;
    }

    public void setTipo(String tipo) {
        this.tipo = tipo;
    }

    public int getMes() { return mes; }

    public void setMes(int mes) { this.mes = mes; }

    public Integer getFilial() { return filial; }

    public void setFilial(Integer filial) { this.filial = filial; }
}
