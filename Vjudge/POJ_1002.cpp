#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char s[100];
int letter[] = {2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,0,7,7,8,8,8,9,9,9};

int phone[100005] = {0};


int main(int argc, char const *argv[])
{
	int t;
	scanf("%d\n", &t);
	for(int k = 0; k < t; k++){
		gets(s);
		int l1 = strlen(s);
		for (int i = 0; i < l1; ++i)
		{	
			if(s[i] == '-' || s[i] == 'Q' || s[i] == 'Z'){
				continue;
			}
			else if(s[i] >= '0' && s[i] <= '9'){
				phone[k] = phone[k]*10 + s[i] - '0';
			}
			else{
				phone[k] = phone[k]*10 + letter[s[i]-'A'];
			}
		}
	}
	sort(phone,phone+t);
	int count = 1,kase = 0,i;
	for(i = 1; i <t; i++){
		if(phone[i] == phone[i-1])
			count++;
		else{
			if(count > 1){
				printf("%03d-%04d %d\n", phone[i-1]/10000, phone[i-1]%10000, count);
				kase = 1;
			}
			count = 1;
		}
		}
		if(count > 1){
			printf("%03d-%04d %d\n", phone[i-1]/10000, phone[i-1]%10000, count);
			kase = 1;
		}

	if(!kase)
		printf("No duplicates.\n");
	return 0;
		
}