#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

vector< vector< int>>  periods(2);
int time[1000005];
vector< vector<int>> final(1000005);
class Solution{
	public:
		vector<vector<int>> mergeWorkPeriods(vector<vector<int>>&periods){			
			int start, end;
			for(int i = 0; i < periods.size(); i++){
				start = periods[i][0];
				end = periods[i][1];
				for(int j = start; j < end; j++){
					time[j] = 1;
				}
			}
			vector< vector<int>> ans(1000005);
			int count = 0;
			for(int i = 0; i < 1000005; i++){
				if(time[i] == 1){
					int ans_start = i;
					int ans_end = i;
					ans[count].push_back(ans_start);
					while(time[i] == 1){
						i++;
					}
					ans_end = i;
					ans[count].push_back(ans_end);
					count++;
					i--;
				}
			}
			return ans;
		}

};
int main(int argc, char const *argv[])
{
	int n = 2;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 2; j++){
			int a;
			scanf("%d", &a);
			// printf("%d\n", a);
			periods[i].push_back(a);
		}
	}
	Solution temp;
	final = temp.mergeWorkPeriods(periods);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 2; j++){
			cout << final[i][j];
		}
		cout <<endl;
	}
	return 0;
}
/*
1 4
3 5
7 9
14 16
*/