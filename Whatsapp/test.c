#include <stdio.h>
#include "C:\Users\Alienware\OneDrive\Documentos\Algoritmos\Whatsapp\plot\koolplot.h"
#include "C:\Users\Alienware\OneDrive\Documentos\Algoritmos\Whatsapp\plot\graphics.h"

int main(void){
	int dia, mes, ano, hora, minuto;
	FILE *data;
	char fdp[20];


	
	/*data=fopen("ohana.txt","r");
	fscanf(data, "%*[^\n]\n", NULL);
	fscanf(data, "%*[^\n]\n", NULL);
	fscanf(data,"%d/%d/%d, %d:%d - %s",&dia,&mes,&ano,&hora,&minuto,fdp);
	fscanf(data, "%*[^\n]\n", NULL);
	//fclose(data);
	printf("%d/%d/%d - %d/%d -%s\n",dia,mes,ano,hora,minuto,fdp );

	fscanf(data,"%d/%d/%d, %d:%d - %s",&dia,&mes,&ano,&hora,&minuto,fdp);
	fscanf(data, "%*[^\n]\n", NULL);
	printf("%d/%d/%d - %d/%d -%s\n",dia,mes,ano,hora,minuto,fdp );
	fscanf(data,"%d/%d/%d, %d:%d - %s",&dia,&mes,&ano,&hora,&minuto,fdp);
	fscanf(data, "%*[^\n]\n", NULL);
	printf("%d/%d/%d - %d/%d -%s\n",dia,mes,ano,hora,minuto,fdp );
	fscanf(data,"%d/%d/%d, %d:%d - %s",&dia,&mes,&ano,&hora,&minuto,fdp);
	fscanf(data, "%*[^\n]\n", NULL);
	printf("%d/%d/%d - %d/%d -%s\n",dia,mes,ano,hora,minuto,fdp );


	fclose(data);
	*/
	Plotdata x(-3.0,3.0), y=sin(x);
	plot(x,y);


	return 0;
}