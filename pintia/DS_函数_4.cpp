int reverse(int num){
	int kase = 1;
	if(num < 0){
		num *= -1;
		kase = 0;
	}
	int temp, ans = 0;
	while(num != 0){
		temp = num%10;
		num/=10;
		ans = ans*10 + temp;
	}
	if(kase)
		return ans;
	else
		return -ans;
}