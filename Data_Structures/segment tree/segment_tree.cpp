//segment tree to find sum of a range with point updates

struct node		//modify this as per questions requirements
{
	int val;
};

int a[N];
node T[4 *N];
node identity;	//set this such that merge(a, identity) = a and merge(identity, b) = b

inline int c1(int n) { return (n << 1); }
inline int c2(int n) { return (n << 1)|1; }

void init(node &a, int val)
{
	a.val = a;
}

node merge(node &a, node &b)
{
	//handle condition for identity seperately
	
	node res;
	res.val = a.val +b.val;
	return res;
}

void build(int curr, int st, int end)
{
	if(st == end)
	{
		init(T[curr], a[st]);
		return;
	}
	
	int mid = st +end >> 1;
	
	build(c1(curr), st, mid);
	build(c2(curr), mid +1, end);
	
	T[curr] = merge(T[c1(curr)], T[c2(curr)]);
}

void update(int curr, int st, int end, int idx, int value)
{
	if(st == end)
	{
		init(T[curr], value);
		return;
	}
	
	int mid = st +end >> 1;
	
	if(idx <= mid)
		update(c1(curr), st, mid, idx, value);
	
	else
		update(c2(curr), mid +1, end, idx, value);
	
	T[curr] = merge(T[c1(curr)], T[c2(curr)]);		
}

node query(int curr, int st, int end, int l, int r)
{
	if(st > end || r < st || end < l)
		return identity;
	
	if(l <= st && end <= r)
		return T[curr];
	
	int mid = st +end >> 1;
	
	node q1 = query(c1(curr), st, mid, l, r);
	node q2 = query(c2(curr), mid +1, end, l, r);
	
	return merge(q1, q2);
}

