#include <stdio.h>
#include <math.h>
int main(void){
	int n,res=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int t;
		scanf("%d",&t);
		res+=pow(-1,i+1)*pow(t,2);
	}
	printf("%d\n",res);
	return 0;
}
