#include <stdio.h>

int main(void){

int p=5, *a, *b;

printf("%d, %d\n",&p, p);

a=&p;
printf("%d, %d",*a,&a);

return 0;
}
