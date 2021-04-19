#include<stdio.h>
//4 = 4*3*2*1 = 24

int fatorial(int n){
	if(n<=0){
	return 1;
	}
	else{
		return n * fatorial(n-1);
	}

}

int main(void){
	int n;
	int result;
	scanf("%d",&n);
	result = fatorial(n);
	printf("%d", result);
}