#include <cstdio>
#include <cstdlib>
typedef struct BiTNode{
	int data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;
bool searchBST(BiTree T, int key, BiTree f,BiTree *p){
	if(!T){
		*p = f;
		return 0;
	}
	else if(key == T->data){
		*p = T;
		return 1;
	}
	else if(key < T->data)
		return searchBST(T->lchild,key,T,p);
	else
		return searchBST(T->rchild,key,T,p);
}
void InsertBST(BiTree *T, int key){
	BiTree p,s;
	if(!searchBST(*T,key,NULL,&p)){
		s = (BiTree)malloc(sizeof(BiTNode));
		s->data = key;
		s->lchild=s->rchild = NULL;
		if(!p)
			*T = s;
		else if(key<p->data)
			p->lchild = s;
		else
			p->rchild = s;
	}
}
bool Delete(BiTree &P){
	BiTree q,s;
	if(!P->rchild){
		q = P ;
		P = P->lchild;
		free(q);
		return 1;
	}
	else if(!P->lchild){
		q = P;
		P = P->rchild;
		free(q);
		return 1;
	}
	else{
		q = P;
		s = P->lchild;
		while(s->rchild){
			q = s;
			s = s->rchild;
		}
		P->data = s->data;
		if(q != P)
			q->rchild = s->lchild;
		else
			q->lchild = s->lchild;
		free(s);
		return 1;
	}
	return 0;
}
bool DeleteBST(BiTree &T, int key){
	if(!T)
		return 0;
	else{
		if(key == T->data){
			return Delete(T);
		}
		else if(key < T->data){
			return DeleteBST(T->lchild,key);
		}
		else if(key > T->data){
			return DeleteBST(T->rchild,key);
		}
	}
	return 0;
}
void inorder(BiTree T){
	if(T!=NULL){
		inorder(T->lchild);
		printf("%d ", T->data);
		inorder(T->rchild);
	}
}
int main(int argc, char const *argv[])
{
	BiTree T=NULL,P;
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		int temp;
		scanf("%d", &temp);
		InsertBST(&T,temp);
	}
	inorder(T);
	printf("\n");
	int temp;
	scanf("%d", &temp);
	searchBST(T,temp,NULL,&P);
	if(P)
		DeleteBST(T,temp);
	searchBST(T,temp,NULL,&P);
	inorder(T);
	return 0;
}