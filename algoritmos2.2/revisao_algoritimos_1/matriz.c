#include <stdio.h>
#include <time.h>

int main(void){
	int matriz[4][4], matriz2[16][2];

	srand(time(NULL));
	int i=0,j=0;

	while(i<4){
		j=0;
		while(j<4){
			matriz[i][j]=(rand()%3)+7;
			j++;
		}
		i++;
	}
	i=0;
	while(i<16){
		matriz2[i][0]=0;
		matriz2[i][1]=0;
		i++;
	}
	i=0;
	j=0;

	while(i<4){
		j=0;
		while(j<4){
			printf("%d ",matriz[i][j] );
			j++;
		}
		printf("\n");
		i++;
	}
	i=0;
	j=0;

	int i2=0;

	while(i<4){
		j=0;
		while(j<4){
			if(matriz[i][j]==7){
				matriz2[i2][0]=i;
				matriz2[i2][1]=j;
				i2++;
			}
			j++;
		}
		i++;
	}	

	printf("\n");
	i=0;
	while(i<16){
		printf("%d %d\n",matriz2[i][0], matriz2[i][1] );
		i++;
	}

	return 0;
}