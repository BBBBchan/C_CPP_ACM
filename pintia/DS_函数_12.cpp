ElementType Find(List L, int m){
	int j = 0;
	List P = L;
	while(P->Next != NULL && j < m){
		  	P = P->Next;
			j++;
		}
	if(j < m)
		return ERROR;
	L = L->Next;
	for(int i = 0;L; i++){
		if(P->Next == NULL)
			return L->Data;
		L = L->Next;
		P = P->Next;
	}
	return ERROR;
}