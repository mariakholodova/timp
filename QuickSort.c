#include <stdio.h>
#include <stdlib.h>

int swaps=0,compares=0;

void sorting(int* arr, int arr_len) {
    int i = 0, j = arr_len;
    int temp, p;
    p = arr[arr_len/2];
    do {
        while ( arr[i] < p ) i++;
        while ( arr[j] > p ) j--;

        if (i <= j) {
        	compares++;
        	if(arr[i]>arr[j]){
        		temp = arr[i]; 
	            arr[i] = arr[j]; 
	            arr[j] = temp;
	            swaps++;
        	}
            i++; 
            j--;
        }
    } while ( i<=j );
    if ( j > 0 ) 
        sorting(arr, j);
    if ( arr_len > i ) 
        sorting(arr+i, arr_len-i);
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
