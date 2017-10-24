package DataHora;

public class DataHora // declaração da classe 
{
  Data estaData;  
  Hora estaHora; 

  public DataHora(byte h,byte min,byte s,byte d,byte m,short a)
  {
    estaData = new Data(d,m,a);
    estaHora = new Hora(h,min,s);
  }
  
  public String toString()
  {
    String resultado = estaHora.hora+":"+estaHora.minuto+":"+estaHora.segundo;
    resultado += " de "+estaData.dia;
    resultado += " de ";
    switch(estaData.mês) // dependendo do valor do campo mês, concatena o nome do mês
      {
      case  1: resultado += "Janeiro"; break;
      case  2: resultado += "Fevereiro"; break;
      case  3: resultado += "Março"; break;
      case  4: resultado += "Abril"; break;
      case  5: resultado += "Maio"; break;
      case  6: resultado += "Junho"; break;
      case  7: resultado += "Julho"; break;
      case  8: resultado += "Agosto"; break;
      case  9: resultado += "Setembro"; break;
      case 10: resultado += "Outubro"; break;
      case 11: resultado += "Novembro"; break;
      case 12: resultado += "Dezembro"; break;
      }
    resultado += " de "+estaData.ano;
    return resultado; 
    }
	
	public void testandoModificadoresAcesso(){
		estaData.dia = (byte)10;
	}
  } // fim da classe DataHora