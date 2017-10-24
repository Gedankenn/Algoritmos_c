import java.util.Scanner;
import java.io.Serializable;
import java.io.Console;

public class Estudante implements Serializable{
	private int matricula;
	private String nome;
	private Data dat;
	private Diciplinas[] diciplinas = new Diciplinas[3];


	public Estudante(int m, String nomeA, int dia, int mes, int ano){
		this.matricula = m;
		this.nome = nomeA;
		dat =new Data(dia,mes,ano);
	}

	public void setdiciplinas(){

		Console tc = System.console();
		String dis, conc;
		for (int i=0;i<diciplinas.length;i++){
			dis=tc.readLine("ensira diciplina: ");
			conc=tc.readLine("ensira o conceito da materia: ");
            diciplinas[i] = new Diciplinas(dis, conc);
         }
		
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
		dat.imprime_data();
		System.out.println("Disciplinas: ");
		for(int i=0; i<3;i++){
			diciplinas[i].imprime_diciplina();
		}
		System.out.println();
	}
}