import javax.swing.JFrame;
import javax.swing.jframe;

public class terceirajanela extends JFrame{
	public terceirajanela(String t,int l, int a){
		super(t);
		getContentPane().add(new JLabel("tudo puta e viado"));
		setSize(l,a);
		setVisible(true);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}

	public static void main(String[] args){
		new terceirajanela("fiz as conta:",300,300);
	}
}