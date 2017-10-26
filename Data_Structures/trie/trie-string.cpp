struct trie
{
	int words;
	int prefix;
	trie *ref[26];
};

trie *root = NULL;

void initialize(trie* init)
{
	init->words = 0;
	init->prefix = 0;
	
	for(int i = 0; i < 26; i++)
		init->ref[i] = NULL;
}

void addWord(string &s)
{
	trie *curr = root;
	
	int n = s.size();
	for(int i = 0; i < n; i++)
	{
		int target = s[i] -'a';
		
		if(curr->ref[target] == NULL)
		{
			curr->ref[target] = new trie;
			initialize(curr->ref[target]);
		}
		
		curr = curr->ref[target];
		curr->prefix++;
	}
	
	curr->words++;
}

int countWords(string &s)
{
	int n = s.size();
	
	trie *curr = root;
	for(int i = 0; i < n; i++)
	{
		int target = s[i] -'a';
		
		if(curr->ref[target] == NULL)
			return 0;
		
		curr = curr->ref[target];
	}
	
	return curr->words;
}

int countPrefixes(string &s)
{
	int n = s.size();
	
	trie *curr = root;
	for(int i = 0; i < n; i++)
	{
		int target = s[i] -'a';
		
		if(curr->ref[target] == NULL)
			return 0;
		
		curr = curr->ref[target];
	}
	
	return curr->prefix;
}

int main()
{
	root = new trie;	//make sure that you allocate memory for root
	initialize(root);
}
