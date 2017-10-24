/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
//package trabalho1po;

/**
 *
 * @author gedan
 */
public class Tanque {
    private int combustivel;
    private int municao;
    private int mac;
    private boolean direita;
    private boolean esquerda;
    private int acelera;


    public Tanque(int c, int m, int mc){
    	this.combustivel=c;
    	this.municao=m;
    	this.mac=mc;
    	this.direita=false;
    	this.esquerda=false;
    	this.acelera=0;
    }

    public int getmac(){
    	return this.mac;
    }

    public void moverdireita(){
    	this.esquerda=false;
    	this.direita=true;
    	this.combustivel--;
    }
    public void moveesquerda(){
    	this.esquerda=true;
    	this.direita=false;
    	this.combustivel--;
    }
    public void tacale_pau_marco_veio(int morro_da_vo_sovelina){
    	this.acelera=morro_da_vo_sovelina+this.acelera;
    	this.combustivel--;
    }
    public void freia_demonio(int nois_capota_ma_nao_breka){
    	this.acelera=this.acelera+nois_capota_ma_nao_breka;
    }
    public void mete_bala_no_rabo_deles(){
    	this.municao--;

    }
}
