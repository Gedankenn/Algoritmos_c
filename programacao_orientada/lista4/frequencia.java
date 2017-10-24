public class frequencia{
	public static void main(String[] args){
		frequenciaCardiaca boi1 = new frequenciaCardiaca();

		boi1.inicializa("Edeval","dasorta",24,11,1993);
		boi1.imprime();

		int idade=boi1.idade(2015);
		System.out.println(idade);

		int frequenciamax=boi1.frequenciamaxima(idade);
		System.out.println(frequenciamax);

		boi1.frequenciaideal(frequenciamax);
	}
}