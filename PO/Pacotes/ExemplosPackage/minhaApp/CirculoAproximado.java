package minhaApp;
import geometria.Circulo;
import geometria.Ponto2D;
public class CirculoAproximado extends Circulo
{
	// O construtor paramétrico deve existir.
	public CirculoAproximado(Ponto2D centro, double raio)
	{
		super(centro, raio);
	}
	public double calculaÁrea()
	{
		return 3.14*raio*raio;
	}
	//protected double calculaPerímetro() // Erro de compilação!
	public double calculaPerímetro() // Sem erro de compilação!
	{
		return 3.14*Math.PI*raio;
	}
}