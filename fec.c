#include <stdio.h>
#include <stdlib.h>

int main(void){
	FILE *data;
	char ler;
	int dia, mes, ano, hora, minuto;
	int cont=0, cont2=0;
	int comp=0;
	char fdp[20];

	int menor=0, fabio=0, opressao=0, chacals2=0, skynet=0, lindo=0,gatos=0;
	int totalm=0,totalf=0, totalo=0, totalc=0, totals=0, totall=0, totalg=0;
	int aux, aux2;
	int menorh[24], fabioh[24], opressaoh[24], chacals2h[24], lindoh[24], skyneth[24],gatosh[24];

	data=fopen("Conversa do WhatsApp com 5.135.156.131_2.txt","r");
	fscanf(data,"%d/%d/%d, %d:%d - %s",&dia,&mes,&ano,&hora,&minuto,&fdp);
	//printf("%d/%d/%d, %d:%d - %c\n",dia,mes,ano,hora,minuto,ler);

	while(cont<24){
		menorh[cont]=0;
		fabioh[cont]=0;
		opressaoh[cont]=0;
		chacals2h[cont]=0;
		lindoh[cont]=0;
		skyneth[cont]=0;
		gatosh[cont]=0;
		cont++;
	}

	cont=0;
	comp=mes;
	aux=ano;
	aux2=dia;
	rewind(data);
	printf("mes, fabio, chacal, roner, menor, demon, meitcher, pincel \n");
	while(fscanf(data,"%d/%d/%d, %d:%d - %s",&dia,&mes,&ano,&hora,&minuto,&fdp)!=EOF){
		fscanf(data, "%*[^\n]\n", NULL);
		//aux=hora;
		if(mes==comp){
			cont++;
			if(fdp[0]=='F'){
				fabio++;
				fabioh[hora]++;
			}
			if(fdp[0]=='M'){
				if(fdp[2]=='n'){
					menor++;
					menorh[hora]++;
				}
				else{
					skynet++;
					skyneth[hora]++;
				}
			}
			if(fdp[0]=='C'){
				chacals2++;
				chacals2h[hora]++;
			}
			if(fdp[0]=='R'){
				lindo++;
				lindoh[hora]++;
			}
			if(fdp[0]=='D'){
				opressao++;
				opressaoh[hora]++;
			}
			if(fdp[0]=='P'){
				gatos++;
				gatosh[hora]++;
			}
		}
		if(mes!=comp && dia<5){
			/*printf("mes: %d| ano: %d -- total de: %d mensagens|\n",comp,aux,cont);
			printf("msg enviadas-> Fabio=%d| ",fabio );
			printf("Chacal=%d| Roner=%d| Menor=%d| Demon=%d| Meitcher=%d| Pincel=%d|",chacals2,lindo,menor,opressao,skynet,gatos );
			cont=0;*/
			printf("%d,",comp);
			printf("%d,",fabio );
			printf("%d,%d,%d,%d,%d,%d,",chacals2,lindo,menor,opressao,skynet,gatos );
			/*while(cont<24){
				printf("hora->[%d] - [%d]\n",cont,horamsg[cont] );
				totalhoramsg[cont]=totalhoramsg[cont]+horamsg[cont];
				cont++;
			}*/
			printf("\n");
			comp=mes;
			aux=ano;

			totalm=menor+totalm;
			totalf=fabio+totalf;
			totalo=opressao+totalo;
			totalc=chacals2+totalc;
			totals=skynet+totals;
			totall=lindo+totall;
			totalg=gatos+totalg;

			fabio=0;
			chacals2=0;
			lindo=0;
			menor=0;
			opressao=0;
			skynet=0;
			gatos=0;

			if(fdp[0]=='F'){
				fabio++;
				fabioh[hora]++;
			}
			if(fdp[0]=='M'){
				if(fdp[2]=='n'){
					menor++;
					menorh[hora]++;
				}
				else{
					skynet++;
					skyneth[hora]++;
				}
			}
			if(fdp[0]=='C'){
				chacals2++;
				chacals2h[hora]++;
			}
			if(fdp[0]=='R'){
				lindo++;
				lindoh[hora]++;
			}
			if(fdp[0]=='D'){
				opressao++;
				opressaoh[hora]++;
			}
			if(fdp[0]=='P'){
				gatos++;
				gatosh[hora]++;
			}
			cont=1;
		}

		//printf("%d/%d/%d\n",dia,mes,ano );
		cont2++;
	}

	
	/*printf("mes: %d -- total de: %d mensagens|\n",comp,cont);
	printf("msg enviadas-> Fabio=%d| ",fabio );
	printf("Chacal=%d| Roner=%d| Menor=%d| Demon=%d| Meitcher=%d| Pincel=%d|",chacals2,lindo,menor,opressao,skynet,gatos );
	cont=0;*/
	printf("%d,",comp);
	printf("%d,",fabio );
	printf("%d,%d,%d,%d,%d,%d,",chacals2,lindo,menor,opressao,skynet,gatos );
	/*while(cont<24){
		//printf("hora-> |  0   |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |  10  |  11  |\n");
		//printf("       | %d   |  %d  |  %d  |  %d  |  %d  |  %d  |  %d  |  %d  |  %d  |  %d  |  %d  |  %d  |\n\n",horamsg[0],horamsg[1],horamsg[2],horamsg[3],horamsg[4],horamsg[5],horamsg[6],horamsg[7],horamsg[8],horamsg[9],horamsg[10],horamsg[11] );
		//printf("hora-> |  12  |  13  |  14  |   15 |  16  |  17  |  18  |  19  |  20  |  21  |  22  |  23  |\n");
		//printf("       | %d   |  %d  |  %d  |  %d  |  %d  |  %d  |  %d  |  %d  |  %d  |  %d  |  %d  |  %d  |\n",horamsg[12],horamsg[13],horamsg[14],horamsg[15],horamsg[16],horamsg[17],horamsg[18],horamsg[19],horamsg[20],horamsg[21],horamsg[22],horamsg[23] );
			
			printf("hora->[%d] - [%d]\n",cont,horamsg[cont] );
			cont++;
		}*/
	printf("\n");
	/*printf("total msg enviadas-> Fabio=%d|",totalf );
	printf("Chacal=%d|Roner=%d|Menor=%d|Demon=%d|Meitcher=%d|Pincel=%d|\n",totalc,totall,totalm,totalo,totals,totalg );
 	*/
 	
	printf("total,%d,",totalf );
	printf("%d,%d,%d,%d,%d,%d,",totalc,totall,totalm,totalo,totals,totalg );
 	/*printf("total de msg por horas somados no mes\n");
 	cont=0;
 	while(cont<24){
		printf("hora->[%d] - [%d]\n",cont,totalhoramsg[cont] );
		cont++;
	}*/
	cont=0;
	printf("\n\n");
	while(cont<24){
		printf("%d,%d,%d,%d,%d,%d,%d,%d,\n",cont,fabioh[cont],chacals2h[cont],lindoh[cont],menorh[cont],opressaoh[cont],skyneth[cont],gatosh[cont] );
		
		cont++;
	}


	fclose(data);
	return 0;
}