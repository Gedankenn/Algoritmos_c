public class Principal{

	public static void main(String[] args){

		Fluxo1 f1 = new Fluxo1();
		Fluxo2 f2 = new Fluxo2();

		System.err.println("Inicio do programa");

		//disparando os processos
		f1.disparar();
		f2.disparar();

		System.err.println("Fim do programa");

	}

}
