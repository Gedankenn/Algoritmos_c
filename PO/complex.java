public class complex{
	public static void main(String[] arg){
		numero num1= new numero(2,3);
		numero num2= new numero(1,2);

		System.out.println(num1);

		num1.compara(num1);
		num1.soma(num1);
		System.out.println("soma: "+num1);

		System.out.println("num2: "+num2);
		num1.divide(num2);
		System.out.println("divide: "+num1);

		num1.multiplica(num1);
		System.out.println("multiplica: "+num1);

		num1.subtrai(num1);
		System.out.println("subtracao: "+num1);

	}
}

class numero{
	private int a=1, b=2;

	public numero(int x, int y){
		a=x;
		b=y;
	}

	public void inicializa(int x, int y){
		a=x;
		b=y;
	}

	public void imprime(){
		System.out.println(a+b+"i");
	}
	public String toString(){
		return a+"+"+b+"i";
	}

	public void compara(numero num){
		if(num.a==a && num.b==b){
			System.out.println("verdadeiro");
		}
		else{
			System.out.println("falso");
		}
	}
	public void soma(numero num){
		a=num.a+a;
		b=num.b+b;

	}
	public void subtrai(numero num){
		a=num.a-a;
		b=num.b-b;
	}
	public void divide(numero num){
		int aux=a;
		a=(num.a*a+num.b*b)/((num.a*num.a)+(num.b*num.b));
		b=(num.b*b-num.a*aux)/((num.a*num.a)+(num.b*num.b));
	}
	public void multiplica(numero num){
		int aux=a;
		a=num.a*a-num.b*b;
		b=aux*b+num.b*num.a;
	}

}