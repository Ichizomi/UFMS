#include<stdio.h>
#define MAX 99

void bubble_sort(int n, int v[MAX]){

	int i, j, temp;
	for(i=n-1; i>0; i--){
		
		for(j=0;j<i;j++){

			if(v[j] > v[j+1]){
				temp = v[j+1]; 
				v[j+1] = v[j];
				v[j] = temp;
			}	

		}
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

		bubble_sort(n, vetor);

		//Imprimir vetor ordenado
		for(j=0;j<n; j++){
			printf("%d ", vetor[j]);
		}
		printf("\n");
	}
}
