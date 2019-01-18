int f[100005] = {0};
int find(int x)//并查集
{
    if (f[x]==x) 
        return x; 
    else{
        f[x]=find(f[x]);
        return f[x];
    }
}
int main(int argc, char const *argv[])
{	
	int n;
	scanf("%d", &n);
	for(int i  = 0; i < n; i++)		//初始化
		f[i] = i;
	
	int a = find(x);
	int b = find(y);
	if(a != b)
		f[a] = b;		//加入并查集
	if(a == b)
		continue;		//同一集合

	//求连通分量
	int u[100005] = {0};
	int count = 0;
	for(int i = 1; i <= n; i++){
		int u = find(i);
		if(b[u] == 0){
			count++;
			b[u] = 1;
		}
	}
	return 0;
}