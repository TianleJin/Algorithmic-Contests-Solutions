#include <iostream>
#include <algorithm>
#include <string.h>
#include <bitset>
#include <vector>
using namespace std;

const int mxn = 5e4;
int n, m;
vector<int> g[mxn];
bitset<mxn> reach[mxn];
bool vis[mxn];

void dfs(int u) {
	vis[u] = true;
	reach[u][u] = 1;
	for (int v : g[u]) {
		if (!vis[v]) {
			dfs(v);
		}
		reach[u] |= reach[v];
	}
}

// https://cses.fi/problemset/task/2138/
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b; --a; --b;
		g[a].push_back(b);
	}

	memset(vis, false, sizeof(vis));
	for (int u = 0; u < n; u++) {
		if (!vis[u]) {
			dfs(u);
		}
	}

	for (int u = 0; u < n; u++) {
		cout << reach[u].count() << ' ';
	}
}