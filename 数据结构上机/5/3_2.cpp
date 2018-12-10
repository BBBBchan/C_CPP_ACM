#include <cstdio>
#include <cstring>
#define maxnsize 97
struct info{
	char phone[12];
	char name[25];
	char adress[55];
	info *next;
};
typedef struct{
    info data[maxnsize]; 
    int kase[maxnsize];   
    int count;
    int size;       
}HashTable;
void init(HashTable &H){
	H.size = maxnsize;
	H.count = 0;
	for(int i = 0; i < H.size; i++){
		H.kase[i] = 0;
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
	int p = hash(K),temp = 0;
	info q = H.data[p];
	if(H.kase[p] && p<H.size){
		while(temp < H.kase[p]&&(!strcmp(H.data[p].phone,K.phone) && !strcmp(H.data[p].name,K.name) && !strcmp(H.data[p].adress,K.adress))){
			q = *q.next;
			temp ++;
		}
		if(temp < H.kase[p])
			return 1;
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
		if(H->kase[p] == 0){
			H->data[p] = K;
			H->kase[p] += 1;
			H->data[p].next = NULL;
			return;
		}
		int temp = 0;
		info q = H->data[p];
		while(temp < H->kase[p]-1 && p < H->size){
			q = *q.next;
			temp++;
		}
		if(p >= H->size)
			return;
		K.next = NULL;
		*q.next = K;
		H->kase[p] += 1;
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
		temp.next = NULL;
		InsertHash(&H,temp);
	}
	if(SearchHash(H,temp))
		printf("yes\n");
	else
		printf("No\n");
	return 0;
}