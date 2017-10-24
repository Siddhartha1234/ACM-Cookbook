// Topological sorting/Cycle detection

const int N=100010; // upper limit on number of nodesin graph

int color[N]; // 0-> white, 1-> grey, 2-> black 
vector<int> adj[N];
list<int> order; // for maintaining topological order

bool cycle=0; // flag to detect cycle

void topo(int u)
{
	
	color[u] = 1;

	for(int i = 0; i < adj[u].size(); i++)
	{
		if(color[adj[u][i]] == 1)
			cycle = 1;

		else if(color[adj[u][i]] == 0)
			topo(adj[u][i]);
	}

	color[u] = 2;
	topo.push_front(u);
	return;
}