package geometria;
public class Circulo implements ObjetoGeometrico
{
	protected Ponto2D centro;
	protected double raio;
	public Circulo(Ponto2D centro, double raio)
	{
		this.centro = centro;
		this.raio = raio;
	}
	public Ponto2D centro() { return centro; }
	public double calculaÁrea() { return Math.PI*raio*raio; }
	
	public double calculaPerímetro() { return 2.0*Math.PI*raio; }
 //   private double calculaPerímetro() { return 2.0*Math.PI*raio; }
//	protected double calculaPerímetro() { return 2.0*Math.PI*raio; }
	
	public String toString()
	{
		return "Círculo com centro em "+centro+" e raio "+raio;
	}
	// metodo definido na interface
	public void calcularVolume ( double x, double y, double z ){
		System.out.println("Estou calculando o volume do circulo, que no caso é vazio, aqui!");
	}
}