/* ncr % p in < O(Nlogp), O(1) > */

#include <iostream>
#include <cassert>

#define ll long long
#define db(x) cout << "> " << #x << " : " << x << endl;

const int N = 100100;
const int MOD = 1000000007;	/* p */
using namespace std;

ll fact[N];
ll fact_inv[N];

ll bexp(ll a, ll b)
{
	ll res = 1;
	
	while(b)
	{
		if(b & 1)
			res = (res *a) % MOD;
		
		a = (a *a) % MOD;
		b >>= 1;
	}
	
	return res;
}

ll ncr(ll n, ll r)
{
	assert(n >= 0 && n < N && r >= 0 && r <= n);
	
	ll res = (fact_inv[r] *fact_inv[n -r]) % MOD;
	res = (res *fact[n]) % MOD;
	
	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	fact[0] = fact[1] = 1;

	for(int i = 2; i < N; i++)
		fact[i] = (fact[i -1] *i) % MOD;
	
	for(int i = 0; i < N; i++)
		fact_inv[i] = bexp(fact[i], MOD -2);
		
	while(1)
	{
		int n, r;
		cin >> n >> r;
		cout << ncr(n, r) << endl;
	}
	
	return 0;
}
