#include <stdio.h>
#include<stdlib.h>

struct point {
	int value;
	struct point *next;
	struct point *prev;
} point;

struct list2{		
	struct point* begin;
	struct point* end;	
} list2;

int isEmpty(struct list2* spisok);
struct point* find(struct list2* spisok,int k);
struct point* find_invers(struct list2* spisok,int k);
void init(struct list2* spisok,int value);
int push_back(struct list2* spisok, int x);
int push_front(struct list2* spisok,int x);
int clear(struct list2* spisok);
void _remove(struct list2* spisok, struct point *tmp);
int removeLast(struct list2* spisok,int x);
int insertAfter	(struct list2* spisok,int num, int data);
int insertBefore(struct list2* spisok,int num, int data);
void print(struct list2* spisok);
void print_invers(struct list2* spisok);


int main()
{
	int n,a;
	struct list2* spisok=(struct list2*)malloc(sizeof(struct list2));	
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		scanf("%d",&a);
		push_back(spisok,a);
	}
	print(spisok);
	
	int k[3];
	for(int i=0;i<3;i++){
		scanf("%d",&k[i]);
		if(find(spisok,k[i])!=NULL)
			printf("1");
		else
			printf("0");
	}
	printf("\n");

	int m;
	scanf("%d",&m);
	push_back(spisok,m);
	print_invers(spisok);

	int t;
	scanf("%d",&t);
	push_front(spisok,t);
	print(spisok);

	int j,x;
	scanf("%d%d",&j,&x);
	insertAfter(spisok,j,x);
	print_invers(spisok);

	int u,y;
	scanf("%d%d",&u,&y);
	insertBefore(spisok,u,y);
	print(spisok);

	int z;
	scanf("%d",&z);
	removeFirst(spisok,z);
	print_invers(spisok);

	int r;
	scanf("%d",&r);
	removeLast(spisok,r);
	print(spisok);

	clear(spisok);
	return 0;
}

int isEmpty(struct list2* spisok)
{
	return spisok->begin==NULL && spisok->end==NULL;
}

struct point* find(struct list2* spisok,int k)
{
	struct point *tmp=spisok->begin;
	while(tmp->value!=k){
		if(tmp->next!=NULL){
			tmp=tmp->next;
		}else{
			return 0;
		}
	}
	return tmp;
}

struct point* find_invers(struct list2* spisok,int k)
{
	struct point *tmp=spisok->end;
	while(tmp->value!=k){
		if(tmp->prev!=NULL){
			tmp=tmp->prev;
		}else{
			return 0;
		}
	}
	return tmp;
}

void init(struct list2* spisok,int value)
{
	struct point* tmp;
	tmp = (struct point*)malloc(sizeof(struct point));
	tmp->value=value;
	tmp->next=NULL;
	tmp->prev=NULL;
	spisok->begin = tmp;
	spisok->end = tmp;
}

int push_back(struct list2* spisok, int x)
{
	if(isEmpty(spisok)==1)
		init (spisok,x);
	else
	{
		struct point *tmp = (struct point*)malloc(sizeof(struct point));
		tmp->value=x;
		tmp->prev=spisok->end;
		tmp->next=NULL;
		spisok->end=tmp;
		tmp->prev->next=tmp;
	}
	return 0;
}

int push_front(struct list2* spisok,int x) 
{
	if(isEmpty(spisok)==1)
		init (spisok,x);
	else
	{
		struct point *tmp = (struct point*)malloc(sizeof(struct point));
		tmp->value=x;
		tmp->prev=NULL;
		tmp->next=spisok->begin;
		spisok->begin=tmp;
		tmp->next->prev=tmp;
	}
	return 0;
}

int clear(struct list2* spisok)
{
	if(isEmpty(spisok)==1)
	{
		struct point *tmp=spisok->begin;
		struct point *temp=NULL;
		while(tmp!=NULL)
		{
			temp=tmp->next;
			free(tmp);
			tmp=temp;
		}
		spisok->begin=NULL;
		spisok->end=NULL;
	}
}

void _remove(struct list2* spisok, struct point *tmp){
	if(tmp!=NULL){
		if (tmp==spisok->begin && tmp==spisok->end) {
			clear(spisok);
			return;
		}
		if (tmp==spisok->begin)
		{
			spisok->begin=tmp->next;
			tmp->next->prev=NULL;
		}
		else if(tmp==spisok->end)
		{
			spisok->end=tmp->prev;
			tmp->prev->next=NULL;
		}
		else if (tmp!=spisok->begin && tmp!=spisok->end)
		{
			tmp->next->prev=tmp->prev;
			tmp->prev->next=tmp->next;
		}
		free(tmp);
	}
}

int removeLast(struct list2* spisok,int x)
{
	struct point* element = find_invers(spisok,x);
	if (element!=NULL){
		_remove(spisok,element);
		return 0;
	}
	return -1;
}

int removeFirst(struct list2* spisok, int x)
{
	struct point* element = find(spisok,x);
	if (element!=NULL){
		_remove(spisok,element);
		return 0;
	}
	return -1;
}

int insertAfter	(struct list2* spisok,int num, int data)
{
	struct point* tmp = spisok->begin;
	for (int i = 1;i<num;i++)
	{
		tmp=tmp->next;
		if(tmp==NULL) 
			return -1;
	}
	struct point *temp = malloc(sizeof(point));
	temp->value=data;
	temp->next=tmp->next;
	temp->prev=tmp;
	tmp->next->prev=temp;
	tmp->next=temp;  
	return 0;   
}

int insertBefore(struct list2* spisok,int num, int data)
{
	struct point* tmp = spisok->begin;
	for (int i = 1;i<num;i++)
	{
		tmp=tmp->next;
		if(tmp==NULL) 
			return -1;
	}
	struct point *temp = malloc(sizeof(point));
	temp->value=data;
	temp->prev=tmp->prev;
	temp->next=tmp;
	tmp->prev=temp;
	temp->prev->next=temp;      
	return 0; 
}

void print(struct list2* spisok)
{
	struct point* tmp=spisok->begin;
	while(tmp->next!=NULL)
	{
		printf("%d ", tmp->value);
		tmp=tmp->next;
	}
	printf("%d\n", tmp->value);
}

void print_invers(struct list2* spisok)
{
	struct point* tmp=spisok->end;
	while(tmp->prev!=NULL)
	{
		printf("%d ", tmp->value);
		tmp=tmp->prev;
	}
	printf("%d\n", tmp->value);	
}

