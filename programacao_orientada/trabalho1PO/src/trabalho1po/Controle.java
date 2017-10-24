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
public class Controle {
    private int mac;
    private boolean atirar;
    private boolean botaocontrole;
    
    
    public Controle(int a){
        this.mac=a;
        this.atirar=false;
        this.botaocontrole=true;
    }
    
    public int getmac(){
        return this.mac;
    }
    public void atacar() {
      this.atirar = !this.atirar;
   }
   public void botcontrole(){
    this.botaocontrole =!this.botaocontrole;
   }
}
