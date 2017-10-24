import javax.swing.JOptionPane;

public class terceiro{
	public static void main(String[] args){
		String texto = JOptionPane.showInputDialog("jo soy pablo escobar gaviria: ");
		int numero = Integer.parseInt(texto);
		JOptionPane.showMessageDialog(null, numero);
	}
}