public class Fluxo1 extends Thread{

	@Override
	public void run(){
		for(int i=0; i < 1000; i++){
			if (i % 10 == 0){
				System.err.println("Fazendo uso de heranca");
			}
		}
	}

}
