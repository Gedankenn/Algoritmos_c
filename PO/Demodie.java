import java.util.Random;


public class Demodie{
	
	public static void main(String[] arg){
		die dado1 = new die(6);
		die dado2 = new die(6);
		int soma;

		System.out.println("dado1: "+dado1.mostra());
		System.out.println("dado1: "+dado2.mostra());

		dado1.rolar();
		dado2.rolar();
		System.out.println("dado1: "+dado1.mostra());
		System.out.println("dado1: "+dado2.mostra());	

		soma=dado1.mostra()+dado2.mostra();

		System.out.println("soma dos dado: "+soma);

	}
}

class die{
	private int face;


	public die(int n){
		Random r= new Random();
		int d=r.nextInt(n) + 1;
		face=d;
	}
	public int mostra(){
		return face;
	}

	public void rolar(){
		Random r= new Random();
		int d=r.nextInt(6) + 1;
		face=d;
	}
}