const int N = 10010; // upper limit on number of nodes in the graph

vector<int> g[N]; // given graph
vector<int> gr[N] // transpose of given graph

bool vis[N];

stack<int> order; // for maintaining order according to ending time

void dfs1(int u)
{
	vis[u]=1;

	for(int i = 0; i < g[u].size(); i++)
	{
		if(!vis[g[u][i]])
			dfs1(g[u][i]);
	}

	order.push(u);
}

void dfs2(int u){
	vis[u] = 1;
	for(int i = 0; i < gr[u].size(); i++){
		if(!vis[gr[u][i]]){
			dfs2(gr[u][i]);
		}
	}
}

int n,m; // number of nodes and edges in graph


//inside int main

//getting order of nodes to be visited by second DFS
for(int i = 1; i <= n; i++)
{
	if(!vis[i]) 
		dfs1(i);
}

//re-initializing visited array
for(int i = 0; i < N; i++) 
	vis[i]=0;

//visiting nodes in given order in transverse graph
while(!order.empty())
{
	if(!vis[i])
	{
		dfs2(i);
		ans++;
	}
}
