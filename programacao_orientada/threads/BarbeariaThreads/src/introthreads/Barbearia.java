/*package introthreads;

/**
 *
 * @author Luciene
 */
public class Barbearia {

    private boolean ocupada;
    private int cliente;

    public Barbearia() {
        this.ocupada = false;
    }

    // metodo invocado pelo barbeiro ao notar que tem cliente na cadeira
    public synchronized void cortaCabelo() {
        while (ocupada == false) {
            try {
                // se ninguem sentou na cadeira, espere até alguém sentar
                // se nao tiver cliente, barbeiro tira um cochilo...
                System.err.println("Barbeiro tirando cochilo...");
                wait();
            } catch (InterruptedException e) {
                System.err.println(e.toString());
            }
        }
        // se saiu do while é pq alguém sentou, então corte o cabelo do cliente
        // e libere a cadeira
        try {
            System.err.println("Barbeiro está cortando o cabelo do cliente " + cliente);
            //Thread.sleep((int)(Math.random() * 3000));
            // Pause de 4 segundos
            Thread.sleep(4000);
        } catch (InterruptedException e) {
            System.err.println(e.toString());
        }
        System.err.println("Pronto, mais um cliente satisfeito...");
        ocupada = false;
        // avisar a thread produtora (Cliente) que a cadeira do barbeiro está vazia
        notify();
    }

    // metodo invocado pelo Cliente que chega no salao
    public synchronized void chegaNaBarbearia(int id) {
        //enquanto a cadeira estiver ocupada, aguarde sua vez
        while (ocupada == true) {
            try {
                // espere até o cliente atual sair da cadeira do barbeiro
                System.err.println("Cliente "+ id + " chegou na barbearia e espera sua vez");
                wait();
            } catch (InterruptedException e) {
                System.err.println(e.toString());
            }
        }
        // cadeira livre! Fazer com que o cliente sente na cadeira para ser
        // atendido
        System.err.println("Cliente "+ id + " sentou na cadeira do barbeiro...");
        cliente = id;
        ocupada = true;
        // avisar a thread consumidor (Barbeiro) que tem cliente na cadeira
        notify();
    }
}
