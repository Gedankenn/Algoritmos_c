import java.util.Random;

public class Principal extends javax.swing.JFrame{
	 private Random sorteio;

	 //butao
	private javax.swing.ButtonGroup buttonGroup1;
   	private javax.swing.JButton butaoAldeao;
	private javax.swing.JButton butaoArqueiro;
	private javax.swing.JButton butaoBaixo;
	private javax.swing.JButton butaoCavaleiro;
	private javax.swing.JButton butaoCima;
	private javax.swing.JButton butaoCima1;
	private javax.swing.JButton butaoDireita;
	private javax.swing.JButton butaoEsquerda;
	private javax.swing.JPanel butaoCriar;
	private javax.swing.JPanel butaoLateral;
	private javax.swing.JPanel butaoMovimentar;
	private javax.swing.JPanel butaoTela;
	private javax.swing.JRadioButton radiobutaoAldeao;
	private javax.swing.JRadioButton radiobutaoArqueiro;
	private javax.swing.JRadioButton radiobutaoCavaleiro;
	private javax.swing.JRadioButton radiobutaoTodos;

	 public Principal(){
	 	initComponents();
	 	this.setLocationRelativeto(null);
	 	this.sorteio=new Random();
	 }

	 private void personagemAction(java.awt.event.ActionEvent evt){
	 	int largura=this.JPTela.getWidth();
	 	int altura= this.JPTela.getHeight();

	 	int x=this.sorteio.nextInt(largura-50);
	 	int y=this.sortio.nextInt(altura-50);
	 	if(x<0){
	 		x=0;
	 	}
	 	if(y<0){
	 		y=0;
	 	}
	 	((Tela) this.JPTela).criarPersonagem(x,y);
	 }

	 public static void main(String args[]){
	 	java.awt.EventQueue.invokeLater(new Runnable(){
	 		public void run(){
	 			new Principal().setVisible(true);
	 		}
	 	});
	 }
}