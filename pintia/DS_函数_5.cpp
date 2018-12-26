void strmcpy(char *t, int m, char *s){
	int j = 0;
	while(t[j] != '\0')
		j++;
	if(m > j){
		s[0] = '\0';
		return;
	}
	int i = 0;
	while(t[m-1] != '\0'){
		s[i] = t[m-1];
		m++;
		i++;
	}
	s[i] = '\0';
}