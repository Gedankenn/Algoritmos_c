package barbearia;

/**
 *
 * @author Luciene
 */
public class ClienteProdutor extends Thread{

    private Barbearia ca;
    private int totalDeClientes;

    public ClienteProdutor(Barbearia c){
        this.ca = c;
        
        this.totalDeClientes = 0;
    }

    @Override
    public void run(){
        while(totalDeClientes < 10){
            try {
                // simulando a chegada de clientes na barbearia
                // Pausa por 3 segundos
                Thread.sleep(3000);
                
            } catch (InterruptedException e) {
                System.err.println(e.toString());
            }
            int id = totalDeClientes;
            ca.chegaNaBarbearia(id);
            totalDeClientes++;
        }
    }

}
