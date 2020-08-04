#include <cstdio>
#include <string>
#include <map>
#include <iostream>
using namespace std;
struct kuohao
{
	int left_pos;
	int right_pos;
	int count;
};
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	while(n--){
		string init;
		cin >> init;
		cout << init <<endl;
		string left[1000], right[1000];
		left[0] = "";
		right[0] = "";
		int left_string_count = 0, right_string_count = 0, status=0;
		for(int i = 0; i < init.size(); i++){
			if(init[i] == '+'){
				if(status == 0){
					left_string_count++;
					left[left_string_count]="";
				}
				else{
					right_string_count++;
					right[right_string_count] = "";
				}
				continue;
			}
			if(init[i] == '='){
				status = 1;
				continue;
			}
			if(status == 0){
				left[left_string_count] += init[i];
				cout<<left[left_string_count] <<endl;
			}
			else{
				right[right_string_count] += init[i];
				cout<<right[right_string_count] <<endl;
			}
			// cout<<"hereeee"<<endl;
		}
		// for(int j = 0; j <= left_string_count; j++){
		// 	for(k = 0; k <= left[j].size(); k++){
		// 		if(left[j][k] == '('){
					
		// 		}
		// 	}
		// }
		cout <<endl;
		for(int j = 0; j <= right_string_count; j++){
			cout << right[j] << " ";
		}
	}
	return 0;
}
/**
10
H2+O2=H2O
**/