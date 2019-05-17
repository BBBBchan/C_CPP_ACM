#include <string>
#include <iostream>
using namespace std;
class Historgram
{
private:
	int a[10];
public:
	Historgram();
	void add_historgram(int value);
	void print(){
		for(int i = 0; i < 10; i++)
			printf("%d ", a[i]);
	}
};

Historgram::Historgram(){
	for(int i = 0; i < 10; i++)
		a[i] = 0;
}

void Historgram::add_historgram(int value){
	a[value-1]++;
}
int main()
{
	Historgram h;
	int temp;
	while(cin >> temp){
		if(temp >= 1 && temp <= 10){
			h.add_historgram(temp);
			printf("Successfully added\n");
		}
		else
			printf("invalid data\n");
	}
	h.print();
}