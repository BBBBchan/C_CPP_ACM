#include <cstdio>
#include <cstring>
#define maxnsize 97
struct info{
	int kase;
	char phone[12];
	char name[25];
	char adress[55];
};
typedef struct{
    info data[maxnsize];    
    int count;
    int size;       
}HashTable;
void init(HashTable &H){
	H.size = maxnsize;
	H.count = 0;
	for(int i = 0; i < H.size; i++){
		H.data[i].kase = 0;
	}
}
int hash(info K){
	int i = 0, p=0;
	while(K.name[i]!='\0'){
		p = K.name[i] + p*33;
		i++;
	}
	p%=maxnsize;
	return p;
}
int SearchHash(HashTable H, info K){
	int p = hash(K);
	if(H.data[p].kase && p<H.size){
		if(!strcmp(H.data[p].phone,K.phone) && !strcmp(H.data[p].name,K.name) && !strcmp(H.data[p].adress,K.adress)){
			return 1;
		}
		else{
			p++;
		}
	}
	return 0;
}
void InsertHash(HashTable *H, info K){
	if(H->count >= H->size)
		return;
	if(SearchHash(*H,K))
		return;
	else{
		int p = hash(K);
		if(H->data[p].kase == 0){
			H->data[p] = K;
			H->data[p].kase = 1;
			return;
		}
		while(H->data[p].kase == 1 && p < H->size)
			p++;
		if(p >= H->size)
			return;
		H->data[p] = K;
		H->data[p].kase = 1;
		H->count++;
	}
}
int main(int argc, char const *argv[]){
	HashTable H;
	init(H);
	int n;
	info temp;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%s %s %s", temp.phone, temp.name, temp.adress);
		InsertHash(&H,temp);
	}
	if(SearchHash(H,temp))
		printf("yes\n");
	else
		printf("No\n");
	return 0;
}