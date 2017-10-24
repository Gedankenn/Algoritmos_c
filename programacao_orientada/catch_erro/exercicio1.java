import java.util.Scanner;

public class exercicio1{

	public static void main(String[] args){
		Scanner ler = new Scanner(System.in);
		int a, b, res;

		try{
			a=ler.nextInt();
			b=ler.nextInt();

			res=a/b;

			System.out.println(a+"divido por "+b+" = "+res);
		}catch(Exception e){
			System.err.println("ocorrou um erro seu fdp"+e.toString());
		}

		System.out.println("fim do programa");
	}

}