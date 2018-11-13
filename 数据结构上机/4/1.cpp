#include <cstdio>
#include <cstdlib>
typedef struct BiTNode{
	char data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;
void createBiTree(BiTree &T){
	char ch;
	scanf("%c", &ch);
	if(ch == '.')
		T = NULL;
	else{
		T = (BiTree)malloc(sizeof(BiTNode));
		T->data = ch;
		createBiTree(T->lchild);
		createBiTree(T->rchild);
	}
}
void Pre(BiTree &T){
	if(T != NULL){
		printf("%c ", T->data);
		Pre(T->lchild);
		Pre(T->rchild);
	}
}

void inorder(BiTree &T){
	if(T!=NULL){
		inorder(T->lchild);
		printf("%c ", T->data);
		inorder(T->rchild);
	}
}
void postorder(BiTree &T){
	if(T!=NULL){
		postorder(T->lchild);
		postorder(T->rchild);
		printf("%c ", T->data);
	}
}
int main(int argc, char const *argv[])
{
	BiTree T;
	createBiTree(T);
	Pre(T);
	printf("\n");
	inorder(T);
	printf("\n");
	postorder(T);
	printf("\n");
	return 0;
}