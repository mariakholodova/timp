#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

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
    srand(time(NULL));
    printf("%10s %10s %10s %10s %10s %10s %10s %10s %10s\n","N","N*log(N)","N^2","N^3","time","swaps","cmps","best time","worst time");
    int sizes[]={1, 2, 3, 4, 5, 10, 15, 20, 25, 30, 50, 75, 100, 250, 500};
    for(int i=0;i<(sizeof(sizes)/sizeof(int));i++){
        double res_time=0;
        int res_swaps=0,res_compares=0;
        for(int j=0;j<1000;j++){
            swaps=0;
        	compares=0;
            int* arr=malloc(sizeof(int)*sizes[i]);
            for(int j=0;j<sizes[i];j++)
                arr[j]=rand()%sizes[i];
            clock_t start_time=clock();
            sorting(arr,sizes[i]);
            double now = (double)(clock()-start_time)/CLOCKS_PER_SEC;
            res_time+=now;
            res_swaps+=swaps;
            res_compares+=compares;
            free(arr);
        }
        
        res_swaps/=1000;
        res_compares/=1000;
        res_time/=1000;
        
        int* best=malloc(sizeof(int)*sizes[i]);
        int* worst=malloc(sizeof(int)*sizes[i]);
        for(int j=0;j<sizes[i];j++){
            best[j]=j;
            worst[j]=sizes[i]-j;
        }

        clock_t start_time=clock();
        sorting(best,sizes[i]);
        double best_time = (double)(clock()-start_time)/CLOCKS_PER_SEC;
        free(best);

        start_time=clock();
        sorting(worst,sizes[i]);
        double worst_time = (double)(clock()-start_time)/CLOCKS_PER_SEC;
        free(worst);

        printf("%10d %10d %10d %10d %10f %10d %10d %10f %10f\n", sizes[i],(int)(sizes[i]*log(sizes[i])),(int)pow(sizes[i],2),(int)pow(sizes[i],3),res_time,res_swaps,res_compares,best_time,worst_time);
    }
    return 0;
}