import java.util.Scanner;
import java.io.Serializable;

public class Estudante implements Serializable{
	private int matricula;
	private String nome;
	private String data;
	private String[] diciplinas = new String[3];
	private String[] conceito = new String[3];


	public Estudante(int m, String nomeA, String dataA){
		this.matricula = m;
		this.nome = nomeA;
		this.data=dataA;
	}

	public void setdiciplinas(String[] dis, String[] conc){
		this.diciplinas = dis;
		this.conceito=conc;
	}
	public int matricula(){
		return this.matricula;
	}
	public String nome(){
		return this.nome;
	}
	public void imprime(){
		System.out.println();
		System.out.println("Matricula: "+this.matricula);
		System.out.println("Nome: "+this.nome);
		System.out.println("Data: "+this.data);
		System.out.println("Disciplinas: ");
		for(int i=0; i<3;i++){
			System.out.println(this.diciplinas[i]+" : "+this.conceito[i]);
		}
		System.out.println();
	}
}