import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class butao extends JFrame implements ActionListener{
	private JButton b1,b2,b3,b4;
	private int putas=0;
	private int viado=0;
	private JLabel lputas;
	private JLabel lviado;

	public butao(){
		super("butao das puta");
		Container c=getContentPane();
		c.setLayout(new GridLayout(2,3));
		b1=new JButton("+puta");
		b2=new JButton("-puta");
		b3=new JButton("+viado");
		b4=new JButton("-viado");
		lputas = new JLabel(" = "+putas);
		lviado = new JLabel(" = "+viado);
		c.add(b1); c.add(b2); c.add(lputas);
		c.add(b3); c.add(b4); c.add(lviado);
		b1.addActionListener(this); b2.addActionListener(this);
		b3.addActionListener(this); b4.addActionListener(this);
		//pack(); deve comentar isso para setar tamanho da janela
		setSize(400,400);
		setVisible(true);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

	}
	public void actionPerformed(ActionEvent e){
		if(e.getSource()==b1) putas++;
		if(e.getSource()==b2) putas--;
		if(e.getSource()==b3) viado++;
		if(e.getSource()==b4) viado--;
		lputas.setText(""+putas);
		lviado.setText(""+viado);
	}

	public static void main(String[] args){
		new butao();
	}

}