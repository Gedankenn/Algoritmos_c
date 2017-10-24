/*package introthreads;

/**
 *
 * @author Luciene
 */

public class Principal {

   
    public static void main(String[] args) {

        Barbearia ca = new Barbearia();

        ClienteProdutor cli = new ClienteProdutor(ca);
        BarbeiroConsumidor bar = new BarbeiroConsumidor(ca, 10);

        cli.start();
        bar.start();

    }

}
