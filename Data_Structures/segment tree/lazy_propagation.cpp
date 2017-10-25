struct node		//modify this as per questions requirements
{
	int val;
};

int a[N];
node T[4 *N];
int lazy[4 *N];
node identity;	//set this such that merge(a, identity) = a and merge(identity, b) = b

inline int c1(int n) { return (n << 1); }
inline int c2(int n) { return (n << 1)|1; }

void init(node &a, int val)
{
	a.val = a;
}

void change(node &a, int val)
{
	a.val += val;
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

void update(int node, int st, int end, int l, int r, int v)
{
	if(lazy[node] != 0)
	{
		change(T[node], lazy[node]);
		
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
		change(T[node], v);
		
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
	
	T[node] = merge(T[c1(node)], T[c2(node)]);
}

node query(int node, int st, int end, int l, int r)
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
		return identity;
	
	if(l <= st && end <= r)
		return T[node];
	
	int mid = st +end >> 1;
	node q1 = query(c1(node), st, mid, l, r);
	node q2 = query(c2(node), mid +1, end, l, r);
	
	return merge(q1, q2);
}

