#include<stdio.h>
#define MAX 3000

void insertion_sort(int n, int v[MAX]){
	int i, j, x;
	for(i=1;i<n;i++){
		x = v[i];	
		for(j=i-1;j>=0 && v[j] > x; j--){
			v[j+1] = v[j];
		}
		v[j+1] = x;
	}
}

int main(void){

	int k, i , j;
	int n;
	int vetor[MAX];
	//Ler numero de casos de teste
	scanf("%d", &k);
	for(i=0; i<k; i++){	
		//Ler tamanho do vetor e os elementos do vetor
		scanf("%d", &n);
		for(j=0; j<n; j++){
			scanf("%d", &vetor[j]);
		}
		//Chamar função para ordenar o vetor

		insertion_sort(n, vetor);

		//Imprimir vetor ordenado
		for(j=0;j<n; j++){
			printf("%d ", vetor[j]);
		}
		printf("\n");
	}
}
