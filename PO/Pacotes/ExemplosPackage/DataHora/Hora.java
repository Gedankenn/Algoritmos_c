package DataHora;

public class Hora
{
  byte hora;
  byte minuto;
  byte segundo;

  public Hora(byte h,byte m,byte s)
  {
    hora = h; minuto = m; segundo = s;
  }
  public String toString()
  {
    return hora+":"+minuto+":"+segundo;
  }
} // fim da classe Hora