abstract class RoboAbstrato{
	
	private String nomedorobo;
	private int posicaoX, posicaoY;
	private short direcao;

	RoboAbstrato(String n, int px, int py, short d){
		nomedorobo=n;
		posicaoX=px;
		posicaoY=py;
		direcao=d;
	}

	public void move(){
		move(1);
	}

	public abstract void move(int passos);

	public void moveX(int passos){
		posicaoX += passos;
	}
	public void moveY(int passos){
		posicaoY += passos;
	}
	
	public void mudaDirecao(short novaD){
		direcao=novaD;
	}	
	public short direcaoatual(){
		return direcao;
	}

	public String toString(){
		String resultado= "nome do robo: "+nomedorobo+"\n";
		resultado=resultado+"posicao do robo: ("+posicaoX+","+posicaoY")\n";
		resultado=resultado+"Direcao do robo: "+direcao;
		return resultado;
	}
}