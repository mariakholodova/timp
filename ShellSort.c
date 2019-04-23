#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int swaps=0,compares=0;

void sorting(int* arr,size_t arr_len)
{
	int tmp;
	for(int k = arr_len / 2; k > 0; k /= 2){
		for(int i = k; i < arr_len; i++)
        {
            tmp = arr[i];
            for(int j = i; j >= k; j -= k)
            {
            	compares++;
                if(tmp < arr[j - k]){
                    arr[j] = arr[j - k];
                    swaps++;
                }
                else
                    break;
            }
            arr[j] = tmp;
        }
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
