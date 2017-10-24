import javax.swing.JOptionPane;

public class terceiro{
	public static void main(String[] args){
		String texto = JOptionPane.showlnputDialog("jo soy pablo escobar gaviria: ");
		int numero = Integer.parselnt(texto);
		JOptionPane.showMessageDialog(null, numero);
	}
}