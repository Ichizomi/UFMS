#include<stdio.h>
#include<stdlib.h> //malloc, free, rand

int busca_binaria_R(int *v, int esq, int dir, int x){

	int meio;

	if(esq == dir -1){
		return dir;
	}	
	else{
		meio = (esq + dir) / 2;
		if(v[meio] < x){
			return busca_binaria_R(v, meio, dir, x);
		}
		else{
			return busca_binaria_R(v, esq, meio, x);
		}
	}

}

int main(void){
	int *v; //novo vetor v, alocado especificamente pela função malloc
	int n, i;
	//int v[MAX]; Antigo vetor V, definido pelo max
	int j, k;
	int x, result;

	//casos de teste
	scanf("%d", &k);
	for(j=0;j<k; j++){
	
		//tamanho do vetor
		scanf("%d", &n);
		v= (int *) malloc(n * sizeof(int)); //malloc retorna a quantidade de bits necessaria para o tamanho do vetor multiplicando seu tamanho pela size of um inteiro, dps usamos um cast para transformar esse dado vazio em um inteiro ponteiro. (int *)
		if(v == NULL){
		printf("problema na alocação da memória");
		}
		else{ //Continuar Programa
			//ler vetor	
			for(i=0;i<n;i++){
			scanf("%d", v+i);//scanf("%d", &v[i]); 
			}
			//numero a ser buscado		
				scanf("%d", &x);
				result = busca_binaria_R(v, -1, n, x);
				printf("%d\n", result);
			
			//liberar memória antes do laço continuar
			free(v);
		}


	}

}
