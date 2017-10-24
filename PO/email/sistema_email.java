import java.util.Scanner;
import java.io.File;
import java.io.Console;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;

public class sistema_email{
	public static void main(String[] args){
		Email[] emails = new Email[10];
		int total=0;
		int opcao=-1;
		int login=1;

		File arquivo = new File("backup_email.dat");
		try{
				FileInputStream fin = new FileInputStream(arquivo);
				ObjectInputStream oin = new ObjectInputStream(fin);

				emails = (Email[]) oin.readObject();

				oin.close();
				fin.close();

				for(Email p : emails){
					if(p!=null){
						total++;
					}
				}
				
		}catch (Exception ex){
			System.err.println("erro: "+ex.toString());
		}

		System.out.println("total de emails: "+total);
		Scanner tc = new Scanner(System.in);
		while(login==1){
			System.out.println("ensira usuario: ");
			String usuario = tc.next();
			while(opcao!=0){
				System.out.println("---------------------------------------------------------------------------");
				System.out.println("opcao 0: logout");
				System.out.println("opcao 1: escrever email");
				System.out.println("opcao 2: ler email");
				System.out.println("opcao 3: listar emails");
				opcao=tc.nextInt();

				System.out.println("----------------------------------------------------------------------------");

				if(opcao==1){
					if(total<10){
						emails[total]= new Email(usuario);
						total++;
					}
					else{
						System.out.println("backup lotado");
					}
				}

				if(opcao==2){
					int cont=0;
					int aux=0;
					while(cont<total){
						if(emails[cont].listar_emails(usuario)==1){
							System.out.println("Email: "+cont);
							aux++;
						}
						cont++;
					}
					System.out.println();
					if(aux>0){
						System.out.println("escolha -1 para parar de ler emails: ");
						System.out.println("Ensira o valor do email que deseja ler: ");
						aux=tc.nextInt();
						while(aux!=-1){
							System.out.println();
							emails[aux].ler_email(usuario);
							aux=tc.nextInt();
						}
					}
					else{
						System.out.println("arquivo esta vazio");
					}
				}

				if(opcao==3){
					int cont=0;
					if(total==0){
						System.out.println("arquivo vasio");
					}
					else{
						while(cont<total){
							if(emails[cont].listar_emails(usuario)==1){
								System.out.println("Email: "+cont);
							}
							cont++;
						}
					}
				}
				try {
				FileOutputStream fout = new FileOutputStream(arquivo);
				ObjectOutputStream oos = new ObjectOutputStream(fout);

				//gravando o vetor
				oos.writeObject(emails);

				oos.flush();
				oos.close();
				fout.close();

			} catch(Exception ex){
				System.err.println("erro: "+ex.toString());
			}
			}
			System.out.println("entrar com novo usuario=1 / ou sair = 0");
			login=tc.nextInt();
			opcao=-1;

		}

	}
}


class Email implements Serializable{
	private String destinatario;
	private String conteudo;
	private String assunto;
	private String remetente;

	public Email(String usuario){
		System.out.println("ensira o destinatario");
		Scanner tc = new Scanner(System.in);
		Console console = System.console();
		this.remetente=usuario;
		this.destinatario=console.readLine("ensira o destinatario: ");
		//System.out.println("ensira o assunto");
		this.assunto=console.readLine("ensira o assunto: ");
		//System.out.println("ensira o conteudo");
		this.conteudo=console.readLine("ensira o conteudo: ");
	}

	public int listar_emails(String usuario){
		if(this.destinatario.equals(usuario)){
			System.out.println("email de: "+this.remetente+" para: "+this.destinatario);
			System.out.println("assunto: "+this.assunto);
			return 1;
		}
		else{
			System.out.println("nao possui emails");
			return 0;
		}
	}
	public void ler_email(String usuario){
		if(this.destinatario.equals(usuario)){
			System.out.println("remetente: "+this.remetente);
			System.out.println("assunto: "+this.assunto);
			System.out.println("conteudo: "+this.conteudo);
		}
	}
}