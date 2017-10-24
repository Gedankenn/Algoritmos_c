public class CarroNaoIdeal{
	//atributos
	public float velocidade;
	//metodos
	public void definirVelocidade(float v){
		if(v<=450){
			velocidade=v;
		}
		else
			velocidade=0;
	}

	public void acelerar(float a){
		if(velocidade + a <=450){
			velocidade=velocidade+a;
		}
		else
			velocidade=450;
	}
}