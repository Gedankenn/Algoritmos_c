package fluxos;
public class Fluxo1 extends Thread{

	@Override
	public void run(){
		for(int i=0; i < 1000; i++){
				System.err.println("Fazendo uso de heranca");
		}
	}

}
