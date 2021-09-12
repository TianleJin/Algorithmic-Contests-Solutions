#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

const int mxn = 500, mxm = 1000, inf = 2000000000;
int n, m, par[mxn];
bool vis[mxn];
vector<int> path, graph[mxn];
struct Edge {
	int a, b, c, r;
} edges[2 * mxm];

void dfs(int u) {
	path.push_back(u);
	if (u == n - 1) return;
	for (int i : graph[u]) {
		if (i % 2 == 0 && edges[i].c == 0) {
			edges[i].c = 1;
			dfs(edges[i].b);
			return;
		}
	}
}

// https://cses.fi/problemset/task/1711/
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b; --a; --b;
		int f = 2 * i, r = 2 * i + 1;
		edges[f] = { a, b, 1, r };
		edges[r] = { b, a, 0, f };
		graph[a].push_back(f);
		graph[b].push_back(r);
	}

	long long ans = 0;
	while (true) {
		bool found = false;
		queue<int> q; q.push(0);
		memset(vis, 0, sizeof(vis)); vis[0] = true;
		while (!found && q.size()) {
			int a = q.front(); q.pop();
			for (int i : graph[a]) {
				Edge e = edges[i];
				if (!vis[e.b] && e.c > 0) {
					vis[e.b] = true;
					par[e.b] = i;
					q.push(e.b);
					if (e.b == n - 1) {
						found = true; break;
					}
				}
			}
		}
		if (!found) break;
		int mf = inf, u = n - 1;
		while (u != 0) {
			int f = par[u];
			mf = min(mf, edges[f].c);
			u = edges[f].a;
		}

		ans += mf;
		u = n - 1;
		while (u != 0) {
			int f = par[u], r = edges[f].r;
			edges[f].c -= mf;
			edges[r].c += mf;
			u = edges[f].a;
		}
	}
	
	cout << ans << endl;
	for (int i = 0; i < ans; i++) {
		dfs(0);
		cout << (int)path.size() << endl;
		for (int i = 0; i < (int)path.size(); i++) {
			cout << path[i] + 1 << ' ';
		}
		cout << endl;
		path.clear();
	}
}