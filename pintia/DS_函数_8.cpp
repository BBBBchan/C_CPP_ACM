int search(int n){
	int count = 0;
	for(int i = 11; i*i < n; i++){
		int temp = i*i,a,b,c;
		a = temp % 10;
		b = (temp/10)%10;
		c = temp/100;
		if(a==b || b==c || a==c)
			count++;
	}
	return count;
}