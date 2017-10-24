package minhaApp;

import geometria.Circulo;
import geometria.Ponto2D;

public class MeuCirculo extends Circulo
{
	private int id;
	public MeuCirculo(Ponto2D centro, double raio,int id)
	{
		//super();      // erro de compilacao
		super(centro, raio);
		this.id = id;
	}
	public String toString()
	{
		return "Círculo com ID "+id+", centro em "+centro+" e raio "+raio;
	}
}