import java.util.ArrayList;
import java.util.Collections;
public class Sorteio
 {
 public static void main(String[] args)
 {
 ArrayList<Integer> números = new ArrayList<Integer>(60);
 for(int i=1;i<60;i++) números.add(i);
 Collections.shuffle(números);
 for(int i=0;i<6;i++) System.out.print(números.get(i)+" ");
 // 7 59 16 51 36 58
 }
 }