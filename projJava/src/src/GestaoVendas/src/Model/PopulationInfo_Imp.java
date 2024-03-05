package GestaoVendas.src.Model;

import GestaoVendas.include.Model.PopulationInfo;

public class PopulationInfo_Imp implements PopulationInfo {

    String cliPath;
    String vndPath;
    String prdPath;
    int pt, ct, vt, pv, cv, vv;

    public PopulationInfo_Imp(){
        this.prdPath = this.cliPath = this.vndPath = "";
        this.pt = this.ct = this.vt = -1;
        this.pv = this.cv = this.vv = -1;
    }

    public String getPrdPath() {
        return prdPath;
    }

    public void setPrdPath(String prdPath) {
        this.prdPath = prdPath;
    }

    public String getCliPath() {
        return cliPath;
    }

    public void setCliPath(String cliPath) {
        this.cliPath = cliPath;
    }

    public String getVndPath() {
        return vndPath;
    }

    public void setVndPath(String vndPath) {
        this.vndPath = vndPath;
    }

    public int getPt() {
        return pt;
    }

    public void setPt(int pt) {
        this.pt = pt;
    }

    public int getCt() {
        return ct;
    }

    public void setCt(int ct) {
        this.ct = ct;
    }

    public int getVt() {
        return vt;
    }

    public void setVt(int vt) {
        this.vt = vt;
    }

    public int getPv() {
        return pv;
    }

    public void setPv(int pv) {
        this.pv = pv;
    }

    public int getCv() {
        return cv;
    }

    public void setCv(int cv) {
        this.cv = cv;
    }

    public int getVv() {
        return vv;
    }

    public void setVv(int vv) {
        this.vv = vv;
    }


}
