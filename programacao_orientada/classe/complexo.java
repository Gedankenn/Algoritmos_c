public class complexo{
	public static void main(String[] args){
		numeroComplexo num1 = new numeroComplexo();

		System.out.println(num1);

		num1.igual(num1);

		num1.soma(num1);
		System.out.println("soma: "+num1);

		num1.divide(num1);
		System.out.println("divisao: "+num1);

		num1.multiplica(num1);
		System.out.println("multiplica: "+num1);

		num1.subtrai(num1);
		System.out.println("subtracao: "+num1);		
	}
}