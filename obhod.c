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

int find(tree* t,int data,node** n){
    if(t->root==0)
        return 1;
    node* tmp=t->root;
    while(1){
        if(tmp==0)
            return 1;
        if(tmp->data==data){
            *n=tmp;
            return 0;
        }
        if(data > tmp->data)
            tmp=tmp->r;
        else if(data < tmp->data)
            tmp=tmp->l;
    }
}

void clearnode(node* n){
    if(n!=0){
        if(n->l!=0)
            clearnode(n->l);  
        if(n->r!=0)
            clearnode(n->r);
    }
    free(n);
    n=0;
}

void clear(tree* t){
    clearnode(t->root);
    init(t);
}

int removeMin(node* n){
    if(n!=0){
        if(n->l!=0)
            return removeMin(n->l);
        else{
            if(n->p!=0){
                if(n->r!=0){
                    n->p->r=n->r;
                    n->r=n->p;
                }else
                    n->p->l=0;    
            }
            int res=n->data;
            free(n);
            n=0;
            return res;
        }
    }   
}

int _remove(tree* t,int data){
    if(t->root==0)
        return 1;
    node* tmp=t->root;
    while(1){
        if(tmp==0)
            return 1;
        if(data > tmp->data)
            tmp=tmp->r;
        else if(data < tmp->data)
            tmp=tmp->l;
        else{
            t->values--;
            if(tmp->l==0 && tmp->r==0){
                if(tmp->p){
                    if(tmp->p->l==tmp)
                        tmp->p->l=0;
                    else if(tmp->p->r==tmp)
                        tmp->p->r=0;
                }
            }
            else if(tmp->l!=0 && tmp->r==0){
                if(tmp->p!=0){
                    if(tmp->p->l==tmp)
                        tmp->p->l=tmp->l;
                    else if(tmp->p->r==tmp)
                        tmp->p->r=tmp->l;
                }
            }
            else if(tmp->l==0 && tmp->r!=0){
                if(tmp->p!=0){
                    if(tmp->p->l==tmp)
                        tmp->p->l=tmp->r;
                    else if(tmp->p->r==tmp)
                        tmp->p->r=tmp->r;
                }
            }
            else{
                tmp->data=removeMin(tmp->r);
                return 0;
            }
            free(tmp);
            tmp=0;
            return 0;
        }
    }
}


int rotateLeft(node* n){
    if(n->r!=0){
        node* tmp = n->r;
        n->r=0;
        n->p=tmp;
        tmp->p=0;
        tmp->l=n;
        return 0;
    }
    else
        return 1;
}

int rotateRight(node* n){
    if(n->l!=0){
        node* tmp = n->l;
        n->l=0;
        n->p=tmp;
        tmp->p=0;
        tmp->r=n;       
        return 0;
    }
    else
        return 1;
}

void printTree(tree* t);


void print_pryamoi(tree* t){
    node** stack = malloc(sizeof(node)*30);
    int last=29;
    printf("%d", t->root->data);
    stack[last--]=t->root->r;
    stack[last--]=t->root->l;
    while(last!=29){
        node* tmp=stack[++last];
        printf(" %d", tmp->data);
        if(tmp->r!=NULL)
            stack[last--]=tmp->r;
        if(tmp->l!=NULL)
            stack[last--]=tmp->l;
    }
    printf("\n");
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
    int t,m,res=0;
    scanf("%d".&m);
    for(int i=0;i<m;i++){
        scanf("%d",&t);
        insert(Tree,t);
    }
    printTree(Tree);
    print_pryamoi(Tree);
    print_obratni(Tree);
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
        printf("%d\n", t->root->data);
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
                }else{
                    printf("_");
                    nodes_to_print[is_1][next_free_pos[is_1]]=0;
                    next_free_pos[is_1]++;
                    nodes_to_print[is_1][next_free_pos[is_1]]=0;
                    next_free_pos[is_1]++;
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
            printf("\n");
        }
    }
}
