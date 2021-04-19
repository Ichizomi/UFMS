#include <stdio.h>
#include <stdlib.h>

// gerador de vetores com quantidade de elementos variando entre
// 1 e m. m é um valor inteiro passado como argumento para a função
// main. 
// para compilar: gcc gerador.c -o gerador
// para executar: ./gerador m > casos_de_teste.txt 
// m deve ser um numero inteiro; 
// os dados serão direcionados para o arquivo casos_de_teste.txt; 
// se o arquivo não existe será criado; 
// se o arquivo já existe, será sobrescrito;

int main (int argc, char **argv)
{

	//printf("argc %d  argv %s\n", argc, argv[1]);
	
	int m=atoi(argv[1]); // quantidade de casos de teste
	int n=1;  // quantidade de elementos do vetor que sera gerado
	int i;

	printf("%d",m);

	while (n<=m)
	{
		printf("\n");
		printf("%d\n",n);
		for(i=1;i<=n;i++)
			printf("%d ",rand()%200);
		n++;
	}

}
