package fluxos;
public class UsaFluxo1Fluxo2{

	public static void main(String[] args){

		Thread comHeranca   = new Fluxo1();
		Thread comInterface = new Thread(new Fluxo2());

		//disparando as threads
		comHeranca.start();
		comInterface.start();
		
		System.err.println("Fim do programa"); 

	}

}
