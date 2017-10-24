import java.awt.*;
import javax.swing.*;

public class borda extends JFrame{
	public borda(String t){
		super(t);
		Container c=getContentPane();
		c.setLayout(new BorderLayout());
		c.add(new JLabel("puta1"),BorderLayout.NORTH);
		c.add(new JLabel("puta2"),BorderLayout.SOUTH);
		JLabel centro= new JLabel("cafetao");
		centro.setForeground(Color.RED);
		centro.setBorder(BorderFactory.createEmptyBorder(100,100,100,100));
		c.add(centro,BorderLayout.CENTER);
		pack();
		setVisible(true);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}

	public static void main(String[] args){
		new borda("puteiro");
		new borda("tudo puta");
	}
}