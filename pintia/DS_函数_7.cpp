int set_grade(struct student *p, int n){
	int count = 0;
	for(int i = 0; i < n; i++){
		if(p[i].score >= 85 && p[i].score <= 100)
			p[i].grade = 'A';
		else if(p[i].score <= 84 && p[i].score >= 70)
			p[i].grade = 'B';
		else if(p[i].score <= 69 && p[i].score >= 60)
			p[i].grade = 'C';
		else{
			count++;
			p[i].grade = 'D';
		}
	}
	return count;
}