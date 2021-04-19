// Alunos: Lucas Grijó e Pietro Dal Moro

#include<stdio.h>
#define MAX 9999
int contador_comp_G = 0; //Contador de iterações global para o mergesort e o quicksort

// Métodos de Ordenação
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

void intercala(int p, int q, int r, int v[MAX]){
	int i, j, k, w[MAX];
	
	i = p;
	j = q;
	k = 0;
	while (i<q && j<r){
		contador_comp_G++;
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

void troca(int *x, int *y){
	int temp;
	temp = *y;
	*y = *x;
	*x = temp;
}

int separa(int p, int r, int v[MAX]){
	
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
		if(i<j){
			contador_comp_G++;
			troca(&v[i], &v[j]);
		}		
		else{
			contador_comp_G++;
			return j;
		}
	}
}

void quicksort(int p, int r, int v[MAX]){
	
	int q;
	if(p < r){
		q = separa(p,r,v);
		quicksort(p, q, v);
		quicksort(q+1, r, v);
	}

}

// Main
int main(void){

	int k, i , j, l; //Variaveis para estruturas de repetição
	int n; // Tamanho do vetor
	int contador_comp_L = 0; //Contador local de iterações globais para o bubble, selection e insertion sort
	int vetor_desordenado[MAX]; //Vetor original
	int vetor_auxiliar[MAX]; //Vetor auxiliar
	//Ler numero de casos de teste
	scanf("%d", &k);
	for(i=0; i<k; i++){	

			//Ler tamanho do vetor e os elementos do vetor
			scanf("%d", &n);
			for(j=0; j<n; j++){
				scanf("%d", &vetor_desordenado[j]);
			}
			//Gravar o vetor original ordenado em um vetor secundario, para armazenarmos o vetor original mesmo após a execução dos algoritmos de ordenação
			for(l = 0; l<n; l++){
				vetor_auxiliar[l] = vetor_desordenado[l];
			}
			//Chamar todos os métodos de ordenação e imprimir seu respectivo contador de iterações
			
			//Bubble Sort
			contador_comp_L = bubble_sort(n, vetor_auxiliar);
			printf("Bubble Sort : %d\n", contador_comp_L);
			
				//Resetar vetor auxiliar para o proximo método de ordenação e contador local
				contador_comp_L = 0;
				for(l = 0; l<n; l++){
					vetor_auxiliar[l] = vetor_desordenado[l];
				}
			
			//Selection Sort
			contador_comp_L = selection_sort(n, vetor_auxiliar);
			printf("Selection Sort : %d\n", contador_comp_L);

				//Resetar vetor auxiliar para o proximo método de ordenação e contador local
				contador_comp_L = 0;
				for(l = 0; l<n; l++){
					vetor_auxiliar[l] = vetor_desordenado[l];
				}

			//Insertion Sort
			contador_comp_L = insertion_sort(n, vetor_auxiliar);
			printf("Insertion Sort : %d\n", contador_comp_L);

				//Resetar vetor auxiliar para o proximo método de ordenação e contador local
				contador_comp_L = 0;
				for(l = 0; l<n; l++){
					vetor_auxiliar[l] = vetor_desordenado[l];
				}

			//Merge Sort
			mergesort(0, n-1, vetor_auxiliar);
			printf("Merge Sort : %d\n", contador_comp_G);

				//Resetar vetor auxiliar para o proximo método de ordenação e contador global
				contador_comp_G = 0;
				for(l = 0; l<n; l++){
					vetor_auxiliar[l] = vetor_desordenado[l];
				}

			//Quick Sort
			quicksort(0, n-1, vetor_auxiliar);
			printf("Quick Sort : %d\n\n", contador_comp_G);
				
				//Resetar vetor auxiliar para o proximo método de ordenação e contador global
				contador_comp_G = 0;
				for(l = 0; l<n; l++){
					vetor_auxiliar[l] = vetor_desordenado[l];
				}
			//fim de um caso de teste
	}
}
