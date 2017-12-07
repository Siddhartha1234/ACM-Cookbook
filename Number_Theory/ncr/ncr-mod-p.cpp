/* ncr % p in < O(N), O(logp) > */

#include <iostream>
#include <cassert>

#define ll long long
#define db(x) cout << "> " << #x << " : " << x << endl;

const int N = 100100;
const int MOD = 1000000007;	/* p */
using namespace std;

ll fact[N];

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
	
	ll base = (fact[r] *fact[n -r]) % MOD;
	ll exponent = MOD -2;
	
	ll res = bexp(base, exponent);
	
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
	
	while(1)
	{
		int n, r;
		cin >> n >> r;
		cout << ncr(n, r) << endl;
	}
	
	return 0;
}
