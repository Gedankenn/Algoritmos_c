public class ponto2D{
	private double x, y;

	ponto2D(double a, double b){
		x=a;
		y=b;
	}
}

interface Objetogeometrico{
	ponto2D centro();
}

class quadrado implements Objetogeometrico{
	private ponto2D p1,p2,p3,p4;

	quadrado(ponto2D p1, ponto2D p2, ponto2D p3, ponto2D p4){
		this.p1=p1;
		this.p2=p2;
		this.p3=p3;
		this.p4=p4;
	}

	public ponto2D centro(){
		double x1=(p2.x-p1.x)/2;
		double y1=(p3.y-p1.y)/2;
		return new ponto2D(x1,y1);
	}

	public double area(){
		double x=p2.x-p1.x;
		double y=p3.y-p1.y;
		return x*y;
	}
	
}

public class Circulo implements Objetogeometrico{
	protected ponto2D centro;
	protected double raio;

	public Circulo(ponto2D centro, double raio){
		this.centro=centro;
		this.raio=raio;
	}

	public ponto2D centro(){
		return centro;
	}

	public double calcularArea(){
		return Math.PI*raio*raio;
	}

	public double calculaPerimetro(){
		return 2.0*Math.PI*raio;
	}

	public String toString(){
		return "Circulo com centro em "+centro+"e raio "+raio;
	}
}