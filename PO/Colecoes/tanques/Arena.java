package tanques;
import java.awt.*;
import java.awt.event.*;
import java.util.HashSet;
import javax.swing.*;
import java.awt.KeyEventDispatcher;
import java.awt.KeyboardFocusManager;
import java.awt.event.KeyEvent;
import java.util.Random;

public class Arena extends JComponent implements MouseListener, ActionListener, KeyListener
{
	private int w,h;
	private HashSet<Tanque> tanques;
	private Timer timer;
	private Tanque pronteirotanque;
	private Random randomico = new Random();
	//private int keyup = getKeyCode();
	private boolean up=false;
	public Arena(int w,int h)
	{
		this.w = w; this.h = h;
		tanques = new HashSet<Tanque>();
		addMouseListener(this);
		this.setFocusable(true);
		addKeyListener(this);
		/*Timer-javax.swing -> dispara um ou mais ActionEvent em intervalo especificado
		em milisegundos - invocando o actionPerformed da classe*/
		timer = new Timer(500,this);
		timer.start(); 
		System.out.println("1");
	}
	public void adicionaTanque(Tanque t)
	{
		tanques.add(t);
	}
	public Dimension getMaximumSize()
	{
		return getPreferredSize();
	}
	public Dimension getMinimumSize()
	{
		return getPreferredSize();
	}
	public Dimension getPreferredSize()
	{
		return new Dimension(w,h);
	}
	protected void paintComponent(Graphics g)
	{
		super.paintComponent(g);
		Graphics2D g2d = (Graphics2D)g;
		g2d.setRenderingHint(RenderingHints.KEY_ANTIALIASING,
		RenderingHints.VALUE_ANTIALIAS_ON);
		g2d.setColor(new Color(245,245,255));
		g2d.fillRect(0,0,w,h);
		g2d.setColor(new Color(220,220,220));
		for(int _w=0;_w<=w;_w+=20) g2d.drawLine(_w,0,_w,h);
		for(int _h=0;_h<=h;_h+=20) g2d.drawLine(0,_h,w,_h);
		// Desenhamos todos os tanques
		for(Tanque t:tanques) t.draw(g2d);
	}
	public void mouseClicked(MouseEvent e)
	{

		for(Tanque t:tanques) t.setEstaAtivo(false);
		for(Tanque t:tanques)
		{
			boolean clicado = t.getRectEnvolvente().contains(e.getX(),e.getY());
			if (clicado)
			{
				pronteirotanque=t;
				t.setEstaAtivo(true);
				switch(e.getButton())
				{
					case MouseEvent.BUTTON1:{
						
						t.giraAntiHorario(3); 
						break;
					}
					case MouseEvent.BUTTON2:{
						t.diminuivelocidade();
						break;
					}
					case MouseEvent.BUTTON3:{
						t.giraHorario(3);
						break;
					}
				}
				break;
			}
		}
	repaint();
	}
	public void mouseEntered(MouseEvent e) { }
	public void mouseExited(MouseEvent e) { }
	public void mousePressed(MouseEvent e) { }
	public void mouseReleased(MouseEvent e) { }
	public void keyEntered(KeyEvent e) { }
	public void keyPressed(KeyEvent e) {
		//System.out.println("test");
		if(pronteirotanque!=null){
			int keyup = e.getKeyCode();
			if(keyup==KeyEvent.VK_W){
				pronteirotanque.aumentaVelocidade();
			}
			if(keyup==KeyEvent.VK_F){
				//cria tanque em posiçao aleatoria.
				tanques.add(new Tanque(randomico.nextInt(300), randomico.nextInt(300),randomico.nextInt(300),Color.YELLOW));
			}
		}
		repaint();
	}
	public void keyTyped(KeyEvent e) {
	}
	public void keyReleased(KeyEvent e) {
			up=false;
	}
	public void actionPerformed(ActionEvent e)
	{
	for(Tanque t:tanques) t.move(this.w,this.h);
	repaint();
	}
}