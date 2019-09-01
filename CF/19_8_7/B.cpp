#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int a[10][10][10] = {0};
	for(int i = 0; i <= 9; i++){
		for(int j = 0; j <= 9; j++){
			for(int k = 0; k < 10; k++){
				int min = 1000000;
				for(int ii = 0; ii <=10; ii++){
					for(int jj = 0; jj <= 10; jj++){
						if(ii == 0 && jj == 0)
							continue;
						if((i*ii+j*jj)%10 == k){
							if(ii+jj<min)
								min = ii+jj;
						}
					}
				}
				if(min == 1000000)
					a[i][j][k] = -1;
				else if(min > 0){
					a[i][j][k] = min-1;
				}
			}
		}
	}
	//cout << a[2][2][0]<<endl;
	// for(int i = 0; i < 9; i++){
	// 	for(int j = 0; j < 9; j++){
	// 		for(int k = 0; k < 9; k++){
	// 			printf("%d ",a[i][j][k] );
	// 		}
	// 		printf("\n");
	// 	}
	// }
	string t;
	cin >> t;
	int ans[10][10] = {0};
	for(int i = 0; i <= 9; i++){
		for(int j = 0; j <= 9; j++){
			for(int k = 1; k < t.size(); k++){
				int temp = t[k] -t[k-1];
				if(temp < 0)
					temp = 10 + temp;
			//	cout << temp <<endl;
				if(a[i][j][temp] == -1){
					ans[i][j] = -1;
					break;
				}
				else{
					ans[i][j] += a[i][j][temp];
				}
			}
			//cout << ans[i][j] << " ";
		}
		//cout << endl;
	}
	for(int i = 0; i <= 9; i++){
		for(int j = 0; j <= 9; j++){
			printf("%d ", ans[i][j]);
		}
		printf("\n");
	}
	return 0;
}