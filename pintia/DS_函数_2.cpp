
void delchar(char *str, char c){
	int i = 0;
	while(str[i]!='\0'){
		if(str[i] == c){
			int j = i;
			while(str[j]!='\0'){
				str[j] = str[j+1];
				j++;
			}
			i--;
		}
		i++;
	}
}