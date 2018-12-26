Position BinarySearch( List L, ElementType X ){
	int left = 0, right = L->Last;
	int mid;
	while(left <= right){
		mid = left+(right-left)/2;
		if(L->Data[mid] == X)
			return mid;
		else if(L->Data[mid] > X){
			right = mid-1;
		}
		else if(L->Data[mid] < X){
			left = mid+1;
		}
	}
	return NotFound;
}