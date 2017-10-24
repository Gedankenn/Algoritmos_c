import java.util.Scanner;

public class exercicio6{
	public static void main(String[] args){
		Scanner tec = new Scanner(System.in);

		int i=0;
		int j=0;
		int aux;
		int cont;


		int num=tec.nextInt();

		j=(2*num)-1;
		int[][] matriz= new int[num][j];


		cont=0;
		aux=0;
		while(aux<num){
			i=aux;
			while(i<j-aux){
				matriz[aux][i]=1;
				i++;
			}
			aux++;
		}

		i=0;
		aux=0;

		while(aux<num){
			i=0;
			while(i<j){
				System.out.printf(" "+matriz[aux][i]);
				i++;
			}
			System.out.println(" ");
			aux++;
		}

	}
}