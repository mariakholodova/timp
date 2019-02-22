#include <stdio.h>
#include <math.h>
#include <limits.h>

int main(void)
{
	
	int a;
	scanf("%d",&a);
	
	int b;
	scanf("%d",&b);
	
	if (pow(a,b)>INT_MAX || pow(a,b)<INT_MIN){
		printf("Out of range!");
	}else{
		printf("%f",pow(a,b));
	}

	return 0;
}
