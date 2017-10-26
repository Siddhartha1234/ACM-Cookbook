
const int LEN = 62;
inline bool bit(ll mask, int idx) { return ((mask & (1ll << idx)) != 0); }

struct trie
{
	int num;
	trie *ref[2];
};

trie *root = NULL;

void initialize(trie* init)
{
	init->num = 0;
	
	for(int i = 0; i < 2; i++)
		init->ref[i] = NULL;
}

void insert(ll x)
{
	trie *curr = root;
	
	for(int i = LEN; i >= 0; i--)
	{
		int dest = bit(x, i);
		
		if(curr->ref[dest] == NULL)
		{
			curr->ref[dest] = new trie;
			initialize(curr->ref[dest]);
		}
		
		curr = curr->ref[dest];
	}
	
	curr->num++;
}

int cnt(ll x)
{
	trie *curr = root;
	for(int i = LEN; i >= 0; i--)
	{
		//do something
		
		int dest = bit(x, i);
		
		if(curr->ref[dest] == NULL)
			return 0;
		
		curr = curr->ref[dest];
	}
	
	return curr->num;
}

int main()
{
	root = new trie;
	initialize(root);
	
	return 0;
}
