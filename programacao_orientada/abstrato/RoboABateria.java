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
					movex(+passos);
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