#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
string a, b;
int main(int argc, char const *argv[])
{
	int t;
	scanf("%d", &t);
	for(int times = 1; times <= t; times++){
		cin >> a;
		cin >> b;
//		cout << b<<endl;
		int temp[26] = {0};
		for(int i = 0; i < a.size(); i++){
//			cout << a[i]-'a'<<endl;
			temp[b[a[i]-'a']-'a']++;
		}
		if(temp['h'-'a'] >= 0.25*a.size()){
			cout << "Case #"<< times <<": Harmful" << endl;
		}
		else if(temp['h'-'a'] <= 0.1*a.size()){
			cout << "Case #"<< times <<": Recyclable" << endl;
		}
		else if(temp['d'-'a'] >= 2*temp['w'-'a']){
			cout << "Case #"<< times <<": Dry" << endl;
		}
		else{
			cout << "Case #"<< times <<": Wet" << endl;
		}
	}
	return 0;
}