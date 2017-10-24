#include <stdio.h>

void drawCircle(int x, int y, float radius) {
  ellipse(x, y, radius, radius);
  if(radius > 2) {
    radius *= 0.75f;
    drawCircle(x, y, radius);
  }
}

int main(void){

drawCricle( 4, 4, 16);

return 0;
}
