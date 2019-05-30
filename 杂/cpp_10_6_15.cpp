#include <iostream>
#include <stdio.h>
using namespace std;
ostream &operator <<(ostream &os, const char* s)
{
	printf("Initialize\n");
	printf("%s",s);
	printf("Clean up");
	return os;
}
int main()
{
	std::cout << "Hello world!\n";
}