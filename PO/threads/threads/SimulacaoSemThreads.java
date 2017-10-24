package threads;
public class SimulacaoSemThreads 
{
	public static void main(String[] args){
	// Criamos instancias da classe	CarroDeCorrida.
	CarroDeCorrida penelope = new CarroDeCorrida("Penelope Charmosa",60);
	CarroDeCorrida dick = new CarroDeCorrida("Dick Vigarista",100);
	CarroDeCorrida quadrilha = new CarroDeCorrida("Quadrilha da Morte",120);
	// Criados os carros, vamos executar as	simulações.
	penelope.executa();
	dick.executa();
	quadrilha.executa();
	}
}