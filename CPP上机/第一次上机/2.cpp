#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
	int count = 0, kase;
	string Quit_str = "quit", str1;
	string strings[100];
	while((cin >> str1) && str1 != Quit_str){
		kase = 1;
		for(int i = 0; i < count; i++){
			if(strings[i] == str1){
				kase = 0;
				break;
			}

		}
		if(kase){
			strings[count] = str1;
			count++;
		}

	}
	sort(strings, strings+count);
	for(int i = 0; i < count; i++)
		cout << strings[i] << endl;
	return 0;
}