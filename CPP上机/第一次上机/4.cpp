#include <iostream>
#include <string>
using namespace std;
template <typename T>
void print(const T &t)
{
	cout <<"Hello "<< t << "!" << endl;
}
template <typename T, typename...Args>
void print(const T &t, const Args&...rest)
{
	cout <<"Hello "<< t << "!" << endl;
	print(rest...);
}
int main()
{
	print("str1", 100, 3.14f, "BBChan", 42);
	return 0;
}