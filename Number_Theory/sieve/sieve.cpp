
const int N = 1000000;

bool isPrime[N +100];

void sieve()
{
	for(int i = 2; i <= N; i++)
		isPrime[i] = 1;
	
	int till = sqrt(N);
	
	for(int i = 2; i <= till +1; i++) 
	{
		if(isPrime[i])
		{
			for(ll j = 1ll *i *i; j <= N; j += i)
			{
				isPrime[j] = 0;
			}
		}
	}
}
