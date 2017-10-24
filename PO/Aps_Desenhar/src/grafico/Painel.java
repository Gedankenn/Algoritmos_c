/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package grafico;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import javax.swing.JPanel;

/**
 *
 * @author Alienware
 */
public class Painel extends JPanel{
public Painel(){
//Alterando as propriedades do objeto
this.setFocusable(true);
this.setBackground(Color.BLACK);
}
//Este m´etodo ´e invocada para desenhar o painel...
@Override
public void paint(Graphics g){
super.paint(g);
g.setColor(Color.red);
g.drawString("Fabio", 100, 100);
}
public void desenharQuadrado(int x, int y, int largura, int altura){
Graphics2D g2d = (Graphics2D) this.getGraphics();
// Desenhando um ret^angulo
g2d.setColor(Color.BLUE);
g2d.drawRect(x, y, largura, altura);
// Desemhar um ret^angulo preenchido com a cor vermelha
g2d.setColor(Color.red);
g2d.fillRect(x+100,y+100,largura,altura);
}
}
