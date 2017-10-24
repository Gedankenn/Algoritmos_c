public class sexyshop{
	public static void main(String[] args){
		fatura item1 = new fatura();
		fatura item2 = new fatura();
		fatura item3 = new fatura();

		item1.imprime();
		System.out.println();
		item1.fatura("001","pirocao preto",5,250);
		item1.imprime();

		item2.fatura("022","boneca inflavel",3,1500);
		System.out.println();
		item2.imprime();

		item3.fatura("053","vibrador 27cm",2,530);
		System.out.println();
		item3.imprime();


		System.out.println();
		double total;
		total=item1.compra()+item2.compra()+item3.compra();
		System.out.println("valor total da compra: "+total);

	}
}