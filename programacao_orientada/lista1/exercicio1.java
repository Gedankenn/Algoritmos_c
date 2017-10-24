import java.util.Scanner;

public class exercicio1{
	public static void main(String[] args){
		Scanner tec = new Scanner(System.in);

		int num = tec.nextInt();
		int cont=1;

		while(cont<num){
			System.out.printf(cont+" ");
			cont=cont+2;
		}
	}

}