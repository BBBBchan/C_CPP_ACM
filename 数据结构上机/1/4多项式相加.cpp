#include <stdio.h>
#include <stdlib.h>
typedef struct LNode{
	float num;
	int expn;
	struct LNode *next;
}LNode, *LinkList;
void Create_L(LinkList &La, LinkList &Lb, int a, int b){
	LinkList rear_a, rear_b;
	La = (LinkList)malloc(sizeof(LNode));
	Lb = (LinkList)malloc(sizeof(LNode));
	La->next = NULL;
	Lb->next = NULL;
	rear_a = La;
	rear_b = Lb;
	for(int i = 0; i < a; i++){
		LinkList p = (LinkList)malloc(sizeof(LNode));
		scanf("%f %d", &p->num, &p->expn);
		p->next = NULL;
		rear_a->next = p;
		rear_a = p;
	}
	for(int j = 0; j < b; j++){
		LinkList p = (LinkList)malloc(sizeof(LNode));
		scanf("%f %d", &p->num, &p->expn);
		p->next = NULL;
		rear_b->next = p;
		rear_b = p; 
	}
}
void print_LinkList(LinkList L){
	LinkList p = L->next;
	if(!p)
		printf("empty!!!\n");
	do{
		if(p->num == 0){
			p = p->next;
			continue;
		}
		printf("%.1f %d  ", p->num, p->expn);
		p = p->next;
	}while(p!=NULL);
	printf("\n");
}

LinkList Add(LinkList La, LinkList Lb){
	LinkList Lc = (LinkList)malloc(sizeof(LNode));
	Lc->next = NULL;
	LinkList temp_a = La->next;
	LinkList temp_b = Lb->next;
	if(!temp_a && !temp_b){
		printf("error!\n");
		return NULL;
	}
	while(temp_a || temp_b){
		LinkList p = (LinkList)malloc(sizeof(LNode));
		if(temp_a && temp_b && temp_a->expn == temp_b->expn){
			p->num = temp_a->num + temp_b->num;
			p->expn = temp_a->expn;
			temp_a = temp_a->next;
			temp_b = temp_b->next;
		}
		else if(temp_a && temp_b && temp_a->expn < temp_b->expn){
			p->num = temp_a->num;
			p->expn = temp_a->expn;
			temp_a = temp_a->next;
		}
		else if(temp_a && temp_b && temp_a->expn > temp_b->expn){
			p->num = temp_b->num;
			p->expn = temp_b->expn;
			temp_b = temp_b->next;
		}
		else if(!temp_a){
			p->num = temp_b->num;
			p->expn = temp_b->expn;
			temp_b = temp_b->next;
		}
		else if(!temp_b){
			p->num = temp_a->num;
			p->expn = temp_a->expn;
			temp_a = temp_a->next;
		}
		p->next = Lc->next;
		Lc->next = p;
	}
	return Lc;
}
int main(int argc, char const *argv[])
{
	int a, b;
	scanf("%d %d", &a, &b);
	LinkList La, Lb;
	Create_L(La, Lb, a, b);
	// print_LinkList(La);
	// print_LinkList(Lb);
	LinkList Lc = Add(La, Lb);
	print_LinkList(Lc);
	return 0;
}