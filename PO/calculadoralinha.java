public class calculadoralinha{
	public static void main(String[] aargs){
		if(aargs.length != 3){
			System.out.println("ensira 3 argumentos karalho");
			System.exit(1);
		}

		int n1 = Integer.parseInt(aargs[0]);
		char operador = aargs[1].charAt(0);
		int n2= Integer.parseInt(aargs[2]);
		int res=0;

		switch(operador){
			case '+': res=n1+n2; break;
			case '-': res=n1-n2; break;
			case 'x': res=n1*n2; break;
			case '/': res=n1/n2; break;
		}

		for(int i=0;i<aargs.length;i++){
			System.out.println(aargs[i]+" ");
		}
		System.out.println("="+res);
	}
}