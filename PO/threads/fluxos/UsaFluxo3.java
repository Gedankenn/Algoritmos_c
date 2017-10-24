package fluxos;
public class UsaFluxo3{

	public static void main(String[] args){

	 Thread f3 = new Fluxo3("Fluxo3");

	 //disparando a thread
	 f3.start() ;
	 System.err.println ("Depois do start e antes do join") ;
	 try {
		 f3.join( ) ;
		 // a linha abaixo e’ executada somente depois
		 // de finalizar o metodo run do objeo f3
		 System.err.println("Depois do join") ;

		 }catch ( InterruptedException ex ) {
			System.err.println ( ex.toString ( ) ) ;
		 }
		 System.err.println ("Fim do programa") ;		
	}

}