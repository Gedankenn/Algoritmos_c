import java.util.Scanner;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;

public class Sistema_email{
	public static void main(String[] args){

		Email[] emails= new Email[10];

		int total=0;
		int opcao=-1;

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
		System.out.println(total);
		Scanner tc = new Scanner(System.in);
		String usuario=tc.next();
		
		while(opcao!=0){
			System.out.println("---------------------------------------------------------------------------");
			System.out.println("opcao 0: sair");
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
					System.out.println("arquivo lotado");
				}
			}

			if(opcao==2){
				int cont=0;
				int aux=0;
				while(cont<total){
					if(emails[cont].listar_emails(usuario)==1){
						System.out.println("email: "+cont);
						aux++;
					}
					cont++;
				}
				System.out.println();
				if(aux>0){
					System.out.println("Ensira o valor do email que deseja ler: ");
					aux=tc.nextInt();
					System.out.println();
					emails[aux].ler_email(usuario);
				}
				else{
					System.out.println("arquivo vazio");
				}
			}
			if(opcao==3){
				int cont=0;
				if(total==0){
					System.out.println("arquivo vazio");
				}
				while(cont<total){
					if(emails[cont].listar_emails(usuario)==1){
						System.out.println("email: "+cont);
					}
					cont++;
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
	}
}