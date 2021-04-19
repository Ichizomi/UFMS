#include<stdio.h>
#define MAX 100
int busca_binaria_R(int esq, int dir, int v[MAX], int x){

	int meio;

	if(esq == dir -1){
		return dir;
	}	
	else{
		meio = (esq + dir) / 2;
		if(v[meio] < x){
			return busca_binaria_R(meio, dir, v, x);
		}
		else{
			return busca_binaria_R(esq, meio, v, x);
		}
	}

}

int main(void){
	int n, i;
	int v[MAX];
	int j, k;
	int x, result;
	//tamanho do vetor
	scanf("%d", &n);
	//ler vetor	
	for(i=0;i<n;i++){
	scanf("%d", &v[i]);
	}
	//quantidade de buscas
	scanf("%d", &k);
	for(j=0;j<k;j++){
		scanf("%d", &x);
		result = busca_binaria_R(-1, n, v, x);
		printf("%d\n", result);
	}
}
