bool find(int *a, int left, int right, int key){
	if(left > right)
		return 0;
	int mid = left + (right-left)/2;
	if(a[mid] > key)
		return find(a,left,right-1,key);
	else if(a[mid] < key)
		return find(a,left+1,right,key);
	else
		return 1;
	return 0;
}