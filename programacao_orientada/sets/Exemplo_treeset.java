import java.util.Date;
import java.util.TreeSet;

public class Exemplo_treeset{
	
	public static void main(String[] args){

		TreeSet<Object> set = new TreeSet<Object>();
		set.add(new Integer(123));
		set.add(123);
		set.add("ABC");
		set.add(new Date());
		System.out.println(set);
	}
}