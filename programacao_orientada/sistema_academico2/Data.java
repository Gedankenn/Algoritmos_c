import java.util.Scanner;
import java.io.Serializable;

public class Data implements Serializable{
	private int dia;
	private int mes;
	private int ano;


	public Data(int d, int m, int a){
		this.dia=d;
		this.mes=m;
		this.ano=a;
	}
	public void imprime_data(){
		System.out.println("data de nascimento: "+this.dia+"| "+this.mes+"| "+this.ano);
	}

}