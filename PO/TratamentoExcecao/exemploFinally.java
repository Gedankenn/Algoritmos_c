public class exemploFinally{

	public static void main(String[] args){
	  
      System.out.println("Ola mundo");	  
	  try{
		System.out.println("Primeira instrucao");	  
		int a = 10/0;  
		System.out.println("Terceira instrucao");	
	  }catch(Exception e){
		System.out.println("Executadao somente se ocorrer excecao: " + e.toString());
	  }finally{
	     System.out.println("Executa sempre");
      }
      System.out.println("Executa sempre - fora do bloco");	  
	}
}