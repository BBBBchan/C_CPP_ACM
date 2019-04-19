/*最经典的GCD算法，求a,b的最大公约数，使用方法：GCD(a,b)*/
int GCD(int a,int b){
return b==0?a:GCD(b,a%b);
}