void StringCount(char *s){
	int a[5] = {0};
	int i = 0;
	while(s[i] != '\0'){
		if(s[i] >= 'A' && s[i] <= 'Z')
			a[0]++;
		else if(s[i] >= 'a' && s[i] <= 'z')
			a[1]++;
		else if(s[i] == ' ')
			a[2]++;
		else if(s[i] >= '0' && s[i] <= '9')
			a[3]++;
		else
			a[4]++;
		i++;
	}
	for(int k = 0; k < 4; k++)
		printf("%d ", a[k]);
	printf("%d", a[4]);
}