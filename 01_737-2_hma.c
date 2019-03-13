#include <stdio.h>
#include<stdlib.h>

struct point {
	int value;
	struct point *next;
} point;

struct list1{		
	struct point* begin;	
} list1;


int isEmpty(struct list1* spisok);
struct point* find(struct list1* spisok,int value);
void init(struct list1* spisok,int value);
int push_back(struct list1* spisok, int x);
int push_front(struct list1* spisok,int x);
int clear(struct list1* spisok);
void _remove(struct list1* spisok, struct point *tmp);
int removeFirst(struct list1* spisok, int x);
int insertAfter	(struct list1* spisok,int num, int value);
void print(struct list1* spisok);

int main()
{
	int n,a;
	struct list1* spisok=(struct list1*)malloc(sizeof(struct list1));	
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
	print(spisok);

	int t;
	scanf("%d",&t);
	push_front(spisok,t);
	print(spisok);

	int j,x;
	scanf("%d%d",&j,&x);
	insertAfter(spisok,j,x);
	print(spisok);

	int z;
	scanf("%d",&z);
	removeFirst(spisok,z);
	print(spisok);
	
	int r;
	scanf("%d",&r);
	removeLast(spisok);
	print(spisok);

	clear(spisok);
	return 0;
}

int isEmpty(struct list1* spisok)
{
	return spisok->begin==NULL;
}

void print(struct list1* spisok)
{
	struct point* tmp=spisok->begin;
	while(tmp->next!=NULL)
	{
		printf("%d ", tmp->value);
		tmp=tmp->next;
	}
	printf("%d\n", tmp->value);
}

int insertAfter	(struct list1* spisok,int num, int value)
{
	struct point *temp = malloc(sizeof(point));
	temp->value=value;

	struct point* tmp = spisok->begin;
	struct point* prev_tmp = spisok->begin;
	
	for (int i = 1;i<num+1;i++)
	{
		prev_tmp=tmp;
		tmp=tmp->next;
		if(tmp==NULL) 
			return -1;
	}
	prev_tmp->next=temp;
	temp->next=tmp;
	return 0;   
}

int removeFirst(struct list1* spisok, int x)
{
	struct point* element = find(spisok,x);
	if (element!=NULL){
		_remove(spisok,element);
		return 0;
	}
	return -1;
}

void _remove(struct list1* spisok, struct point* tmp)
{
	if(tmp!=NULL){
		if (tmp==spisok->begin)
			spisok->begin=tmp->next;
		else
		{
			struct point *temp = (struct point*)malloc(sizeof(struct point));
			temp=spisok->begin;
			while(temp->next!=tmp)
				temp=temp->next;
			temp->next = tmp->next;
		}
		free(tmp);
	}
}

int clear(struct list1* spisok)
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
	}
}

int push_front(struct list1* spisok,int x) 
{
	if(isEmpty(spisok)==1)
		init (spisok,x);
	else
	{
		struct point *tmp = (struct point*)malloc(sizeof(struct point));
		tmp->value=x;
		tmp->next=spisok->begin;
		spisok->begin=tmp;
	}
	return 0;
}

int push_back(struct list1* spisok, int x)
{
	if(isEmpty(spisok)==1)
		init (spisok,x);
	else
	{
		struct point* tmp = (struct point*)malloc(sizeof(struct point));
		tmp->value=x;
		tmp->next=NULL;
		struct point* temp = spisok->begin;
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=tmp;
	}
	return 0;
}

struct point* find(struct list1* spisok,int value)
{
	struct point *tmp=spisok->begin;
	while(tmp->value!=value){
		if(tmp->next!=NULL)
			tmp=tmp->next;
		else
			return 0;
	}
	return tmp;
}

void init(struct list1* spisok,int value)
{
	struct point* tmp;
	tmp = (struct point*)malloc(sizeof(struct point));
	tmp->value=value;
	tmp->next=NULL;
	spisok->begin = tmp;
}
