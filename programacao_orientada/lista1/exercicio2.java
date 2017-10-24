import java.util.Scanner;

public class exercicio2{
	public static void main(String[] args){
		Scanner tec = new Scanner(System.in);

		int num = tec.nextInt();
		int cont=2;
		int raiz;
		int cont2=1;

		while(cont2*cont2<num){
			cont2++;
		}

		raiz=cont2;
		cont2=0;

		while((cont*(num/cont))!=num && cont<raiz){
			cont++;
		}
		if(cont==raiz){
			System.out.println("o numero eh primo");
		}
		else{
			System.out.println("o numero nao eh primo");
		}
	}
}