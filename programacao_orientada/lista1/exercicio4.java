import java.util.Scanner;

public class exercicio4{
	public static void main(String[] args){
		Scanner tec = new Scanner(System.in);

		int cont=2;
		int num = tec.nextInt();
		int cont2=1;
		int cont3;

		while(cont<=num){
			cont2=1;
			while(cont2*cont2<cont && cont != 4){
				cont2=cont2+1;
			}
			cont3=2;
			while((cont3*(cont/cont3))!=cont && cont3<cont2){
				cont3++;
			}
			if(cont3==cont2){
				System.out.printf(cont+" ");
			}
			cont++;
		}
	}
}