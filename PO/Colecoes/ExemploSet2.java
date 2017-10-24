import java.util.Date;
import java.util.TreeSet;
public class ExemploSet2
{ 
 public static void main(String[] args)
 { 
	TreeSet<Object> set = new TreeSet<Object>();
	set.add(new Integer(123));
	set.add(123);
	set.add("ABC"); // !!!!
	set.add("ABC");
	set.add(new Date());
	set.remove("ABC");
	System.out.println(set);
 }
}