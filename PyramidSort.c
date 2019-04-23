#include <stdio.h>
#include <malloc.h>

int swaps=0,compares=0;

void restore_heap(int *arr, int prev_lvl, int end){
	int maxChild,stop = 0;
	while ((prev_lvl * 2 <= end) && !stop){
		if (prev_lvl * 2 == end)
			maxChild = prev_lvl * 2;
		else if (arr[prev_lvl * 2] > arr[prev_lvl * 2 + 1])
		  	maxChild = prev_lvl * 2;
		else
		 	maxChild = prev_lvl * 2 + 1;
		compares++;
		if (arr[prev_lvl] < arr[maxChild]){
			swaps++;
			int temp = arr[prev_lvl];
			arr[prev_lvl] = arr[maxChild];
			arr[maxChild] = temp;
			prev_lvl = maxChild;
		}
		else
			stop = 1;
	}
}

void sorting(int *arr, size_t arr_len){
	for (int i = (arr_len / 2) - 1; i >= 0; i--)
		restore_heap(arr, i, arr_len - 1);
	for (int i = arr_len - 1; i >= 1; i--)
	{
		swaps++;
	    int tmp = arr[0];
	    arr[0] = arr[i];
	    arr[i] = tmp;
	    restore_heap(arr, 0, i - 1);
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
