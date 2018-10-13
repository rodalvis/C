#include <stdio.h>
#include <math.h>
#include <string.h>

void print();
void tudo();

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
 diabetes exemplo;  //6, 148, 72, 35, 0, 33.6, 0.627, 50, -1.0
	
typedef struct{
	int index;
	float dist;
	}vet;
 vet met[769];
	
int main(){

	  exemplo.a = 6 ;
	  exemplo.b = 140;
	  exemplo.c = 72;
	  exemplo.d = 35;
	  exemplo.e = 0;
	  exemplo.f = 33.6;
	  exemplo.g = 0.627;
	  exemplo.h = 50;
	  //exemplo.classe= "sem";


	FILE *arquivo;
	arquivo = fopen("data.txt","r");
	
	int i =0;
	
	//nt temp=0;
	
	if(arquivo == NULL) 
		printf("erro ao abrir"); 	
	else {
	while(!feof(arquivo)){
		fscanf(arquivo,"%d[^,]",&teste[i].a);
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



	i++;
	}	}
	print(--i);
	tudo(--i);
	
	return  0;
}	
	
	
void print(int i){	
	int j = 0;
	for(;j<=i;j++){
	
		printf("%1d ",teste[j].a);
		printf("%1d ",teste[j].b);
		printf("%1d ",teste[j].c);
		printf("%1d ",teste[j].d);
		printf("%1d ",teste[j].e);
		printf("%.2f ",teste[j].f);
		printf("%.3f ",teste[j].g);
		printf("%1d ",teste[j].h);
		printf("%s\n",teste[j].classe);
		
		}
}

void tudo(int i){
	int p =0;
	for(;p<i;p++){ 
		met[p].dist += sqrt( pow( ( teste[p].a - exemplo.a ),2) );
		met[p].dist += sqrt( pow( ( teste[p].b - exemplo.b ),2) );
		met[p].dist += sqrt( pow( ( teste[p].c - exemplo.c ),2) );
		met[p].dist += sqrt( pow( ( teste[p].d - exemplo.d ),2) );
		met[p].dist += sqrt( pow( ( teste[p].e - exemplo.e ),2) );
		met[p].dist += sqrt( pow( ( teste[p].f - exemplo.f ),2) );
		met[p].dist += sqrt( pow( ( teste[p].g - exemplo.g ),2) );
		met[p].dist += sqrt( pow( ( teste[p].h - exemplo.h ),2) );
		met[p].index = p;
		printf("%d\t",met[p].index);
		printf("%f\n",met[p].dist);
		}
	int j,t,m;
	float aux;
	for(m =0;m<i;m++){
	for(j = 0; j< i;j++){
		if(met[j].dist > met[j+1].dist){
			aux = met[j].dist;
			met[j].dist = met[j+1].dist;
			met[j+1].dist = aux;
			t = met[j].index;
			met[j].index = met[j+1].index;
			met[j+1].index = t;
			}
		}	}
	int tt =0;
	for(;tt<i;tt++){
		printf("%d\t",met[tt].index);
		printf("%f\n",met[tt].dist);}
		
		int temp,ii =0, ee =0;
		for(tt=0; tt<5;tt++){
			if(strcmp(teste[temp].classe , "tested_positive")){
				ii++;}
				else{
					ee++;}
			temp = met[tt].index;
					printf("%1d ",teste[temp].a);
					printf("%1d ",teste[temp].b);
					printf("%1d ",teste[temp].c);
					printf("%1d ",teste[temp].d);
					printf("%1d ",teste[temp].e);
					printf("%.2f ",teste[temp].f);
					printf("%.3f ",teste[temp].g);
					printf("%1d ",teste[temp].h);
					printf("%s\n",teste[temp].classe);
					ii > ee ? printf("tested_positive") : printf("tested_negative");
			}
	}
