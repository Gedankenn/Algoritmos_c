public class Fluxo2 implements Runnable{

	public void run(){
		for(int i=0; i < 1000; i++){
			if (i % 100 == 0){
				System.err.println("Fazendo uso de interface");
			}
		}
	}

}
