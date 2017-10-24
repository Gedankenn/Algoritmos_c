import java.awt.Color;
import java.awt.Graphics;
import java.util.ArrayList;

public class Tela extends java.swing.JPanel{
	private Principal painel;
	private ArrayList<Personagem> personagens;

	public Tela(Principal aThis){
		initComponents();
		this.painel=aThis;
		this.setBackground(Color.white);
		this.personagens=new ArrayList<Personagem>();
	}

	@Override
	public void paint(Graphics g){
		super.paint(g);

		for(Personagem personagem:personagens){
			personagem.desenhar(g);
		}
		g.dispose();
	}

	public void criarPersongem(int x, int y){
		Personagem a=new Personagem(this,"personagem",x,y);
		a.desenhar(super.getGraphics());
		personagem.add(a);
	}

	public void movimentaPersonagem(int direcao){
		for(Personagem personagens:aldeoes){
			personagens.mover(direcao);
		}
		this.repaint();
	}

	public void atacarPersonagem(){
		for(Personagem personagens:aldeoes){
			personagens.atacar();
		}
		this.repaint();
	}
}