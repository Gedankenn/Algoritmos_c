package threads;
public class SimulacaoComThreads
{
	public static void main(String[] args)
	{
		// Criamos instâncias da classe CarroDeCorrida.
		CarroDeCorridaComThreads penelope =
		new CarroDeCorridaComThreads("Penelope Charmosa",60);
		CarroDeCorridaComThreads dick =
		new CarroDeCorridaComThreads("Dick Vigarista",100);
		CarroDeCorridaComThreads quadrilha =
		new CarroDeCorridaComThreads("Quadrilha da Morte",120);
		// Criados os carros, vamos executar as simulacoes.
		penelope.start();
		dick.start();
		quadrilha.start();
	}
}