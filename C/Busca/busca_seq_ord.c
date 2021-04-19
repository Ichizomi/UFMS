#include<stdio.h>
#define MAX 100
int busca_sequencial(int n, int v[MAX], int x){
	int k;
	for(k= n-1; k>=0 && v[k] >= x; k--);
	return k + 1;
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
		result = busca_sequencial(n, v, x);
		printf("%d\n", result);
	}

}
