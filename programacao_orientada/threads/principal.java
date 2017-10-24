public class principal{

public static void main(String[] args){
	Thread comHeranca =new Fluxo1();
	Thread comInterface= new Thread(new Fluxo2());

	comHeranca.start();
	comInterface.start();

	System.err.println("fim do programa");
}
}