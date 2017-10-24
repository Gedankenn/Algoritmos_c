import java.util.Scanner;
public class DivisaoPorZeroGenerica{

	public static void main(String[] args){
	  Scanner ler = new Scanner(System.in);
	  int a, b, res;

	  try{
	   a = ler.nextInt();
	   b = ler.nextInt();

	   res = a / b;

	   System.out.println(a + " dividido por " + b + " = " + res);

	  }catch(Exception e){
		System.err.println("Ocorreu o erro: " + e.toString());
	 }
	 System.out.println("Fim do programa");
  }
}