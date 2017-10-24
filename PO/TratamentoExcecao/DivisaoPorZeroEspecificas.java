import java.util.Scanner;
public class DivisaoPorZeroEspecificas{

	public static void main(String[] args){
	  Scanner ler = new Scanner(System.in);
	  int a, b, res;
	  try{
		a = ler.nextInt();
		b = ler.nextInt();
		res = a / b;

		System.out.println(a + " dividido por " + b + " = " + res);
	  }catch(java.util.InputMismatchException e){
		System.out.println("Erro: Valores nao inteiros. ");
	  }catch(java.lang.ArithmeticException e){
		System.out.println("Erro: Divisao por zero ");
	  }catch(Exception e){
		System.out.println("Ocorreu o erro: " + e.toString());
	  }
	  System.out.println("Fim do programa");
	}
}