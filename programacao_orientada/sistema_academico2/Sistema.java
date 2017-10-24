import java.util.Scanner;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;

public class Sistema{
	public static void main(String[] args){
		Scanner tc = new Scanner(System.in);

		Estudante[] alunos= new Estudante[10];
		int total=0;
		int opcao=0;

		File arquivo = new File("backup.dat");

			try{
				FileInputStream fin = new FileInputStream(arquivo);
				ObjectInputStream oin = new ObjectInputStream(fin);

				alunos = (Estudante[]) oin.readObject();

				oin.close();
				fin.close();

				for(Estudante p : alunos){
					if(p!=null){
						p.imprime();
						total++;
					}
				}
			}catch (Exception ex){
				System.err.println("erro: "+ex.toString());
			}

		while(opcao!=-1){
			System.out.println();
			System.out.println();
			System.out.println("Menu do sistema");
			System.out.println("opcao 1: incluir alunos");
			System.out.println("opcao 2: alterar dados de aluno");
			System.out.println("opcao 3: lista todo mundo");
			System.out.println("opcao 4: remover aluno");
			System.out.println("-1 para sair");
			opcao=tc.nextInt();


			//parte logica do sistema
			if(opcao==1){
				if(total<9){
					System.out.println("insira o nome do aluno: ");
					String nome= tc.next();
					String data= tc.next();
					System.out.println("insira numero da matricula: ");
					int mat=tc.nextInt();
					System.out.println("insira a data de nascimento:dia ");
					int dia, mes, ano;
					dia=tc.nextInt();
					System.out.println("insira a data de nascimento:mes:  ");
					mes=tc.nextInt();
					System.out.println("insira a data de nascimento:ano ");
					ano=tc.nextInt();


					alunos[total]= new Estudante(mat, nome, dia, mes, ano);
					alunos[total].setdiciplinas();
					total++;
				}
				else{
					System.out.println("excedeu numero maximo de alunos");
				}
			}

			if(opcao==2){
				System.out.println("insira matricula que deseja alterar");
				int mat=tc.nextInt();
				int j=0;

				while(j<total && mat!=alunos[j].matricula()){
					j++;
				}
				if(j!=total){
					alunos[j].setdiciplinas();						
				}
				else{
					System.out.println("matricula nao encontrada");
				}
			}

			if(opcao==3){
				for(int i=0; i<total;i++){
					alunos[i].imprime();
				}
			}

			if(opcao==4){
				if(total>0){
					System.out.println("insira matricula que deseja remover: ");
					int mat=tc.nextInt();
					int j=0;
					while(j<total && mat!=alunos[j].matricula()){
						j++;
					}
					if(j<total-1){
						alunos[j]=alunos[total];
						total--;
					}
					else if(j==9){
						total--;
					}
					else{
						System.out.println("matricula nao encontrada");
					}
				}
				else{
					System.out.println("nao possui estudante cadastrado");
				}
			}

			try {
				FileOutputStream fout = new FileOutputStream(arquivo);
				ObjectOutputStream oos = new ObjectOutputStream(fout);

				//gravando o vetor
				oos.writeObject(alunos);

				oos.flush();
				oos.close();
				fout.close();

			} catch(Exception ex){
				System.err.println("erro: "+ex.toString());
			}
		}
	}
}