public class calculadora2{
	public static void main(String[] aargs){
		if(aargs.length < 2){
			System.out.println("ensira mais argumentos karalho");
			System.exit(1);
		}

		char operador = aargs[0].charAt(0);
		int aux=aargs.length;
		int[] num = new int[aux-1];
		for(int i=0;i<aargs.length-1;i++){
			num[i]= Integer.parseInt(aargs[i+1]);
		}
		int res=0;

		if(operador=='+'){
			for(int i=0;i<aargs.length-1;i++){
				res=res+num[i];
			}
		}
		if(operador=='x'){
			res=1;
			for(int i=0;i<aargs.length-1;i++){
				res=res*num[i];
			}
		}

		for(int i=0;i<aargs.length;i++){
			System.out.println(aargs[i]+" ");
		}
		System.out.println("="+res);
	}
}