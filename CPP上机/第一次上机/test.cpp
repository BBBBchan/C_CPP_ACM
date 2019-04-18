#include <iostream>  
#include <string>  
#include <stdlib.h>  
      
using namespace std;  
      
struct flowRecord            
{  
    string app_name;                                                              
    struct flowRecord *next;  
      
};  
      
int main() {  
    flowRecord *fr = (flowRecord*)malloc(sizeof(flowRecord));  
    fr->app_name = "hello";  
    cout << fr->app_name << endl;  
    return 0;  
}