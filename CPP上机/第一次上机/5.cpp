#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;
typedef struct BiTNode{
	string word;
	//char* word2 = new char[100];
	int count;
	struct BiTNode *left, *right;
}BiTNode, *BiTree;
bool searchBST(BiTree T, string key, BiTree f,BiTree *p){
	if(!T){
		*p = f;
		return 0;
	}
	else if(key == T->word){
		*p = T;
		return 1;
	}
	else if(key < T->word){
		return searchBST(T->left,key,T,p);
	}
	else{
		return searchBST(T->right,key,T,p);
	}
}
void InsertBST(BiTree *T, string key){
	BiTree p,s;
	if(!searchBST(*T,key,NULL,&p)){
		s = (BiTree)malloc(sizeof(BiTNode));
		s->word = key;
		s->left=s->right = NULL;
		if(!p)
			*T = s;
		else if(key<p->word)
			p->left = s;
		else
			p->right = s;
	}
}

void inorder(BiTree T){
	if(T!=NULL){
		inorder(T->left);
		cout << T->word<<endl;
		inorder(T->right);
	}
}
int main(int argc, char const *argv[])
{
	BiTree T=NULL,P;
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		string temp;
		cin >> temp;
		InsertBST(&T,temp);
	}
	inorder(T);
	return 0;
}