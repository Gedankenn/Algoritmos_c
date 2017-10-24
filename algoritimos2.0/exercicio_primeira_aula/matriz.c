#include <stdio.h>
#include <time.h>




int main(void){
	int M[4][4], M2[16][2];
	int cont=0, i,j,i2,j2;
	i=0;
	j=0;

	while(i<4){
		j=0;
		while(j<4){
			M[i][j]=(rand()%3) +7;
			j++;
		}
		i++;
	}
	i=0;
	j=0;
	while(i<16){
		M2[i][0]=0;
		M2[i][1]=0;
		i++;
	}
	i=0;
	j=0;
	while(i<4){
		j=0;
		while(j<4){
			printf("%d ",M[i][j] );
			j++;
		}
		printf("\n");
		i++;
	}
	i2=0;
	i=0;
	j=0;
	while(i<4){
		j=0;
		while(j<4){
			if(M[i][j]==7){
				M2[i2][0]=i;
				M2[i2][1]=j;
				i2++;
			}
			j++;
		}
		i++;
	}
	i2=0;
	j2=0;

	while(i2<16){
		printf("%d ",M2[i2][0] );
		printf("%d ",M2[i2][1] );
		printf("\n");
		i2++;
	}



	return 0;
}