public class bicicleta{
	private double valor;

	public void imprimir_valor(){
	System.out.println(this.valor);
	}
}

public class principal{
	private double valor;

	public void imprimir_valor(){
	System.out.println(this.valor);
	}

	public void teste(){
	bicicleta b = new bicicleta();
	b.imprime_valor();
	}
	public static void main(String[] argss){
	principal p = new principal();
	p.imprime_valor();
	p.teste();
	}
}