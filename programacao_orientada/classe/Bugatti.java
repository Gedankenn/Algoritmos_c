public class Bugatti{
	public static void main(String[] args){
		CarroNaoIdeal bugatti = new CarroNaoIdeal();

		bugatti.definirVelocidade(350);
		System.out.println("acelera ai bixao: "+bugatti.velocidade);

		bugatti.acelerar(530);

		System.out.println("Nao consegue neh moises: "+bugatti.velocidade);
	}
}