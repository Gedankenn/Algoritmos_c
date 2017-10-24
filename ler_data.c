#include <stdio.h>
#include <stdlib.h>

int main(void){
	FILE *data;
	char ler;
	int dia, mes, ano, hora, minuto;
	int cont=0, cont2=0;
	int comp=0;
	int totalh=0;
	int horamsg[24], totalhoramsg[24];

	int carol=0, fabio=0, totalf=0, totalc=0;
	int aux;

	data=fopen("panda2.txt","r");
	fscanf(data,"%d/%d/%d, %d:%d - %c",&dia,&mes,&ano,&hora,&minuto,&ler);
	//printf("%d/%d/%d, %d:%d - %c\n",dia,mes,ano,hora,minuto,ler);

	while(cont<24){
		horamsg[cont]=0;
		cont++;
	}
	cont=0;
	while(cont<24){
		totalhoramsg[cont]=0;
		cont++;
	}

	cont=0;
	comp=mes;
	rewind(data);

	while(fscanf(data,"%d/%d/%d, %d:%d - %c",&dia,&mes,&ano,&hora,&minuto,&ler)!=EOF){
		fscanf(data, "%*[^\n]\n", NULL);
		//aux=hora;
		if(mes==comp){
			cont++;
			horamsg[hora]++;
			if(ler=='F'){
				fabio++;
			}
			if(ler=='P'){
				carol++;
			}
		}
		else{
			printf("mes: %d -- total de: %d mensagens|\n",comp,cont);
			printf("msg enviadas-> Fabio=%d| carol=%d|\n",fabio,carol );
			cont=0;
			while(cont<24){
				//printf("hora-> |  0   |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |  10  |  11  |\n");
				//printf("       | %d   |  %d  |  %d  |  %d  |  %d  |  %d  |  %d  |  %d  |  %d  |  %d  |  %d  |  %d  |\n\n",horamsg[0],horamsg[1],horamsg[2],horamsg[3],horamsg[4],horamsg[5],horamsg[6],horamsg[7],horamsg[8],horamsg[9],horamsg[10],horamsg[11] );
				//printf("hora-> |  12  |  13  |  14  |   15 |  16  |  17  |  18  |  19  |  20  |  21  |  22  |  23  |\n");
				//printf("       | %d   |  %d  |  %d  |  %d  |  %d  |  %d  |  %d  |  %d  |  %d  |  %d  |  %d  |  %d  |\n",horamsg[12],horamsg[13],horamsg[14],horamsg[15],horamsg[16],horamsg[17],horamsg[18],horamsg[19],horamsg[20],horamsg[21],horamsg[22],horamsg[23] );
				
				printf("hora->[%d] - [%d]\n",cont,horamsg[cont] );
				totalhoramsg[cont]=totalhoramsg[cont]+horamsg[cont];
				cont++;
			}
			printf("\n\n");
			totalf=totalf+fabio;
			totalc=totalc+carol;
			comp=mes;
			
			fabio=1;
			
			
			carol=1;
			

			cont=0;
			while(cont<24){
				horamsg[cont]=0;
				cont++;
			}
			cont=1;
		}

		//printf("%d/%d/%d\n",dia,mes,ano );
		cont2++;
	}

	totalf=totalf+fabio;
	totalc=totalc+carol;
	printf("mes: %d -- total de: %d mensagens\n",comp,cont);
	printf("msg enviadas| Fabio=%d| carol=%d|\n",fabio,carol );
	cont=0;
	while(cont<24){
		//printf("hora-> |  0   |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |  10  |  11  |\n");
		//printf("       | %d   |  %d  |  %d  |  %d  |  %d  |  %d  |  %d  |  %d  |  %d  |  %d  |  %d  |  %d  |\n\n",horamsg[0],horamsg[1],horamsg[2],horamsg[3],horamsg[4],horamsg[5],horamsg[6],horamsg[7],horamsg[8],horamsg[9],horamsg[10],horamsg[11] );
		//printf("hora-> |  12  |  13  |  14  |   15 |  16  |  17  |  18  |  19  |  20  |  21  |  22  |  23  |\n");
		//printf("       | %d   |  %d  |  %d  |  %d  |  %d  |  %d  |  %d  |  %d  |  %d  |  %d  |  %d  |  %d  |\n",horamsg[12],horamsg[13],horamsg[14],horamsg[15],horamsg[16],horamsg[17],horamsg[18],horamsg[19],horamsg[20],horamsg[21],horamsg[22],horamsg[23] );
			
			printf("hora->[%d] - [%d]\n",cont,horamsg[cont] );
			cont++;
		}
	printf("\n");
	printf("total de: %d mensagens\n",cont2);
	printf("total msg enviadas por fabio:%d| por carol:%d\n",totalf,totalc );
 	
 	printf("total de msg por horas somados no mes\n");
 	cont=0;
 	while(cont<24){
		printf("hora->[%d] - [%d]\n",cont,totalhoramsg[cont] );
		cont++;
	}


	fclose(data);
	return 0;
}