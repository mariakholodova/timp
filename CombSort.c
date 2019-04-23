#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int swaps=0,compares=0;

void sorting(int* arr,size_t arr_len) 
{	
	int tmp,k,step=arr_len;
	while(arr_len>1) {
		step/=1.24;
		if (step<1)
			step=1;
		k=0;
		for (int i=0; i+step<arr_len;i++) {
			compares++;
			if(arr[i]>arr[i+step]) {
				tmp=arr[i];
				arr[i]=arr[i+step];
				arr[i+step]=tmp; 	
				k=i;
				swaps++;
			}
		}
		if (step==1)
			arr_len=k+1; 
	}
}

int main(){
    int n;
    scanf("%d",&n);
    int *mas = malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)
        scanf("%d",&mas[i]);
    sorting(mas,n);
    for(int i=0;i<n;i++)
        printf("%d ",mas[i]);
    printf("\n");
    return 0;
}
