//package introthreads;

/*/**
 *
 * @author Luciene
 */
public class BarbeiroConsumidor extends Thread{

    private Barbearia ca;
    private int totalDeClientesQueIreiAtender;


    public BarbeiroConsumidor(Barbearia c, int tot){
        this.ca = c;
        this.totalDeClientesQueIreiAtender = tot;
    }

    @Override
    public void run(){
        // ao atingir o limite, o barbeiro vai pra casa e não atende mais ninguém
        while(totalDeClientesQueIreiAtender > 0){
            try {
                System.out.println("Barbeiro dormindo..." );
                //Thread.sleep((int) (Math.random() * 3000));
                // Barbeiro dormindo por 5 segundos
                Thread.sleep((int) (5000));
                
            } catch (InterruptedException e) {
                System.err.println(e.toString());
            }
            ca.cortaCabelo();
            totalDeClientesQueIreiAtender--;
        }
        System.err.println("\n\nBarbeiro foi pra casa, chega de trabalho por hoje.\n");
    }
}
