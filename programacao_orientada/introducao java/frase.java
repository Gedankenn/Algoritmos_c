import java.util.Scanner;

public class frase{
	public static void main(String[] args){
		Scanner teclado = new Scanner(System.in);

		int i = teclado.nextInt();
		double r = teclado.nextDouble();
		String s = teclado.nextLine();

		System.out.println("inteiro: "+i+", real: "+r);
		System.out.println("frase: "+ s);
	}
}