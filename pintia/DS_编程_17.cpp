#include <cstdio>
#include <stack>
using namespace std;
struct book{
	int num;
	char key;
	double time;
};
stack < book> st;
stack < book> st2;
int inshell[1005]= {0};
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	for(int j = 0; j < n; j++){
		book temp;
		int a, b;
		int count = 0;
		double all = 0;
		while(scanf("%d %c %d:%d", &temp.num, &temp.key, &a, &b) != EOF){
			temp.time = a*60.0+b;
			if(temp.num == 0){
				if(count != 0){
					double t = all/count;
					int ans = t + 0.5f;
					printf("%d %d\n", count, ans);
				}
				else
					printf("0 0\n");
				while(st.size())
					st.pop();
				while(st2.size())
					st2.pop();
				for(int i = 0; i < 1005; i++)
					inshell[i] = 0;
				break;
			}
			if(temp.key == 'E'){
				while(st.size()){
					book temp2;
					temp2 = st.top();
					st.pop();
					if(temp2.num != temp.num)
						st2.push(temp2);
					else{
						all += (temp.time - temp2.time);
						inshell[temp.num] = 0;
						count++;
					}
				}
				while(st2.size()){
					book temp2;
					temp2 = st2.top();
					st2.pop();
					st.push(temp2);
				}
			}
			else if(temp.key == 'S'){
				while(st.size()){
					book temp2;
					temp2 = st.top();
					st.pop();
					if(temp.num != temp2.num)
						st2.push(temp2);
				}
				while(st2.size()){
					book temp2;
					temp2 = st2.top();
					st2.pop();
					st.push(temp2);
				}
				inshell[temp.num] = 1;
				st.push(temp);
			}
		}
	}
	return 0;
}