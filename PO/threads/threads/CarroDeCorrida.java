package threads;
public class CarroDeCorrida
{
	private String nome;
	private int distancia;
	private int velocidade;
	public CarroDeCorrida(String n, int vel)
	{
		nome = n;
		distancia = 0;
		velocidade = vel;
	}
	public void executa()
	{
		while(distancia <= 1200) {
		System.out.println(nome + " rodou " + distancia + " km.");
		distancia += velocidade;
		// Causa um delay artificial.
		double x;
		for (int sleep = 0; sleep < 1000000; sleep++)
			x = Math.sqrt(Math.sqrt(Math.sqrt(sleep)));
		}
	} 
}