import java.util.Scanner;
public class velha{
	private String[][] tabuleiro = new String[3][3];
	private int cont2=0;

	public void inicializa(){
		int cont=0;
		while(cont<3){
			tabuleiro[cont][0]=" ";
			tabuleiro[cont][1]=" ";
			tabuleiro[cont][2]=" ";
			cont++;
		}
	}
	public void printatabuleiro(){
		int cont=0;
		while(cont<3){
			System.out.println("|"+tabuleiro[cont][0]+"|"+tabuleiro[cont][1]+"|"+tabuleiro[cont][2]+"|");
			cont++;
		}
	}
	public void jogada(){
		System.out.println("insira sua jogada:");
		Scanner tc = new Scanner(System.in);
		int x = tc.nextInt();
		int y = tc.nextInt();

		while(tabuleiro[x][y]!=" "){
			System.out.println("jogada invalida, tente dnovo");
			x= tc.nextInt();
			y= tc.nextInt();
		}

		tabuleiro[x][y]="x";
		cont2++;
	}
	public int aijogada(){
		cont2++;
		if(tabuleiro[0][0]==" "){
			tabuleiro[0][0]="o";
			return 0;
		}

		else if(tabuleiro[0][1]=="x" && tabuleiro[1][1]=="x" && tabuleiro[2][1]==" "){
			tabuleiro[2][1]="o";
			return 0;
		}
		else if(tabuleiro[0][1]==" " && tabuleiro[1][1]=="x" && tabuleiro[2][1]=="x"){
			tabuleiro[0][1]="o";
			return 0;
		}
		else if(tabuleiro[0][1]=="x" && tabuleiro[1][1]==" " && tabuleiro[2][1]=="x"){
			tabuleiro[1][1]="o";
			return 0;
		}
		else if(tabuleiro[0][0]=="x" && tabuleiro[0][2]=="x" && tabuleiro[0][1]==" "){
			tabuleiro[0][1]="o";
			return 0;
		}
		else if(tabuleiro[1][0]=="x" && tabuleiro[1][1]=="x" && tabuleiro[1][2]==" "){
			tabuleiro[1][2]="o";
			return 0;
		}
		else if(tabuleiro[1][0]==" " && tabuleiro[1][1]=="x" && tabuleiro[1][2]=="x"){
			tabuleiro[1][0]="o";
			return 0;
		}
		else if(tabuleiro[1][0]=="x" && tabuleiro[1][1]==" " && tabuleiro[1][2]=="x"){
			tabuleiro[1][1]="o";
			return 0;
		}
		else if(tabuleiro[0][0]==" " && tabuleiro[0][2]=="x" && tabuleiro[0][1]=="x"){
			tabuleiro[0][0]="o";
			return 0;
		}
		else if(tabuleiro[0][0]=="x" && tabuleiro[0][2]==" " && tabuleiro[0][1]=="x"){
			tabuleiro[0][2]="o";
			return 0;
		}
		else if(tabuleiro[0][0]=="x" && tabuleiro[2][0]=="x" && tabuleiro[1][0]==" "){
			tabuleiro[1][0]="o";
			return 0;
		}
		else if(tabuleiro[0][0]=="x" && tabuleiro[2][0]==" " && tabuleiro[1][0]=="x"){
			tabuleiro[2][0]="o";
			return 0;
		}
		else if(tabuleiro[0][0]==" " && tabuleiro[2][0]=="x" && tabuleiro[1][0]=="x"){
			tabuleiro[0][0]="o";
			return 0;
		}
		else if(tabuleiro[0][0]=="x" && tabuleiro[2][2]=="x" && tabuleiro[1][1]==" "){
			tabuleiro[1][1]="o";
			return 0;
		}
		else if(tabuleiro[0][0]==" " && tabuleiro[2][2]=="x" && tabuleiro[1][1]=="x"){
			tabuleiro[0][0]="o";
			return 0;
		}
		else if(tabuleiro[0][0]=="x" && tabuleiro[2][2]==" " && tabuleiro[1][1]=="x"){
			tabuleiro[2][2]="o";
			return 0;
		}
		else if(tabuleiro[2][0]=="x" && tabuleiro[2][2]=="x" && tabuleiro[2][1]==" "){
			tabuleiro[2][1]="o";
			return 0;
		}
		else if(tabuleiro[2][0]==" " && tabuleiro[2][2]=="x" && tabuleiro[2][1]=="x"){
			tabuleiro[2][0]="o";
			return 0;
		}
		else if(tabuleiro[2][0]=="x" && tabuleiro[2][2]==" " && tabuleiro[2][1]=="x"){
			tabuleiro[2][2]="o";
			return 0;
		}
		else if(tabuleiro[0][2]=="x" && tabuleiro[2][2]=="x" && tabuleiro[1][2]==" "){
			tabuleiro[1][2]="o";
			return 0;
		}
		else if(tabuleiro[0][2]==" " && tabuleiro[2][2]=="x" && tabuleiro[1][2]=="x"){
			tabuleiro[0][2]="o";
			return 0;
		}
		else if(tabuleiro[0][2]=="x" && tabuleiro[2][2]==" " && tabuleiro[1][2]=="x"){
			tabuleiro[2][2]="o";
			return 0;
		}
		else if(tabuleiro[0][2]=="x" && tabuleiro[2][0]=="x" && tabuleiro[1][1]==" "){
			tabuleiro[1][1]="o";
			return 0;
		}
		else if(tabuleiro[0][2]==" " && tabuleiro[2][0]=="x" && tabuleiro[1][1]=="x"){
			tabuleiro[0][2]="o";
			return 0;
		}
		else if(tabuleiro[0][2]=="x" && tabuleiro[2][0]==" " && tabuleiro[1][1]=="x"){
			tabuleiro[2][0]="o";
			return 0;
		}
		else if(tabuleiro[0][0]=="x" && tabuleiro[0][2]=="x" && tabuleiro[0][1]==" "){
			tabuleiro[0][1]="o";
			return 0;
		}
		else if(tabuleiro[0][0]=="x" && tabuleiro[0][2]==" " && tabuleiro[0][1]=="x"){
			tabuleiro[0][2]="o";
			return 0;
		}
		else if(tabuleiro[0][0]==" " && tabuleiro[0][2]=="x" && tabuleiro[0][1]=="x"){
			tabuleiro[0][0]="o";
			return 0;
		}
		




		else if(tabuleiro[0][0]=="o" && tabuleiro[0][2]=="o" && tabuleiro[0][1]==" "){
			tabuleiro[0][1]="o";
			return 0;
		}
		else if(tabuleiro[0][0]=="o" && tabuleiro[0][2]==" " && tabuleiro[0][1]=="o"){
			tabuleiro[0][2]="o";
			return 0;
		}
		else if(tabuleiro[0][0]==" " && tabuleiro[0][2]=="o" && tabuleiro[0][1]=="o"){
			tabuleiro[0][0]="o";
			return 0;
		}
		else if(tabuleiro[0][0]=="o" && tabuleiro[2][0]=="o" && tabuleiro[1][0]==" "){
			tabuleiro[1][0]="o";
			return 0;
		}
		else if(tabuleiro[0][0]=="o" && tabuleiro[2][0]==" " && tabuleiro[1][0]=="o"){
			tabuleiro[2][0]="o";
			return 0;
		}
		else if(tabuleiro[0][0]==" " && tabuleiro[2][0]=="o" && tabuleiro[1][0]=="o"){
			tabuleiro[0][0]="o";
			return 0;
		}
		else if(tabuleiro[0][0]=="o" && tabuleiro[2][2]=="o" && tabuleiro[1][1]==" "){
			tabuleiro[1][1]="o";
			return 0;
		}
		else if(tabuleiro[0][0]=="o" && tabuleiro[2][2]==" " && tabuleiro[1][1]=="o"){
			tabuleiro[2][2]="o";
			return 0;
		}
		else if(tabuleiro[0][0]==" " && tabuleiro[2][2]=="o" && tabuleiro[1][1]=="o"){
			tabuleiro[0][0]="o";
			return 0;
		}
		else if(tabuleiro[2][0]=="o" && tabuleiro[2][2]=="o" && tabuleiro[2][1]==" "){
			tabuleiro[2][1]="o";
			return 0;
		}
		else if(tabuleiro[2][0]==" " && tabuleiro[2][2]=="o" && tabuleiro[2][1]=="o"){
			tabuleiro[2][0]="o";
			return 0;
		}
		else if(tabuleiro[2][0]=="o" && tabuleiro[2][2]==" " && tabuleiro[2][1]=="o"){
			tabuleiro[2][2]="o";
			return 0;
		}
		else if(tabuleiro[0][2]=="o" && tabuleiro[2][2]=="o" && tabuleiro[1][2]==" "){
			tabuleiro[1][2]="o";
			return 0;
		}
		else if(tabuleiro[0][2]==" " && tabuleiro[2][2]=="o" && tabuleiro[1][2]=="o"){
			tabuleiro[0][2]="o";
			return 0;
		}
		else if(tabuleiro[0][2]=="o" && tabuleiro[2][2]==" " && tabuleiro[1][2]=="o"){
			tabuleiro[2][2]="o";
			return 0;
		}
		else if(tabuleiro[0][2]=="o" && tabuleiro[2][0]=="o" && tabuleiro[1][1]==" "){
			tabuleiro[1][1]="o";
			return 0;
		}
		else if(tabuleiro[0][2]==" " && tabuleiro[2][0]=="o" && tabuleiro[1][1]=="o"){
			tabuleiro[0][2]="o";
			return 0;
		}
		else if(tabuleiro[0][2]=="o" && tabuleiro[2][0]==" " && tabuleiro[1][1]=="o"){
			tabuleiro[2][0]="o";
			return 0;
		}
		else if(tabuleiro[0][2]==" "){
			tabuleiro[0][2]="o";
			return 0;
		}
		else if(tabuleiro[2][0]==" "){
			tabuleiro[2][0]="o";
			return 0;
		}
		else if(tabuleiro[2][2]==" "){
			tabuleiro[2][2]="o";
			return 0;
		}


		else
			return 1;
	}
	public int fim(){
		if(tabuleiro[0][0]=="o" && tabuleiro[0][2]=="o" && tabuleiro[0][1]=="o"){
			return 0;
		}
		else if(tabuleiro[0][0]=="o" && tabuleiro[2][0]=="o" && tabuleiro[1][0]=="o"){
			return 0;
		}
		else if(tabuleiro[0][0]=="o" && tabuleiro[2][2]=="o" && tabuleiro[1][1]=="o"){
			return 0;
		}
		else if(tabuleiro[2][0]=="o" && tabuleiro[2][2]=="o" && tabuleiro[2][1]=="o"){
			return 0;
		}
		else if(tabuleiro[0][2]=="o" && tabuleiro[2][2]=="o" && tabuleiro[1][2]=="o"){
			return 0;
		}
		else if(tabuleiro[0][2]=="o" && tabuleiro[2][0]=="o" && tabuleiro[1][1]=="o"){
			return 0;
		}
		else if(tabuleiro[1][0]=="o" && tabuleiro[1][1]=="o" && tabuleiro[1][2]=="o"){
			return 0;
		}
		else if(tabuleiro[0][0]=="o" && tabuleiro[1][1]=="o" && tabuleiro[2][2]=="o"){
			return 0;
		}
		else if(tabuleiro[0][0]=="x" && tabuleiro[0][2]=="x" && tabuleiro[0][1]=="x"){
			return 2;
		}
		else if(tabuleiro[0][0]=="x" && tabuleiro[2][0]=="x" && tabuleiro[1][0]=="x"){
			return 2;
		}
		else if(tabuleiro[0][0]=="x" && tabuleiro[2][2]=="x" && tabuleiro[1][1]=="x"){
			return 2;
		}
		else if(tabuleiro[2][0]=="x" && tabuleiro[2][2]=="x" && tabuleiro[2][1]=="x"){
			return 2;
		}
		else if(tabuleiro[0][2]=="x" && tabuleiro[2][2]=="x" && tabuleiro[1][2]=="x"){
			return 2;
		}
		else if(tabuleiro[0][2]=="x" && tabuleiro[2][0]=="x" && tabuleiro[1][1]=="x"){
			return 2;
		}
		else if(tabuleiro[1][0]=="x" && tabuleiro[1][1]=="x" && tabuleiro[1][2]=="x"){
			return 2;
		}
		else if(tabuleiro[0][0]=="x" && tabuleiro[1][1]=="x" && tabuleiro[2][2]=="x"){
			return 2;
		}
		else if(cont2>=8){
			return 3;
		}
		else
			return 1;

	}

}