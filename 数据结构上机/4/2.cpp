#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxn 8
typedef struct 
{
	char data;
	float weight;
	int parent, lchild, rchild;
}HTNode, *Huffmantree;
struct HuffmanCode{
	char code[maxn];
}HC[maxn+1];
struct {
	float data;
	int num;
}min1, min2;
struct node{
	char data;
	float weight;	
}w[maxn];
int m = 2*maxn - 1;
void HuffmanCoding(Huffmantree &HT, HuffmanCode *HC, node *w){
	HT = (Huffmantree)malloc((m+1)*sizeof(HTNode));
	for(int i = 1; i <= maxn; i++){		//初始化前n个值
		HT[i].data = w[i-1].data;
		HT[i].weight = w[i-1].weight;
		HT[i].parent = 0;
		HT[i].lchild = 0;
		HT[i].rchild = 0;
	}
	for(int i = maxn+1; i <= m; i++){		//初始化合并处的值
		HT[i].parent = 0;
		HT[i].lchild = 0;
		HT[i].rchild = 0;
	}
	for(int i = maxn+1; i <= m; i++){
		min1.data = 1e9;
		min2.data = 1e9;
		for(int j = 1; j< i; j++){
			if(HT[j].weight < min1.data && HT[j].parent == 0){
				min2 = min1;
				min1.data = HT[j].weight;
				min1.num = j;
			}
			else if(HT[j].weight < min2.data && HT[j].parent == 0){
				min2.data = HT[j].weight;
				min2.num = j;
			}
		}
		HT[min1.num].parent = i;
		HT[min2.num].parent = i;
		HT[i].lchild = min1.num;
		HT[i].rchild = min2.num;
		HT[i].weight = min1.data+min2.data;
	}
	for(int i = 1; i <= maxn; i++){
		printf("%c %f %d %d %d\n", HT[i].data, HT[i].weight, HT[i].parent, HT[i].lchild, HT[i].rchild);
	}
	for(int i = maxn+1; i <= m; i++){
		printf("  %f %d %d %d\n", HT[i].weight, HT[i].parent, HT[i].lchild, HT[i].rchild);
	}
	for(int i = 1; i <= maxn; i++){
		int start = maxn-1,count = 0;
		char cd[maxn];
		cd[maxn-1] = '\0';
		int c = i;
		for(int f = HT[i].parent; f!=0; f=HT[f].parent){
			if(HT[f].lchild == c){
				start--;
				cd[start] = '0';
				count++;
			}
			else{
				start--;
				cd[start] = '1';
				count++;
			}
			c = f;
		}
		HC[i].code[count] = '\0';
		for(int j = 0; j < count; j++){
			HC[i].code[count-1-j] = cd[maxn-2-j];
		}
	}
}
void encode(HuffmanCode *HC, char *a){
	int len = strlen(a);
	for(int i = 0; i < len; i++){
		int temp = a[i]+1-'a';
		printf("%s", HC[temp].code);
	}
	printf("\n");
}
void decode(Huffmantree HT, int m, char *b){
	int p = m;
	while(*b != '\0' && p!=0){
		if((*b) == '0')
			p = HT[p].lchild;
		else
			p = HT[p].rchild;
		b++;
		if(!HT[p].lchild && !HT[p].rchild){
			printf("%c", HT[p].data);
			p = m;
		}
	}
}
int main(int argc, char const *argv[])
{
	Huffmantree HT;	
	for(int i = 0; i < maxn; i++){
		w[i].data = i+'a';
		scanf("%f", &w[i].weight);
	}
	char a[10],b[40];
	scanf("%s", a);
	scanf("%s", b);
	HuffmanCoding(HT,HC,w);
	encode(HC, a);
	decode(HT,m,b);
	return 0;
}

//0.05 0.29 0.07 0.08  0.14  0.23 0.03 0.11