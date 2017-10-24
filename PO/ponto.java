class ponto{
  private ponto2d[] array;

  public ponto(int tamanho){
    array = new ponto2d[tamanho];
  }

  public int tamanho(){
    return array.length;
  }

  public String toString(){
    int c=0;
    String resultado;
    for(c=0;c<array.length;c++){
      resultado += array[c];
    }
  }

  }
}

class ponto2d{
  private int x,y;

  public ponto2d(int a, int b){
    x=a;
    y=b;
  }

  public String toString(){
    return "x: "+x+" y: "+y;
  }

}