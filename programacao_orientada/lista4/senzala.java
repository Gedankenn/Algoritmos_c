public class senzala{
	public static void main(String[] args){
		empregado escravo1 = new empregado();
		empregado escravo2 = new empregado();


		escravo1.inicializa("django","free",120);
		escravo2.inicializa("seu","Ze",24);

		escravo1.imprime();
		System.out.println();
		escravo2.imprime();

		escravo1.aumento();
	}

}