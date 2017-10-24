package geometria;
public interface ObjetoGeometrico{
 // somente para ilustraro uso de constantes em uma interface. Nada util neste exemplo
 public static final String nome = "Objeto Geometrico";
 // metodo abstrato por padrao
 public void calcularVolume ( double x, double y, double z );
}