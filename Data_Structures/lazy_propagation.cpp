int a[N];
int T[4 *N];
int lazy[4 *N];

inline int c1(int n) { return (n << 1); }
inline int c2(int n) { return (n << 1)|1; }

void build(int node, int st, int end)
{
	if(st == end)
	{ 
		T[node] = a[st];
		return; 
	}
	
	int mid = st +end >> 1;
	
	build(c1(node), st, mid);
	build(c2(node), mid +1, end);
	T[node] = min(T[c1(node)], T[c2(node)]);
}

void update(int node, int st, int end, int l, int r, int v)
{
	if(lazy[node] != 0)
	{
		T[node] += lazy[node];
		
		if(st != end)
		{
			lazy[c1(node)] += lazy[node];	//check these steps properly
			lazy[c2(node)] += lazy[node];
		}
		
		lazy[node] = 0;
	}
	
	if(st > end || r < st || end < l)
		return;
	
	if(l <= st && end <= r)
	{
		T[node] += v;
		
		if(st != end)
		{
			lazy[c1(node)] += v;
			lazy[c2(node)] += v;
		}
		
		return;
	}
	
	int mid = st +end >> 1;
	update(c1(node), st, mid, l, r, v);
	update(c2(node), mid +1, end, l, r, v);
	
	T[node] = min(T[c1(node)], T[c2(node)]);
}

int query(int node, int st, int end, int l, int r)
{
	if(lazy[node] != 0)
	{
		T[node] += lazy[node];
		
		if(st != end)
		{
			lazy[c1(node)] += lazy[node];
			lazy[c2(node)] += lazy[node];
		}
		
		lazy[node] = 0;
	}

	if(st > end || r < st || end < l)
		return INF;
	
	if(l <= st && end <= r)
		return T[node];
	
	int mid = st +end >> 1;
	int q1 = query(c1(node), st, mid, l, r);
	int q2 = query(c2(node), mid +1, end, l, r);
	
	return min(q1, q2);
}

