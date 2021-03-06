#include<stdio.h>
#define MAX 3000
/*
Implementação da Versão com contador
1- v[10 5 7 4]
	contador= 0 	
	i = 1
	x = 5(v[1])
	j = 0
	contador= 1(if 10 > 5 troca)
   v[5 5 7 4]
   v[10 5 7 4]
	i = 2
	j = 1
	...
*/

int insertion_sort(int n, int v[MAX]){
	int i, j, x, z;
	int contador_comp = 0;
	for(i=1;i<n;i++){
		x = v[i];
		for(z=i-1;z>=0;z--, contador_comp++){
		}
		for(j=i-1;j>=0 && v[j] > x; j--){
			v[j+1] = v[j];
		}
		v[j+1] = x;
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

		contador_comp = insertion_sort(n, vetor);

		//Imprimir vetor ordenado
		for(j=0;j<n; j++){
			printf("%d ", vetor[j]);
		}
		printf("\n%d\n", contador_comp);
	}
}
