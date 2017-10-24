import java.awt.Graphics;
import java.awt.Image;
import javax.swing.ImageIcon;
import javax.swing.JPanel;

public class Aldeao{

	private JPanel painel;
	private Image icone;
	private String imagemnome;
	private int largura;
	private int altura;
	private int px;
	private int py;
	private boolean atacando;

	public Aldeao(JPanel p, String img, int x, int y, ){
		this.imagemnome=img;
		this.icone=this.carregarImagem(this.imagemnome);
		this.largura = this.icone.getWidth(null);
		this.altura= this.icone.getHeight(null);

		this.painel=p;
		this.px=x;
		this.py=y;
		this.atacando=false;
	}

	public void desenhar(Graphics g){
		if(atacando==true){
			this.icone=this.carregarImagem(this.imagemnome+"2");
		}
		else{
			this.icone=this.carregarImagem(this.imagemnome)
		}

		//desenhando no painel a imagem
		g.drawImage(this.icone,this.px,this.py,this.painel);
	}

	/*posicao:
	0 para cima;
	1 para baixo;
	2 para esquerda;
	3 para direita */
	public void mover(int direcao){
		if(direcao==0){
			this.py -=10;
		}
		if(direcao==1){
			this.py +=10;
		}
		if(direcao==2){
			this.px -=10;
		}
		if(direcao==3){
			this.px +=10;
		}

		if(this.px>this.painel.getWidth()-this.largura){
			this.px=this.painel.getWidth()-this.largura;
		}
		else if(this.px<0){
			this.px=0;
		}
		if(this.py>this.painel.getHeight()-this.altura){
			this.py=this.painel.getHeight()-this.altura;
		}
		else if(this.py<0){
			this.py=0;
		}
	}

	public void atacar(){
		this.atacando =!this.atacando;
	}

	private Image carregarImagem(String imagem){
		ImageIcon iicon=new ImageIcon(this.getClass().getResource("../imagens/"+imagem+".png"));
		return iicon.getImage();
	}
}