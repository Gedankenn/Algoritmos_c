package jadados;

import java.util.Random;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.Icon;
import javax.swing.JLabel;

/**
 * Esta classe precisa ser finalizada. 
 * 
 * @author Luciene
 */
public class Dado extends Thread{

    private JLabel dado;
    private int limiteDeSalto;
    private final Random r;
    private int valorSorteado;
    public boolean vai_que_da;
    private Mesa M;
    private int soma;

    public Dado(String n, JLabel d, int limiteDeSalto, int s) {
        super(n);
        this.dado = d;
        this.limiteDeSalto = limiteDeSalto;
        this.valorSorteado = 0;
        this.r = new Random();
        this.vai_que_da=true;
        this.soma=s;
    }
    
    /**
     * Carrega uma imagem do disco e transforma para Icon, ideal para ser
     * colocada em um JLabel
     * @param valor número inteiro de 1 a 6 que corresponde as seis imagens
     * de dado que estao no pacote jadados.resources
     * @return 
     */
    public Icon carregaImagem(int valor){
        return (new javax.swing.ImageIcon(getClass().getResource("/jadados/resources/" + valor + ".png")));
    }
    
    /**
     * Este método está incompleto
     */
    @Override
    public void run() {
        
        synchronized(soma){
            
        }
        long inicio = System.currentTimeMillis();
        System.out.println(this.getName()+" :Coloque tua logica aqui: " + inicio);
        // alterando a figura do dado
        int cont=0;
        int qual = r.nextInt(6)+1;
        this.dado.setIcon(this.carregaImagem(qual));
        while(this.limiteDeSalto>cont){
            qual = r.nextInt(6)+1;
            /* No lancamento dos dados cada face deve aparecer na tela por 100ms
            antes de ser substituída, simulando assim um dado ao ser jogado.
            Esta lógica precisa ser implementada.
             */
            this.dado.setIcon(this.carregaImagem(qual));
            try {
                Thread.sleep(300);
            } catch (InterruptedException ex) {
                Logger.getLogger(Dado.class.getName()).log(Level.SEVERE, null, ex);
            }
            cont++;
        }
        
        

        
        long fim = System.currentTimeMillis();
        System.out.println(this.getName() +" :Fim: " + fim);
        
        // registra o valor que o dado parou
        this. valorSorteado = qual;
        System.out.println(this.getName() +": valor: " + this.valorSorteado);
        //notify();
        this.vai_que_da=false;
        //notifyAll()
    }

    public int getValorSorteado() {
      //  try {
            //wait();
            //return valorSorteado;
      //  } catch (InterruptedException ex) {
      //      Logger.getLogger(Dado.class.getName()).log(Level.SEVERE, null, ex);
      //  }
        //run();
        //notify();
        //while(vai_que_da==true){
           /* try {
                wait();
            } catch (InterruptedException ex) {
                Logger.getLogger(Dado.class.getName()).log(Level.SEVERE, null, ex);
            }*/
        //}
        return valorSorteado;
    }
    
    
    
}
