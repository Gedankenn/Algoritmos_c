import java.util.Random;

public class exercicio5{
	public static void main(String[] args){

		int[] vet = new int[10];
		int cont;
		Random r = new Random();

		cont=0;
		while(cont<10){
			vet[cont]=r.nextInt(10);
			cont++;
		}
		cont=0;
		while(cont<10){
			System.out.printf(vet[cont]+" ");
			cont++;
		}
		int i=0;
		int j=0;
		int aux;

		while(i<10){
			j=0;
			while(j<9){
				if(vet[j]>vet[j+1]){
					aux=vet[j];
					vet[j]=vet[j+1];
					vet[j+1]=aux;
				}
				j++;
			}
			i++;
		}
		System.out.println(" ");
		cont=0;
		while(cont<10){
			System.out.printf(vet[cont]+" ");
			cont++;
		}
	}
}