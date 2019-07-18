#include <iostream>
using namespace std;
class arr
{
	int *pa;
	int sz;
public:
	arr(int size): sz(size){
		pa = new int[sz];
		for(int i = 0; i < sz; i++){
			pa[i] = i;
		}
	}
	arr(arr &t){
		sz = t.sz;
		pa = new int[sz];
		for(int i = 0; i < sz; i++)
			pa[i] = i+5;
	}
	int* operator[](const int i){return &pa[i];}
	const arr& operator++(int i){
		for(int i = 0; i < sz; i++)
			pa[i] ++;
		return *this;
	}
	~arr(){};
	
};
int main(){
	arr ia(3), ib(ia);
	cout <<"here"<<endl;
	for(int i = 0; i < 3; i++){
		*(ia[i]) = i+5;
	}
	ib++;
	for(int j = 0; j < 3; j++)
		cout << *(ia[j]) << " ";
	cout <<endl;
	for(int j = 0; j < 3; j++)
		cout << *(ib[j]) << " ";
	cout <<endl;
	// int a[2];
	// int x = 1, y = 1;
	// cin >> a[0];
	// cout << x<< y <<endl;
	return 0;
}