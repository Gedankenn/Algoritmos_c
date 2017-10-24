package threads;
public class CarroDeCorridaComThreads extends Thread
{
	private String nome;
	private int distância;
	private int velocidade;
	public CarroDeCorridaComThreads(String n, int vel)
	{
		nome = n;
		distância = 0;
		velocidade = vel;
	}
	public void run()
	{
		while (distância <= 1200)
		{
			System.out.println(nome + " rodou " + distância + " km.");
			distância += velocidade;
			double x;
			// Causa um delay artificial.
			for (int sleep = 0; sleep < 1000000; sleep++)
			x = Math.sqrt(Math.sqrt(Math.sqrt(sleep)));
		}
	}
}