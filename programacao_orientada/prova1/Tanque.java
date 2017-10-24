public class Tanque{
	private int pontos;
	private int combustivel;
	private int municao;

	public Tanque(){
		this.pontos=0;
		this.combustivel=200;
		this.municao=30;
	}

	public acertou_alvo(int d){
		this.pontos=this.pontos+d;
	}
	public int gazoza(){
		return this.gazoza;
	}
	public int muni(){
		return this.muni;
	}
	public void dispara(){
		this.municao--;
	}
	public void movi(){
		this.combustivel--;
	}

}