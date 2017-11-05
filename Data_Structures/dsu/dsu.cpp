const int N = 1000100;

int p[N];
int rnk[N];

inline void createSet(int x)
{
	p[x] = x;
	rnk[x] = 0;
}

int findSet(int x)
{
	if(x != p[x])
		p[x] = findSet(p[x]);
	
	return p[x];
}

void mergeSet(int x, int y)
{
	int p_x = findSet(x);	//representative of x
	int p_y = findSet(y);
	
	if(rnk[p_x] > rnk[p_y])
		p[p_y] = p_x;
	
	else
		p[p_x] = p_y;
	
	if(rnk[p_x] == rnk[p_y])
		rnk[p_y]++;
}

bool isSameSet(int x, int y)
{
	int a = findSet(x);
	int b = findSet(y);
	
	return (a == b);
}

int main()
{
	for(int i = 0; i < n; i++)		//don't forget to do this
		createSet(i);
		
	return 0;
}
