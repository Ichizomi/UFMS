#include<stdio.h>


int cicloR(int n){
	printf("%d ", n);
	if(n == 1){
		printf("\n");		
		return 0;
	}
	if(n%2 == 0){
		return cicloR(n / 2);
	}
	else{
		return cicloR((n * 3) + 1);
	}	

}

int main(void){
	int i, j;
	scanf("%d", &j);
	for(i=0;i<j;i++){
		int n;
		scanf("%d", &n);
		cicloR(n);
	}
}
