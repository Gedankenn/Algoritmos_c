import java.util.LinkedList;
public class ExemploLista2
{
public static void main(String[] args)
 {
 	LinkedList<Float> lista = new LinkedList<Float>();
	lista.add(new Float(1.4));
	lista.add(1f);
	lista.add(new Float(2.61));
	float sum = 0;
	System.out.print("Soma de ");
	for(Float f:lista)
	{
	  System.out.print(f+" ");
	  sum += f;
	}
	System.out.println("e' "+sum);
	// Soma de 1.4 1.0 2.61 e' 5.01
 }
}