const int N; // define n as number of nodes, so size of array can be 2*n;

vector<int> adj[N];

int BEGIN[2*N];       // denotes begining of v's subtree
int END[2*N];        // denotes ending index of v's subtree
int discover[2*N];  // array on which you have to built segment tree
int position[2*N];      // position of a node in discover array

vector<bool> vis(N,0);

int cnt = -1;    // for 0-indexed indexing of arrays

void dfs(int u)
{
	vis[u] = 1;

	discover[++cnt] = u; // discovering that node for first time
	position[u] = cnt;       // storing position of that node in discover array
	
	BEGIN[u] = cnt;    // storing begining index of that node in discover array
	
	for(int i = 0; i < adj[u].size(); i++)
	{
		if(!vis[adj[u][i]])
			dfs(adj[u][i]);
	}

	END[u] = cnt;  // storing ending index of that node in discover array 
}
