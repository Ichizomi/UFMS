#include<stdio.h>
#define MAX 3000
int contador_comp = 0;
/*
Implementação da Versão com contador
p = 0 q = n-1
1- v[10 5 7 4]
	
	...
*/
void intercala(int p, int q, int r, int v[MAX]){
	int i, j, k, w[MAX];
	
	i = p;
	j = q;
	k = 0;
	while (i<q && j<r){
		contador_comp++;
		if(v[i] < v[j]){
			w[k] = v[i];
			i++;
		}
		else{
			w[k] = v[j];
			j++;
		}
		k++;
	}
	while(i < q){
		w[k] = v[i];
		i++;
		k++;
	}
	while(j < r){
		w[k] = v[j];
		j++;
		k++;
	}
	for(i=p; i<r; i++){
		v[i] = w[i-p];	
	}

}

void mergesort(int p, int r, int v[MAX]){
	int q;
	if(p < r - 1){
		q = (p + r) /2;
		mergesort(p, q, v);
		mergesort(q, r, v);
		intercala(p, q, r, v);
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

		mergesort(0, n-1, vetor);

		//Imprimir vetor ordenado
		for(j=0;j<n; j++){
			printf("%d ", vetor[j]);
		}
		printf("\n%d\n", contador_comp);
	}
}
