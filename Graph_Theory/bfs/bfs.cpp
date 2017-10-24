const int N = 100010;

vector<int> adj[N];
vector<int> vis[N];

void bfs(int u)
{
	queue<int> q;
	q.push_back(u);
	vis[u] = 1;

	while(!q.empty())
	{
		int u = q.front(); q.pop();

		for(int i = 0; i < adj[u].size(); i++)
		{
			int v = adj[u][i];
			
			if(!vis[v])
			{
				// do something
				vis[v] = 1;
				q.push(v);
			}
		}
	}
}