package DataHora;

public class Data
{
  protected byte dia;
  byte mês;
  short ano;

  public Data(byte d,byte m,short a)
  {
    dia = d; mês = m; ano = a;
  }

  public String toString()
  {
    return dia+"/"+mês+"/"+ano;
  }

  } // fim da classe Data
