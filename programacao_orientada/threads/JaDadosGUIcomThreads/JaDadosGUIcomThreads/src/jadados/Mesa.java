/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package jadados;

/**
 *
 * @author gedan
 */
public class Mesa {
    private boolean ocupada;
    
    public Mesa(){
        ocupada=false;
    }
    
    public synchronized void dado1(){
        while(ocupada==false)
    }
}
