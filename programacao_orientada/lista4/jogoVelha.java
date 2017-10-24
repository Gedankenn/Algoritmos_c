public class jogoVelha{
	public static void main(String[] args){
		velha tabuleiro = new velha();
		int aux;

		tabuleiro.inicializa();
		tabuleiro.printatabuleiro();

		aux=1;

		while(aux== 1){
			System.out.println();
			tabuleiro.printatabuleiro();
			System.out.println();
			aux=tabuleiro.aijogada();
			tabuleiro.printatabuleiro();
			aux=tabuleiro.fim();
			if(aux!=0){
				tabuleiro.jogada();
				aux=tabuleiro.fim();
			}
		}
		System.out.println();
		if(aux==0){
			System.out.println("a Skynet venceu: ");
		}
		else if(aux==3){
			System.out.println("empate: ");
		}
		else
			System.out.println("os humanos venceram: ");

		tabuleiro.printatabuleiro();
	}
}