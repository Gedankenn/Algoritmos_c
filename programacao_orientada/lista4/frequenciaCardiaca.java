public class frequenciaCardiaca{
	private String nome;
	private String sobrenome;
	private int dia;
	private int mes;
	private int ano;

	public void inicializa(String nomep, String sobrenomep, int diap, int mesp, int anop){
		nome=nomep;
		sobrenome=sobrenomep;
		dia=diap;
		mes=mesp;
		ano=anop;
	}
	public int idade(int ano_atual){
		int idade;
		idade=ano_atual-ano;
		return idade;
	}
	public int frequenciamaxima(int idade){
		int bat;
		bat=220-idade;
		return bat;
	}
	public void frequenciaideal(int bat){
		System.out.println("a sua frequencia ideal eh entre: "+bat*0.5+" e "+bat*0.85);
	}
	public void imprime(){
		System.out.println(nome+" "+sobrenome+" "+dia+"/"+mes+"/"+ano);
	}

}