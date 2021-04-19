#include<stdio.h>


int mdc(int x, int y){
	if(x%y == 0){
		return y;
	}
	else{
		return mdc(y, x%y);
	}

}

int main(void){
	int i, j;
	scanf("%d", &j);
	for(i=0;i<j;i++){
		int x, y, result;		
		scanf("%d", &x);
		scanf("%d", &y);
		result = mdc(x, y);
		printf("%d\n", result);
	}
}
