// Dfs on a graph
// If you can't understand this code, go die!
const int N = 100010;

vector<int> vis(N,0);
vector<int> adj[N];

void dfs(int u)
{
	vis[u] = true;
	for(int i = 0; i < adj[u].size(); i++)
	{
		if(!vis[i]){
			dfs(i);
		}
	}
}

// Dfs on a grid
/* Well this is simple enough for you to understand, but then I
*  don't want you to die, so I will comment it anyways.
*/

const int N = 100010;

int vis[N][N]; //visited array

int dx[] = {0,1,0,-1}; //change in x direction
int dy[] = {1,0,-1,0}; // change in y direction

int n,m; // dimensions of grid, n -> x dimension, m -> y dimension

// rest of code same as above
void dfs(pair<int,int> u){

	vis[u.first][u.second] = 1;

	for(int i = 0; i < 4; i++)
	{
		pair<int,int> v = {u.first+dx[i],u.second+dy[i]};
		if(v.fisrt < 1 or v.first > n or v.second > m or v.second < 1 or vis[v.first][v.second]){
			continue;
		}
		else{
			// do something
			dfs(v);
		}
	}
}
