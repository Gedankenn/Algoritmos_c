import javax.swing.JFrame;

public class primeirajanela extends JFrame{
	public primeirajanela(){
		super("primeira janela seu fdp: ");
		setSize(400,200);
		setVisible(true);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}

	public static void main(String[] args){
		new primeirajanela();
	}
}