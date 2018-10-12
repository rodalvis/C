#include <stdio.h>

typedef struct{
	int id;
	char classe[25];
}diabetes;
 
 diabetes teste[5];

int main(){
 
	FILE *arquivo;
	arquivo = fopen("teste.txt","r");
	
	int i =0;
	int j = 0;
	//char s[27];
	
	if(arquivo == NULL) 
		printf("erro"); 	
	else {
	while(!feof(arquivo)){
		fscanf(arquivo,"%d[^,]",&teste[i].id);
		fscanf(arquivo,"%[^\n]%*c",&teste[i].classe);

	i++;
	}	}
	i--;
	
	for(;j<=i;j++){
		printf("%d",teste[j].id);
		printf("%s\n",teste[j].classe);
		
		}
	return  0;
}
