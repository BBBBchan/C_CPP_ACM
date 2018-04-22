#include "iostream"
#include "algorithm"
#include "vector"
#include "set"
#include "string.h"
#include "ctype.h"
using namespace std;

typedef int State[9];
#define max 1000000
State st[max];
int dist[max];
int front, rear;
set<int> vis;
State goal = {0,1,2,3,4,5,6,7,8};

void init_table()
{
    vis.clear();
}

int insert_table(int s)
{
    int v = 0;
    for(int i=0; i<9; i++)
        v = v*10 + st[s][i];
    if(vis.count(v))
        return 0;
    else
    {
        vis.insert(v);
        return 1;
    }
}

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int bfs()
{
    front = 1;
    rear = 2;
    init_table();
    while(front < rear)
    {
        State &s = st[front];
        if(memcmp(s, goal, sizeof(goal)) == 0)
            return front;
        int z;
        for(z=0; z<9; z++) 
            if(!s[z])
                break;
        int x = z/3;
        int y = z%3;
        for(int i=0; i<4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >=0 && ny>=0 && nx<3 && ny<3)
            {
                State &t = st[rear];
                memcpy(t, s, sizeof(s));
                int newz = 3*nx + ny;
                t[z] = s[newz];
                t[newz] = s[z];
                if(insert_table(rear))
                {
                    dist[rear] = dist[front] + 1;
                    rear++;
                }
            }
        }
        front++;
    }
    return -1;
}

int main()
{	int t;
	scanf("%d", &t);
	while(t--){	
    	memset(dist, 0, sizeof(dist));
    	for(int i=0; i< 9; i++)
    	    scanf("%d", &st[1][i]);
    	
		int ans = bfs();
    	if(ans > 0)
       		printf("%d\n", dist[ans]); 
   		else
        	printf("cannot\n");;
	}
	return 0;
}