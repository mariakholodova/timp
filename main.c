#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int* mas;
    int pos;
} stack;

int in_mas(int* mas,int size,int elem){
    for(int i=0;i<size;i++)
        if(mas[i]==elem)
            return 1;
    return 0;
}

int calc_length(int** mas,int n,int* path){
    int res=0;
    for(int i=1;i<n;i++){
        res+=mas[path[i-1]][path[i]]; 
    }
    return res; 
}

int calc_path(int** mas,int n,stack stk){
    int res=0;
    for(int i=1;i<n;i++){ 
        if(mas[stk.mas[i-1]][stk.mas[i]] == 0) 
            return -1; 
        res+=mas[stk.mas[i-1]][stk.mas[i]]; 
    }
    return res; 
}

int bruteforce(int** mas,int n,stack stk,int* path){
    int length=-1;
    if(stk.pos==n){
        
        int tmp = calc_path(mas,n,stk);
        
        if(tmp!=-1 && (tmp<length || length==-1)){
            length = tmp;
            for(int i=0;i<n;i++){
                path[i]=stk.mas[i];
            }
        }
    }
    else
        for(int i=0;i<n;i++){
            if(!in_mas(stk.mas,n,i)){
                stk.mas[stk.pos]=i;
                stk.pos++;
                int tmp = bruteforce(mas,n,stk,path); 
                if(tmp!=-1 && (tmp<length || length==-1)){ 
                    length = tmp; 
                }
                stk.pos--;
                stk.mas[stk.pos]=-1;
            }
        }
    return length; 
}

void algo_floyd_vorshell(int** mas, int n)
{
    for (int mid=0; mid<n; mid++)
        for (int i=0; i<n; i++)  
            for (int j=0; j<n; j++) 
                if (mas[i][mid] && mas[mid][j] && i!=j) 
                    if (mas[i][j]>mas[i][mid]+mas[mid][j] || mas[i][j]==0) 									
                        mas[i][j]=mas[i][mid]+mas[mid][j];  
}

int main(){
    int n;
    scanf("%d",&n);
    int* path = malloc(sizeof(int)*n);
    int** mas = malloc(sizeof(int*)*n);
    for(int i=0;i<n;i++)
        mas[i] = malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&mas[i][j]);

    stack stk;
    stk.mas = malloc(sizeof(int)*n);
    stk.pos = 0;
    for (int i = 0; i < n; ++i)
    {
        stk.mas[i]=-1;
    }

    int length = bruteforce(mas,n,stk,path);
    printf("%s", "Path: ");
    printf("Length: %d\n", calc_length(mas,n,path));
	for(int i=0;i<n;i++)
        printf("%d ", path[i]);
	printf("\n");

	algo_floyd_vorshell(mas,n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
            printf("%d ", mas[i][j]);
        printf("\n");
	}

    for(int i=0;i<n;i++)
        free(mas[i]);
	free(mas);
	return 0;
}
