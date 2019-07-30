#include <iostream>
#include <vector>
#include <stdio.h>
#include "Test.hpp"

using namespace std;

int main(){
	int i = 0;
	char c;
	vector<int> vec;
	while((c=cin.get())!='\n'){
		cin.unget();
		cin >> i;
		vec.push_back(i);
	}
	int n = vec[0];
	int m = vec[1];
	char area[n][m];
	vector<vector<char> > arr(n,vector<char>(m));

	for(i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			cin >> area[i][j]; 
			arr[i][j] = area[i][j];
		}
	}

	Task tt;

	cout << tt.virusArea(n,m,arr) << endl;

}
