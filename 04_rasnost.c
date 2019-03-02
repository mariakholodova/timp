#include <stdio.h>

int main(void){
	int n,res=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int t;
		scanf("%d",&t);
		res-=t;
	}
	printf("%d",t);
	return 0;
}
