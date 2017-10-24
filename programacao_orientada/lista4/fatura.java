public class fatura{
	private String pessa;
	private String nome;
	private int quant=0;
	private double valor=0;


	public void imprime(){
		System.out.println("numero da pessa: "+pessa);
		System.out.println("nome da pessa: "+nome);
		System.out.println("quantidade: "+quant);
		System.out.println("valor: "+valor);
	
	}
	public void fatura(String nump, String nomep,int quantp, double valorp){
		pessa=nump;
		nome=nomep;
		if(quant<0){
			quantp=0;
		}
		quant=quantp;
		if(valor<0){
			valorp=0;
		}
		valor=valorp;
	}
	public double compra(){
		double total;
		total=valor*quant;
		return total;
	}
}