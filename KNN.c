#include <stdio.h>
#include <math.h>
#include <string.h>

void print();
void tudo();

float teste[769][9];

float exemplo[] = {6, 148, 72, 35, 0, 33.6, 0.627, 50, -1.0};
	
typedef struct{
	int index;
	float dist;
	}vet;
 vet met[769];
	
int main(){

	FILE *arquivo;
	arquivo = fopen("data.txt","r");
	
	int i =0;
	
	
	if(arquivo == NULL) 
		printf("erro ao abrir"); 	
	else {
	while(!feof(arquivo)){
		fscanf(arquivo,"%f[^,]",&teste[i][0]);
		fseek(arquivo,+1,SEEK_CUR);
		fscanf(arquivo,"%f[^,]",&teste[i][1]);
		fseek(arquivo,+1,SEEK_CUR);
		fscanf(arquivo,"%f[^,]",&teste[i][2]);
		fseek(arquivo,+1,SEEK_CUR);
		fscanf(arquivo,"%f[^,]",&teste[i][3]);
		fseek(arquivo,+1,SEEK_CUR);
		fscanf(arquivo,"%f[^,]",&teste[i][4]);
		fseek(arquivo,+1,SEEK_CUR);
		fscanf(arquivo,"%f2[^,]",&teste[i][5]);
		fseek(arquivo,+1,SEEK_CUR);
		fscanf(arquivo,"%f3[^,]",&teste[i][6]);
		fseek(arquivo,+1,SEEK_CUR);
		fscanf(arquivo,"%f[^,]",&teste[i][7]);
		fseek(arquivo,+1,SEEK_CUR);
		fscanf(arquivo,"%f",&teste[i][8]);



	i++;
	}	}
	print(--i);
	tudo(--i);
	
	return  0;
}	
	
	
void print(int i){	
	int j = 0;
	for(;j<=i;j++){
	
		printf("%1f ",teste[j][0]);
		printf("%1f ",teste[j][1]);
		printf("%1f ",teste[j][2]);
		printf("%1f ",teste[j][3]);
		printf("%1f ",teste[j][4]);
		printf("%.2f ",teste[j][5]);
		printf("%.3f ",teste[j][5]);
		printf("%1f ",teste[j][6]);
		printf("%f\n",teste[j][7]);
		
		}
}

void tudo(int i){
	int p =0;
	for(;p<i;p++){ 
		met[p].dist = (pow((teste[p][0] - exemplo[0]),2))
 		 + (pow((teste[p][1] - exemplo[1]),2))
		 + (pow((teste[p][2] - exemplo[2]),2))
		 + (pow((teste[p][3] - exemplo[3]),2))
		 + (pow((teste[p][4] - exemplo[4]),2))
		 + (pow((teste[p][5] - exemplo[5]),2))
		 + (pow((teste[p][6] - exemplo[6]),2))
		 + (pow((teste[p][7] - exemplo[7]),2));
	
		met[p].dist = sqrt(met[p].dist);
		met[p].index = p;
	//	printf("%d\t",met[p].index); //para teste
	//	printf("%f\n",met[p].dist);	//para teste
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
		printf("%f\n",met[tt].dist);
	}        
		
		int temp,ii =0, ee =0;
		printf("Os 5 mais proximos:\n");
		for(tt=0; tt<5;tt++){
			if(teste[temp][9] == 1.0){
				ii++;}
				else{
					ee++;}
			temp = met[tt].index;
					printf("%1f ",teste[temp][0]);
					printf("%1f ",teste[temp][1]);
					printf("%1f ",teste[temp][2]);
					printf("%1f ",teste[temp][3]);
					printf("%1f ",teste[temp][4]);
					printf("%.2f ",teste[temp][5]);
					printf("%.3f ",teste[temp][6]);
					printf("%1f ",teste[temp][7]);
					printf("%f\n",teste[temp][8]);           
			}
			ii > ee ? printf("A classe é tested_positive") : printf("A classe é tested_negative");


}

