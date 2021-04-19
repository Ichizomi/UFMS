#include<stdio.h>


int potencia(int x, int n){
	if(n == 0){
	return 1;
	}
	else if(n%2 == 0){
	return potencia(x, n/2) * potencia(x, n/2);
	}
	else if(n%2 == 1){
	return potencia(x, n - 1) * x;
	}

}

int main(void){
	int i, j;
	scanf("%d", &j);
	for(i=0;i<j;i++){
		int a, b, result;
		scanf("%d", &a);
		scanf("%d", &b);
		result = potencia(a, b);
		printf("%d\n", result);
	}
}
