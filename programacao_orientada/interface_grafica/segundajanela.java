import javax.swing.JFrame;

public class segundajanela extends JFrame{
	public segundajanela(String t,int l, int a){
		super(t);
		setSize(l,a);
		setVisible(true);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}

	public static void main(String[] args){
		new segundajanela("janela1",100,100);
		new segundajanela("janlea2",200,200);
		new segundajanela("janela3",300,300);
	}
}