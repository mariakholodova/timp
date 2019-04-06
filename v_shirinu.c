#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    struct node *l,*r,*p;
    int data;
} node;

typedef struct tree
{
    int values;
    struct node* root;
} tree;


void init(tree* t){
    t->root=t->values=0;
}

void insert(tree* t,int data){
    node* new = malloc(sizeof(node));
    new->data=data;
    new->l=new->r=new->p=0;
    if(t->root==0){
        t->root=new;
        t->values=1;
        return;
    }
    node* tmp=t->root;
    while(1){
        if(tmp->data==data){
            free(new);
            return;
        }
        if(data > tmp->data){
            if(tmp->r==0){
                tmp->r=new;
                tmp->r->p=tmp;
                t->values++;
                return;
            }
            else
                tmp=tmp->r;
        }
        else if(data < tmp->data){
            if(tmp->l==0){
                tmp->l=new;
                tmp->l->p=tmp;
                t->values++;
                return;
            }else
                tmp=tmp->l;
        }
    }
}

int main(){
    tree* Tree = malloc(sizeof(tree));
    init(Tree);
    int t,res=0;
    for(int i=0;i<7;i++){
        scanf("%d",&t);
        insert(Tree,t);
    }
    printTree(Tree);
    return 0;
}


void printTree(tree* t){
    if(t->root==0)
        printf("-\n");
    else{   
        node** nodes_to_print[2];
        nodes_to_print[0] = malloc(sizeof(node)*32);
        nodes_to_print[1] = malloc(sizeof(node)*32);
        int next_free_pos[2]={0,0},values_for_printing[2]={0,0},is_1=1;
        printf("%d ", t->root->data);
        nodes_to_print[0][next_free_pos[0]]=t->root->l;
        next_free_pos[0]++;
        nodes_to_print[0][next_free_pos[0]]=t->root->r;
        next_free_pos[0]++;
        values_for_printing[0]=1;

        while(values_for_printing[0] || values_for_printing[1]){
            values_for_printing[is_1]=0;
            for(int i=0;i<next_free_pos[1-is_1];i++){
                if(nodes_to_print[1-is_1][i]!=0){
                    printf("%d",nodes_to_print[1-is_1][i]->data);
                    nodes_to_print[is_1][next_free_pos[is_1]]=nodes_to_print[1-is_1][i]->l;
                    next_free_pos[is_1]++;
                    nodes_to_print[is_1][next_free_pos[is_1]]=nodes_to_print[1-is_1][i]->r; 
                    next_free_pos[is_1]++;
                    if(nodes_to_print[1-is_1][i]->l!=0 || nodes_to_print[1-is_1][i]->r!=0)
                        values_for_printing[is_1]=1;
                }
                if(i+1!=next_free_pos[1-is_1]){
                    printf(" ");
                }
            }
            next_free_pos[1-is_1]=0;
            values_for_printing[1-is_1]=0;
            free(nodes_to_print[1-is_1]);
            nodes_to_print[1-is_1] = malloc(sizeof(node)*32);
            is_1^=1;
	    printf(" ");
        }
	printf("\n");
    }
}
