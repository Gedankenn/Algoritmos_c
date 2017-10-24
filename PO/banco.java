public class banco{
	public static void main(String[] args){
		contabancaria[] agencia = new contabancaria[3];

		agencia[0] = new contabancaria("temer",5000.25);
		agencia[1] = new contabancaria("dilma",0.00);
		agencia[2] = new contabancaria("trump",9999.99);

		System.out.println(agencia[0]);
		System.out.println(agencia[1]);
		System.out.println(agencia[2]);

		double total=0;
		for(contabancaria a : agencia){
			total=total+a.getsaldo();
		}
		System.out.println("o total de saldo: "+total);
	}
}
class contabancaria{
	private String nome;
	private double saldo;
	public contabancaria(String n, double s){
		nome=n;
		saldo=s;
	}
	public double getsaldo(){
		return saldo;
	}
	public String getnome(){
		return nome;
	}
	public void deposita(double q){
		saldo=saldo+q;
	}
	public void retira(double q){
		if(q<=saldo){
			saldo=saldo-q;
		}
	}
	public void transferencia(contabancaria de, double quanto){
		if(de.getsaldo() <= quanto){
			deposita(quanto);
			de.retira(quanto);
		}
	}

	public String toString(){
		return "conta de "+nome+" tem saldo "+saldo;
	}
}