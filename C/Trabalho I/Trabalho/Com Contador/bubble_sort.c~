#include<stdio.h>
#define MAX 3000
/*
Implementação da Versão com contador
1- v[10 5 7 4]
	i = n-1(3)
	j = 0
	contador= 0 
	contador= 1(if 10 > 5 troca)
   v[5 10 7 4]
	i = 3
	j = 1(j++)
	contador= 2(if 10 > 7 troca)
   v[5 7 10 4]
	i = 3
	j = 2(j++)
	contador= 3(if 10 > 4 troca)
   v[5 7 4 10]
	i= 3
	j = 3(j++) break
	i = 2(i--)
	j = 0
	contador= 4(if 5 > 7 troca)
	...
*/
int bubble_sort(int n, int v[MAX]){

	int i, j, temp;
	int contador_comp = 0;
	for(i=n-1; i>0; i--){
		
		for(j=0;j<i;j++){
			contador_comp++;
			if(v[j] > v[j+1]){
				temp = v[j+1]; 
				v[j+1] = v[j];
				v[j] = temp;
			}	

		}
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

		contador_comp = bubble_sort(n, vetor);

		//Imprimir vetor ordenado
		for(j=0;j<n; j++){
			printf("%d ", vetor[j]);
		}
		printf("\n%d\n", contador_comp);
	}
}
