import java.util.Scanner;

public class jogo{
	public static void main(Strings[], args){
		Scanner tc = new Scanner(System.in);
		System.out.println("ensira numero de jogadores: ");
		int num=tc.nextInt();
		OO_videogame console = new OO_videogame(num);

		int menu=0;

		while(menu!=-1){
			console.comando();
			
			System.out.println("ensira -1 para desligar: ");
			menu=tc.nextInt();
		}


	}
}