#include <stdio.h>
#include <locale.h>

typedef struct{
	int a;
	int b;
	int c;
	int d;
	int e;
	float f;
	float g;
	int h;
	//int i;
	char classe[17];
}diabetes;
 
 diabetes teste[769];

int main(){
 //setlocale(LC_ALL,"");
	FILE *arquivo;
	arquivo = fopen("teste.txt","r");
	//system("pwd");
	int i =0;
	int j = 0;
	int temp=0;
	
	if(arquivo == NULL) 
		printf("erro ao abrir"); 	
	else {
	while(!feof(arquivo)){
		fscanf(arquivo,"%d[^,]",&teste[i].a);
		//fscanf(arquivo,"%d[^,]",&temp);
		//teste[i].a = temp % 100 ;
		fseek(arquivo,+1,SEEK_CUR);
		fscanf(arquivo,"%d[^,]",&teste[i].b);
		fseek(arquivo,+1,SEEK_CUR);
		fscanf(arquivo,"%d[^,]",&teste[i].c);
		fseek(arquivo,+1,SEEK_CUR);
		fscanf(arquivo,"%d[^,]",&teste[i].d);
		fseek(arquivo,+1,SEEK_CUR);
		fscanf(arquivo,"%d[^,]",&teste[i].e);
		fseek(arquivo,+1,SEEK_CUR);
		fscanf(arquivo,"%f2[^,]",&teste[i].f);
		fseek(arquivo,+1,SEEK_CUR);
		fscanf(arquivo,"%f2[^,]",&teste[i].g);
		fseek(arquivo,+1,SEEK_CUR);
		fscanf(arquivo,"%d[^,]",&teste[i].h);
		fseek(arquivo,+1,SEEK_CUR);
		fscanf(arquivo,"%[^\n]%*c",&teste[i].classe);

		printf("%1d ",teste[i].a);
		printf("%1d ",teste[i].b);
		printf("%1d ",teste[i].c);
		printf("%1d ",teste[i].d);
		printf("%1d ",teste[i].e);
		printf("%.2f ",teste[i].f);
		printf("%.3f ",teste[i].g);
		printf("%1d ",teste[i].h);
		//printf("%d",teste[i].i);
	printf("%s\n",teste[i].classe);


	i++;
	}	}
	i--;
	
	for(;j<=i;j++){

		//printf("%s\n",teste[j].classe);
		
		}
	return  0;
}
