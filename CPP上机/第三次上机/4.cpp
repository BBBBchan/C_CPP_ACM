#include <iostream>
#include <string>
#include <stdarg.h>
using namespace std;
void error(string type, ...) {
    va_list valist;
    va_start(valist, type);
    for(int i = 0; i <type.size(); i++){
    	if(type[i] == '%' && i < type.size()-1){
    		if(type[i+1] == 'd'){
    			cout << va_arg(valist,int) <<endl;
    			i++;
    		}
    		else if(type[i+1] == 'f'){
    			cout << va_arg(valist,double)<<endl;
    			i++;
    		}
    		else if(type[i+1] == 's'){
    			cout << va_arg(valist,char const*)<<endl;
    			i++;
    		}
    		else if(type[i+1] == 'c'){
    			cout << char(va_arg(valist, int))<<endl;
    			i++;
    		}
    	}
    }
    va_end(valist);
}

int main(int argc, char const *argv[])
{
	error("%d %s %f %c",1,"test",2.34,'a');
	return 0;
}