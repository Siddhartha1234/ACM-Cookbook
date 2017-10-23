//segment tree to find sum of a range with point updates

int a[N];
int T[4 *N];

inline int c1(int n) { return (n << 1); }
inline int c2(int n) { return (n << 1)|1; }

void build(int curr, int st, int end)
{
	if(st == end)
	{
		T[curr] = a[st];
		return;
	}
	
	int mid = st +end >> 1;
	
	build(c1(curr), st, mid);
	build(c2(curr), mid +1, end);
	
	T[curr] = T[c1(curr)] +T[c2(curr)];
}

void update(int curr, int st, int end, int idx, int value)
{
	if(st == end)
	{
		a[idx] = value;
		T[curr] = value;
		return;
	}
	
	int mid = st +end >> 1;
	
	if(idx <= mid)
		update(c1(curr), st, mid, idx, value);
	
	else
		update(c2(curr), mid +1, end, idx, value);
		
	T[curr] = T[c1(curr)] +T[c2(curr)];
}

int query(int curr, int st, int end, int l, int r)
{
	if(st > end || r < st || end < l)
		return 0;
	
	if(l <= st && end <= r)
		return T[curr];
	
	int mid = st +end >> 1;
	
	int q1 = query(c1(curr), st, mid, l, r);
	int q2 = query(c2(curr), mid +1, end, l, r);
	
	return q1 +q2;
}

