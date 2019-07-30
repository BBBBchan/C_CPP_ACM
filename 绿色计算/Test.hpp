#ifndef _TEST
#define _TEST
#include <iostream>
#include <vector>


using namespace std;  
class Task{

	public:
    void dfs(int n, int m, int x, int y, vector<vector<char> >& arr){
    arr[x][y] = 'x';
    if(x-1>=0 && arr[x-1][y] == 'o'){
        dfs(n,m,x-1,y,arr);
    }
    if(x+1 < n && arr[x+1][y] == 'o'){
        dfs(n,m,x+1,y,arr);
    }
    if(y-1>=0 && arr[x][y-1] == 'o'){
        dfs(n,m,x, y-1,arr);
    }
    if(y+1<m && arr[x][y-1] == 'o'){
        dfs(n,m,x,y+1,arr);
    }
}
		int virusArea(int n,int m,vector<vector<char> >& arr){
			/********* Begin *********/
            int num = 0;
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    if(arr[i][j] == 'o'){
                        dfs(n,m,i,j,arr);
                        num++;
                    }
                    for (int i = 0; i < n; ++i)
                    {
                    	for(int j = 0; j < m; j++){
                    		cout << arr[i][j];
                    	}
                    	cout << endl;
                    }
                }
            }
            return num;			/********* End *********/
		}
};
#endif