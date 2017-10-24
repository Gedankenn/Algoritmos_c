package fluxos;
public class Fluxo3 extends Thread{

 public Fluxo3 ( String nome){
	super (nome) ;
 }

    public void run ( ){
	 try {
		System.err.println(this.getName( ) + " vair dormir . . .");
		Thread.sleep(1000) ;

	 }catch (InterruptedException e ){
		System.err.println(e.toString( )); 
	 }
	 System.err.println(this.getName( ) + " acordou . . . ");
	}
 }