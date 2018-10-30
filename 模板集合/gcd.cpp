int GCD(int a,int b){
return b==0?a:GCD(b,a%b);
}