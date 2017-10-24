public class empregado{
	private String nome;
	private String sobrenome;
	private double salario;

	public void imprime(){
		System.out.println("nome: "+nome);
		System.out.println("sobrenome: "+sobrenome);
		System.out.println("salario: "+salario);
	}
	public void salario(){
		double anual;
		anual=salario*12;
		System.out.println("salario anual: "+anual);
	}
	public void aumento(){
		double aumento;
		aumento=salario-(salario*0.1);
		System.out.println();
		System.out.println(nome+" "+sobrenome+"  ||salario atual: "+salario);
		System.out.println("novo salario: "+aumento+" hahaha achou q ia aumentar mais neh");
	}
	public void inicializa(String nomep, String sobrenomep, double sal){
		nome=nomep;
		sobrenome=sobrenomep;
		salario=sal;
	}

}