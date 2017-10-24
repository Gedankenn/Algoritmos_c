import java.util.Scanner;
import java.io.Serializable;

public class Diciplinas implements Serializable{
	private String conceito;
	private String materia;


	public Diciplinas(String mat, String conc){

		this.conceito=conc;
		this.materia=mat;
	}
	public void imprime_diciplina(){
		System.out.println("diciplina: "+this.materia+"| conceito: "+this.conceito);
	}

}