#include<bits/stdc++.h>
using namespace std;
int m,n,a;
char temp;
int f[1055][1055];
int l[1055],r[1055];
int tem2[1055][1055];
int main(){
	scanf("%d %d",&m,&n);
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin >> temp;
			a = temp-'0';
			if(a)
			f[i][j]=f[i][j-1]+1;
			else
			f[i][j]=0;
		}
	}
	int ans = 0;
	
	for(int i=1;i<=n;i++)
	{
		stack<int>s,st;
		l[1]=1,r[m]=m;
		for(int j=1;j<=m;j++)
		{
			if(s.empty())
			{
				s.push(j);
			}
			else
			{
				if(f[s.top()][i]>=f[j][i])
				{
				while(!s.empty()&&f[s.top()][i]>=f[j][i])
				{
					s.pop();
				}
				if(s.empty())
				{
					l[j]=1;
				}
				else
				{
					l[j]=s.top()+1;
				}
				s.push(j);
				}
				else
				{
					l[j]=j;
					s.push(j);
				}
			}
		}
		for(int j=m;j>=1;j--)
		{
			if(st.empty())
			{
				st.push(j);
			}
			else
			{
				if(f[st.top()][i]>=f[j][i])
				{
				
				while(!st.empty()&&f[st.top()][i]>=f[j][i])
				{
					st.pop();
				}
				if(st.empty())
				{
					r[j]=m;
				}
				else
				{
					r[j]=st.top()-1;
				}
				st.push(j);
		    	}
		    	else
		    	{
		    		r[j]=j;
		    		st.push(j);
				}
			}
		}
		for(int j=1;j<=m;j++)
		{
			tem2[i][j] = (r[j]-l[j]+1)*f[j][i];
		}
	}
	int posx = 0, posy = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <=m; j++){
			printf("%d ", tem2[i][j]);
			if(ans < tem2[i][j]){
				ans = tem2[i][j];
				posx = i;
				posy = j;
			}
		}
		printf("\n");
	}
	int pos = posy;
	while(pos >=1 && pos <= m){
		if(tem2[posx][pos] == ans){
			tem2[posx][pos] = 0;
			pos++;
		}
		else
			break;
	}
	pos = posy-1;
	while(pos >=1 && pos <= m){
		if(tem2[posx][pos] == ans){
			tem2[posx][pos] = 0;
			pos--;
		}
		else
			break;
	}
	ans = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			ans = max(ans, tem2[i][j]);
		}
	}
	printf("%d",ans);
	return 0;
}