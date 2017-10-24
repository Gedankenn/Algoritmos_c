import java.util.Scanner;

public class Controle{
	private char direcional;
	private char metralhadora;
	private char registro;

	Scanner tc = new Scanner(System.in);
	public Controle(){
		this.direcional='p';
		this.metralhadora='n';
		this.registro='o';
	}
	public char comando_M(){
		return this.metralhadora;
	}
	public char comando_D(){
		return this.direcional;
	}
	public char alive(){
		return this.registro;
	}
	public void insere_comando(){
		System.out.println("ensira comando direcional(w,a,s,d): ");
		this.direcional=tc.next();
		this.metralhadora=tc.next();
		System.out.println("deseja disparar? (f=sim|n=nao): ");
		this.metralhadora=tc.next();
	}
	public void desliga(){
		this.registro='f';
	}
}

