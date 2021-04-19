#include<stdio.h>
#include<stdlib.h> //malloc, free, rand


void troca(int *x, int *y){
	int temp;
	temp = *y;
	*y = *x;
	*x = temp;
}

int separa(int p, int r, int *v){
	
	int x, i, j;
	x = v[p];
	i = p - 1;
	j = r + 1;
	while (1) {
		do {
			j--;	
		} while(v[j] > x);
		do {
			i++;
		} while(v[i] < x);
		if(i<j)
			troca(&v[i], &v[j]);
		else
			return j;
	}
}

void quicksort(int p, int r, int *v){
	
	int q;
	if(p < r){
		q = separa(p,r,v);
		quicksort(p, q, v);
		quicksort(q+1, r, v);
	}

}


int main(void){

	int k, i , j;
	int n;
	int *vetor;
	//Ler numero de casos de teste
	scanf("%d", &k);
	for(i=0; i<k; i++){	


		//Ler tamanho do vetor e alocar a memória
		scanf("%d", &n);
		vetor = (int *) malloc(n * sizeof(int));
		if(vetor == NULL){
		printf("problema na alocação da memória");
		}
		else{
			//Ler os elementos do vetor
			for(j=0; j<n; j++){
				scanf("%d", vetor+j);
			}
			//Chamar função para ordenar o vetor

			quicksort(0, n-1, vetor);

			//Imprimir vetor ordenado
			for(j=0;j<n; j++){
				printf("%d ", vetor[j]);
			}
			printf("\n");
			free(vetor);
		}
	}
}
