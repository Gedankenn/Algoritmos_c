#include <stdio.h>

int main(void){
	int num, i=0, j=0;
	scanf("%d",&num);

	int matriz[num][num];

	while(i<num){
		j=0;
		while(j<num){
			if(i==j){
				matriz[i][j]=0;
			}
			if(j>i){
				matriz[i][j]=1;
				matriz[j][i]=-1;
			}
			j++;
		}
		i++;
	}
	j=0;
	i=0;
	while(i<num){
		j=0;
		while(j<num){
			printf("%d ",matriz[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	return 0;
}