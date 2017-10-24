import java.util.Scanner;
import java.io.File;
import java.io.Console;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;


public class RACK{
	public static void main(String[] args){
		machine[] armario = new machine[5];
		Scanner tc=new Scanner(System.in);
		int total=0;

		File arquivo = new File("backup.dat");
		try{
				FileInputStream fin = new FileInputStream(arquivo);
				ObjectInputStream oin = new ObjectInputStream(fin);

				armario = (machine[]) oin.readObject();

				oin.close();
				fin.close();

				for(machine p : armario){
					if(p!=null){
						total++;
					}
				}
				
		}catch (Exception ex){
			System.err.println("erro: "+ex.toString());
		}

		int menu=0;

		if(total==0){
			armario[0]=new machine(20,900,0);
		}

		System.out.println("1-> ensirir nova vm");
		System.out.println("2-> ver estado de vm especifica");
		System.out.println("3-> ver specs de todas as maquinas e suas vms");
		System.out.println("4-> ligar ou desligar vm");
		System.out.println("-1 -> sair do sistema");
		while(menu!=-1){
			menu=tc.nextInt();
			if(menu==1){
				System.out.println("ensira a quantia de ram desejada: ");
				int r=tc.nextInt();
				System.out.println("ensira a quantia de hd desejada: ");
				int h=tc.nextInt();
				int cont=0;
				int aux=0;

				while(aux==0 && cont<total){
					aux=armario[cont].nova_vm(r,h);
					cont++;
				}
				if(aux==0){
					if(cont<5){
						armario[cont]=new machine(20,800,cont);
						total++;
						aux=armario[cont].nova_vm(r,h);
						System.out.println("vm: "+cont+" criada");
					}
					else{
						System.out.println("impossivel criar vm desejada: ");
					}
				}
				else{
					System.out.println("vm criada no RACK:  "+(cont-1));
					//total++;
				}
			}
			if(menu==2){
				int m, v;
				System.out.println("ensira maquina que hospeda sua vm: ");
				m=tc.nextInt();
				System.out.println("ensira sua vm: ");
				v=tc.nextInt();
				int cont=0;
				while(cont!=m && cont<total){
					cont++;
				}
				if(cont==m){
					System.out.println("maquina: "+cont);
					if(armario[cont].nome_vm(v)!=-1){
						System.out.println("vm: "+v);
						armario[v].specs(v);
					}
					else{
						System.out.println("nao existe vm");
					}
				}

			}
			if(menu==3){
				System.out.println("todas as maquinas e suas vms: ");
				int cont=0;
				int cont2=0;
				while(cont<total){
					cont2=0;
					System.out.println("maquina: "+cont);
					while(armario[cont].nome_vm(cont2)!=-1){
						System.out.println("VM: "+cont2);
						armario[cont].specs(cont2);
						System.out.println("---------------------------------------------");
						cont2++;
					}
					cont++;
				}
			}
			if(menu==4){
				//System.out.println("Ensira qual vm deseja ligar ou desligar: ");
				System.out.println("em qual rack esta vm que deseja desligar: ");
				int r=tc.nextInt();
				System.out.println("qual vm: ");
				int v=tc.nextInt();
				System.out.println("1->ligar, 0->desligar");
				int n=tc.nextInt();
				armario[r].liga_desliga(v,n);

			}


			try {
				FileOutputStream fout = new FileOutputStream(arquivo);
				ObjectOutputStream oos = new ObjectOutputStream(fout);

				//gravando o vetor
				oos.writeObject(armario);

				oos.flush();
				oos.close();
				fout.close();

			} catch(Exception ex){
				System.err.println("erro: "+ex.toString());
			}
		}



	}
}

class machine implements Serializable{
	private int ram;
	private int hd;
	private int nome;
	private vm[] virtual;
	private int total_m;

	public machine(int r, int h, int n){
		this.ram=r;
		this.hd=h;
		this.nome=n;
		this.total_m=0;
		this.virtual= new vm[20];
	}

	public int nova_vm(int r, int h){
		int totalr=0, totalh=0;
		for(int i=0;i<total_m;i++){
			totalr= totalr+virtual[i].memoria();
			totalh=totalh+virtual[i].espaco();
		}
		if(totalh+h<hd && totalr+r<ram){
			virtual[total_m]=new vm(r,h,total_m);
			total_m++;
			return 1;
		}
		else{
			return 0;
		}
	}

	public int nome_vm(int v){
		if(v<total_m){
			return virtual[v].nome();
		}
		else{
			return -1;
		}
	}

	public void specs(int v){
		System.out.println("memoria: "+virtual[v].memoria());
		System.out.println("espaco: "+virtual[v].espaco());
		System.out.println("estado: ");
		virtual[v].estado_maquina();
	}

	public void liga_desliga(int v, int n){
		virtual[v].ligar_desligar(n);
	}


}

class vm implements Serializable{
	private int on_off;
	private int ram;
	private int hd;
	private int nome;

	public vm(int r, int h, int n){
		this.ram=r;
		this.hd=h;
		this.nome=n;
	}
	public void ligar_desligar(int n){
		this.on_off=n;
	}
	public void estado_maquina(){
		if(on_off==1){
			System.out.println(nome+" esta ligada");
		}
		else{
			System.out.println(nome+" esta desligada");
		}
	}
	public int memoria(){
		return ram;
	}
	public int espaco(){
		return hd;
	}
	public int nome(){
		return nome;
	}

}