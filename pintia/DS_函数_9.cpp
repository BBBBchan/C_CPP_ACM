int max_len(char *s[], int n){
	int max = 0;
	for(int i = 0; i < n; i++){
		if(strlen(s[i]) > max)
			max = strlen(s[i]);
	}
	return max;
}