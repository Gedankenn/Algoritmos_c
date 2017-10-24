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
public class Batalhadosjipes {
  	private  Tanque[] tanques;
    private  int totaltanques;

    public Batalhadosjipes(){
    	tanques= new Tanque[4];
    	totaltanques=0;
    }

    public void inseretanque(int mac){
    	if(totaltanques<4){
    		tanques[totaltanques]=new Tanque(100,20,mac);
    		totaltanques++;
    	}
    	else{
    		System.out.println("ja tem tanque demais");
    	}
    }

    public void movedireita(int mac){
    	for(int i=0;i<totaltanques;i++){
    		if(tanques[i].getmac()==mac){
    			tanques[i].moverdireita();
    		}
    	}
    }
    public void moveresquerda(int mac){
    	for(int i=0;i<totaltanques;i++){
    		if(tanques[i].getmac()==mac){
    			tanques[i].moveesquerda();
    		}
    	}
    }
    public void corre_berg(int puta_merda_quanta_variavel, int mac){
    	for(int i=0;i<totaltanques;i++){
    		if(tanques[i].getmac()==mac){
    			tanques[i].tacale_pau_marco_veio(puta_merda_quanta_variavel);
    		}
    	}
    }
    public void volta_que_deu_merda_berg(int caceta_falei_pra_voltar_porra, int mac){
    	for(int i=0;i<totaltanques;i++){
    		if(tanques[i].getmac()==mac){
    			tanques[i].freia_demonio(caceta_falei_pra_voltar_porra);
    		}
    	}
    }
    public void mete_dedo_no_gatilho_seu_viadinho(int mac){
    	for(int i=0;i<totaltanques;i++){
    		if(tanques[i].getmac()==mac){
    			tanques[i].mete_bala_no_rabo_deles();
    		}
    	}
    }
    public void desertor_viadinho(int mac){
    	for(int i=0;i<totaltanques;i++){
    		if(tanques[i].getmac()==mac){
    			if(totaltanques-i==0){
    				totaltanques--;
    			}
    			else{
    				tanques[i]=tanques[totaltanques];
    				totaltanques--;
    			}
    		}
    	}

    }
}
