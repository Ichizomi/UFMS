#include<stdio.h>
#define MAX 3000
//   0  1  2  3
// v[4, 2, 3, 6]
// i=0 min = 0 j = 1
// 

void selection_sort(int n, int v[MAX]){
	int i, j, min, temp;
	for(i=0;i<n-1; i++){
		min = i;
		for(j = i+1;j<n; j++){
			if(v[j] < v[min]){			
				min = j;
			}
		}
		temp = v[min];
		v[min] = v[i];
		v[i] = temp;	
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

		selection_sort(n, vetor);

		//Imprimir vetor ordenado
		for(j=0;j<n; j++){
			printf("%d ", vetor[j]);
		}
		printf("\n");
	}
}
