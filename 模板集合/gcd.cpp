/*最经典的GCD算法，求a,b的最大公约数*/
int GCD(int a,int b){
return b==0?a:GCD(b,a%b);
}