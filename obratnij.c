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

void obratni(node* n){
    if (n!=NULL) {
        obratni(n->l);
        obratni(n->r);
        printf("%d ", n->data);
    }
}

void print_obratni(tree* t){
    obratni(t->root->l);
    obratni(t->root->r);
    printf("%d\n", t->root->data);
}


int main(){
    tree* Tree = malloc(sizeof(tree));
    init(Tree);
    int t,res=0;
    for(int i=0;i<7;i++){
        scanf("%d",&t);
        insert(Tree,t);
    }
    print_obratni(Tree);
    return 0;
}
