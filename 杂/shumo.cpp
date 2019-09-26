int visit[1505] = {0}
struct point
{
	int x,y,z,coun;
}point[1505];
vector <point> newpoints(1505)
for(int i = 0; i < 1505; i++){
	if(!visit[i] && density(i) >= 2)
	{
		visit[i] = 1;
		int newx = point[i].x, newy=point[i].y, newz = point[i].z, newcoun = 1; 
		for(int j = 0; j < 1505; j++)
		{ 
			if(!visit[j] && distance(i,j) <= 1.5 && coun <= 5) 
			{
				visit[j] = 1;
				newx += point[j].x;
				newy += point[j].y;
				newz += point[j].z;
				newcoun++;
			}
		}
		point temp;
		temp.x = newx/newcoun;
		temp.y = newy/newcoun;
		temp.z = newz/newcoun;
		temp.coun = newcoun;
		newpoints.push_back(temp);
	}
}