import java.util.Scanner;
import java.io.Serializable;

public class Email implements Serializable{
	private String destinatario;
	private String conteudo;
	private String assunto;
	private String remetente;

	public Email(String usuario){
		System.out.println("ensira o destinatario: ");
		Scanner tc = new Scanner(System.in);
		this.remetente=usuario;
		this.destinatario=tc.next();
		this.conteudo=tc.next();
		System.out.println("ensinra o assunto: ");
		this.assunto=tc.next();
		this.conteudo=tc.next();

		System.out.println("ensira corpo do email: ");
		this.conteudo=tc.next();
	}

	public int listar_emails(String usuario){
		if(this.destinatario.equals(usuario)){
			System.out.println("email de "+this.remetente+" para "+this.destinatario);
			System.out.println("assunto: "+this.assunto);
			return 1;
		}
		else 
			return 0;
	}
	public void ler_email(String usuario){
		if(this.destinatario.equals(usuario)){
			System.out.println("remetente: "+this.remetente);
			System.out.println("assunto: "+this.assunto);
			System.out.println("conteudo: "+this.conteudo);
		}
	}
}