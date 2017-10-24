package geometria;
public class Ponto2D
{
	protected double x;
	protected double y;
	
	public Ponto2D(double x, double y)
	{
		this.x = x;
		this.y = y;
	}
	public String toString()
	{
		return "Ponto x: "+this.x+" e y: "+this.y;
	}
}