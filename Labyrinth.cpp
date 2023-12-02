#include <iostream>
#include <vector>
#include <unistd.h>
#include <unistd.h>
#include <algorithm>
#include <map>
#include <cmath>
#include <cstring>
#include <sstream>
#include <set>
#include <unordered_set>
#include <cstring>
#include <string.h>
#include <queue>

using namespace std;
#define mid(s, e) (s + (e - s) / 2)
#define ALL(x) (x).begin(), (x).end()
#define endl '\n'
#define MAXE(vec) *max_element(ALL(vec))
#define MINE(vec) *min_element(ALL(vec))
#define valid(a, b, c) (a >= b && a < c ? 1 : 0)
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
#define ll long long
void solve()
{
	ll n, m;
	cin >> n >> m;
	vector<vector<char>> grid(n, vector<char>(m));
	vector<vector<ll>> neighbors(n*m);
	vector<ll> vis(n * m, 0);
	ll start_position = 0;
	ll end_position = 0;
	for (ll i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> grid[i][j];
		}
	}
	ll ans = 0;
	for (ll i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (grid[i][j] != '#')
			{
				for (int k = 0; k < 4; k++)
				{
					ll x = i + dx[k];
					ll y = j + dy[k];
					if (valid(x, 0, n) && valid(y, 0, m) && grid[x][y] != '#')
					{
						neighbors[i * m + j].push_back(x * m + y);
					}
				}
			}
			if(grid[i][j] == 'A')
				start_position = i * m + j;
			if(grid[i][j] == 'B')
				end_position = i * m + j;
		}
	}
	vector<ll> dist(n * m, 1e9);
	queue<ll> q;
	vector<ll> parent(n * m, -1);
	q.push(start_position);
	dist[start_position] = 0;
	while(!q.empty())
	{
		ll node = q.front();
		q.pop();
		for(auto child: neighbors[node])
		{
			if(dist[child] > dist[node] + 1)
			{
				dist[child] = dist[node] + 1;
				parent[child] = node;
				q.push(child);
			}
		}
	}
	if(dist[end_position] == 1e9)
	{
		cout << "NO" << endl;
		return;
	}
	cout << "YES" << endl;
	cout << dist[end_position] << endl;
	string path;
	while(end_position != start_position)
	{
		ll node = end_position;
		ll parent_node = parent[node];
		if(node == parent_node + 1)
			path += 'R';
		else if(node == parent_node - 1)
			path += 'L';
		else if(node == parent_node + m)
			path += 'D';
		else
			path += 'U';
		end_position = parent_node;
	}
	reverse(ALL(path));
	cout << path << endl;
}
int main(void)
{
	ll t;
	t = 1;
	while (t--)
		solve();
}
