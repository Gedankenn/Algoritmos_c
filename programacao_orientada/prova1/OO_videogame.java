import java.util.Scanner;

public class OO_videogame{
	private Controle[] players = new Controle[4];
	private Tanque[] carro=new Tanque[4];
	private int num_jogadores;
	
	public OO_videogame(int n){
		int cont=0;
		while(cont<d){
			players[cont]=new Controle();
			carro[cont]=new Tanque();
			cont++;
		}
	}
	public void comando(int n){
		if(players[n].alive=='o'){
			players[n].insere_comando();
			if(players[n].comando_D != 'p'){
				if(carro[n].gazoza>0){
					carro[n].movi();
				}
			}
			if(players[n].comando_M != 'f'){
				if(carro[n].muni>0){
					carro[n].dispara();
				}
			}
		}
	}
	public void desliga_controle(int n){
		players[n].desliga();
	}


}
