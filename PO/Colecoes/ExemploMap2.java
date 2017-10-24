import java.util.TreeMap;
public class ExemploMap2
{
	public static void main(String[] args)
	{
		TreeMap<String,Integer> mapa = new TreeMap<String,Integer>();
		mapa.put("um",1);
		mapa.put("dois",2);
		mapa.put("tres",3);
		mapa.put("quatro",4);
		mapa.put("cinco",5);
		System.out.println(mapa);
		// {cinco=5, dois=2, quatro=4, tres=3, um=1}
		System.out.println(mapa.get("quatro")+mapa.get("dois")); // 6
	}
}