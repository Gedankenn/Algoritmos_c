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
		resultado=resultado+"posicao do robo: ("+posicaoX+","+posicaoY+")\n";
		resultado=resultado+"Direcao do robo: "+direcao;
		return resultado;
	}
}

class RoboABateria extends RoboAbstrato{
	private long energia;

	RoboABateria(String n, int px, int py, short d, long e){
		super(n,px,py,d);
		energia=e;
	}
	public void move(int passos){
		long energiagastar = passos*10;
		if(energiagastar<=energia){
			switch(direcaoatual()){
				case 0: 
					moveX(+passos); 
					break;
				case 45: 
					moveX(+passos);
					moveY(+passos); 
					break;
				case 90:
					moveY(+passos);
					break;
				case 135:
					moveY(+passos);
					moveX(-passos);
					break;
				case 180:
					moveX(-passos);
					break;
				case 225:
					moveX(-passos);
					moveY(-passos);
					break;
				case 270:
					moveY(-passos);
					break;
				case 315:
					moveY(-passos);
					moveX(+passos);
					break;
			}
			energia -=energiagastar;
		}
	}

	public String toString(){
		String resultado=super.toString()+"\n";
		resultado=resultado+"energia do robo: "+energia;
		return resultado;
	}

	public void recarrega(long e){
		energia=energia+e;
	}
}