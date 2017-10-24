public class numeroComplexo{
	public int a=1;
	public int b=2;

	public String toString(){
		return a+"+"+b+"i ";
	}
	public void inicializa(int x, int y){
		a=x;
		b=y;
	}
	public void soma(numeroComplexo num){
		num.a=num.a+num.a;
		num.b=num.b+b;
	}
	public void subtrai(numeroComplexo num){
		num.a=num.a-a;
		num.b=num.b-b;
	}
	public void divide(numeroComplexo num){
		int aux=num.a;
		num.a=(num.a*a+num.b*b)/((num.a*num.a)+(num.b*num.b));
		num.b=(num.b*b-num.a*a)/((num.a*num.a)+(num.b*num.b));
	}

	public void multiplica(numeroComplexo num){
		int aux=num.a;
		num.a=num.a*a-num.b*b;
		num.b=aux*b+num.b*a;
	}
	public void igual(numeroComplexo num){
		if(num.a==a && num.b==b){
			System.out.println("eh igual");
		}
		else
			System.out.println("nao eh igual");
	}
}