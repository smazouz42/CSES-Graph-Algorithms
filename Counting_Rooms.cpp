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
			if (grid[i][j] == '.')
			{
				for (int k = 0; k < 4; k++)
				{
					ll x = i + dx[k];
					ll y = j + dy[k];
					if (valid(x, 0, n) && valid(y, 0, m) && grid[x][y] == '.')
					{
						neighbors[i * m + j].push_back(x * m + y);
					}
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++)
	{
		if (!vis[i] && grid[i / m][i % m] == '.')
		{
			ans += 1;
			queue<ll> q;
			q.push(i);
			vis[i] = 1;
			while (q.size())
			{
				ll u = q.front();
				q.pop();
				for (auto v : neighbors[u])
				{
					if (!vis[v])
					{
						vis[v] = 1;
						q.push(v);
					}
				}
			}
		}
	}
	cout << ans << endl;
}
int main(void)
{
	ll t;
	t = 1;
	while (t--)
		solve();
}
