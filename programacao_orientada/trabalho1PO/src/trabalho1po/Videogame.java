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
public class Videogame{
    private Controle[] controles;
    private int totalcontroles;
    private boolean ligar;
    private Batalhadosjipes joguinho;	


    public Videogame(){
    	controles=new Controle[4];
    	ligar=true;
    	totalcontroles=0;

    }

    public void inserecontrole(int mac){
    	if(totalcontroles<4){
    		controles[totalcontroles]=new Controle(mac);
    		joguinho.inseretanque(mac);
    		totalcontroles++;
    	}
    	else{
    		System.out.println("total controles excedido");
    	}
    }
    public void desligasaporra(){
    	this.ligar=false;
    }


    public void moverdireita(int mac){
    	for(int i=0;i<totalcontroles;i++){
    		if(mac==controles[i].getmac()){
    			joguinho.movedireita(mac);
    		}
    	}
    }
    public void moveresquerda(int mac){
    	for(int i=0;i<totalcontroles;i++){
    		if(mac==controles[i].getmac()){
    			joguinho.moveresquerda(mac);
    		}
    	}
    }
    public void acelerar(int pisa_fundo, int mac){
    	for(int i=0;i<totalcontroles;i++){
    		if(mac==controles[i].getmac()){
    			joguinho.corre_berg(pisa_fundo,mac);
    		}
    	}
    }
    public void freiar(int freia, int mac){
    	for(int i=0;i<totalcontroles;i++){
    		if(mac==controles[i].getmac()){
    			joguinho.volta_que_deu_merda_berg(freia,mac);
    		}
    	}
    }
    public void fire_in_the_hole(int mac){
    	for(int i=0;i<totalcontroles;i++){
    		if(mac==controles[i].getmac()){
    			joguinho.mete_dedo_no_gatilho_seu_viadinho(mac);
    			//controles[i].atacar;
    		}
    	}
    }

    public void sai_usuario(int mac){
    	for(int i=0;i<totalcontroles;i++){
    		if(mac==controles[i].getmac()){
    			if(totalcontroles-i==0){
    				controles[i].botcontrole();
    				totalcontroles--;
    			}
    			else{
    				controles[i]=controles[totalcontroles];
    				controles[totalcontroles].botcontrole();
    				totalcontroles--;
    			}
    		}
    	}
    }

}
