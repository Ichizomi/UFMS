#include<stdio.h>
#define MAX 3000
/*
Implementação da Versão com contador
1- v[10 5 7 4]
	i = 0
	j = 1
	min = 0
	contador= 0 
	contador= 1(if 5 < 10 troca)
	min = 1
	j = 2
	contador= 2(if 7 < 5 troca)	
	j = 3
	contador= 3(if 4 < 5 troca)
	min = 3
   v[4 5 7 10]

*/

int selection_sort(int n, int v[MAX]){
	int i, j, min, temp;
	int contador_comp = 0;
	for(i=0;i<n-1; i++){
		min = i;
		for(j = i+1;j<n; j++){
			contador_comp++;
			if(v[j] < v[min]){			
				min = j;
			}
		}
		temp = v[min];
		v[min] = v[i];
		v[i] = temp;	
	}
	return contador_comp;
}

int main(void){

	int k, i , j;
	int n;
	int vetor[MAX];
	int contador_comp;
	//Ler numero de casos de teste
	scanf("%d", &k);
	for(i=0; i<k; i++){	
		//Ler tamanho do vetor e os elementos do vetor
		scanf("%d", &n);
		for(j=0; j<n; j++){
			scanf("%d", &vetor[j]);
		}
		//Chamar função para ordenar o vetor

		contador_comp = selection_sort(n, vetor);

		//Imprimir vetor ordenado
		for(j=0;j<n; j++){
			printf("%d ", vetor[j]);
		}
		printf("\n%d\n", contador_comp);
	}
}
