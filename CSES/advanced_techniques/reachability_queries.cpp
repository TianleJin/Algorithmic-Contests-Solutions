#include <iostream>
#include <algorithm>
#include <string.h>
#include <bitset>
#include <vector>
#include <stack>
using namespace std;

const int mxn = 5e4;
int n, m, q, c = 0, t = 0, comp[mxn];
vector<int> g[mxn], gt[mxn], gc[mxn];
bitset<mxn> reach[mxn];
bool vis[mxn];
stack<int> stk;

void dfs1(int u) {
	vis[u] = true;
	for (int v : g[u]) {
		if (!vis[v]) {
			dfs1(v);
		}
	}
	stk.push(u);
}

void dfs2(int u) {
	comp[u] = c;
	for (int v : gt[u]) {
		if (comp[v] == -1) {
			dfs2(v);
		}
	}
}

void dfs3(int u) {
	vis[u] = true;
	reach[u][u] = 1;
	for (int v : gc[u]) {
		if (!vis[v]) {
			dfs3(v);
		}
		reach[u] |= reach[v];
	}
}

// https://cses.fi/problemset/task/2143
int main() {
	cin >> n >> m >> q;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b; --a; --b;
		g[a].push_back(b);
		gt[b].push_back(a);
	}

	memset(vis, false, sizeof(vis));
	for (int u = 0; u < n; u++) {
		if (!vis[u]) {
			dfs1(u);
		}
	}

	memset(comp, -1, sizeof(comp));
	while (!stk.empty()) {
		int u = stk.top(); stk.pop();
		if (comp[u] == -1) {
			dfs2(u);
			c++;
		}
	}

	for (int u = 0; u < n; u++) {
		for (int v : g[u]) {
			if (comp[u] != comp[v]) {
				gc[comp[u]].push_back(comp[v]);
			}
		}
	}

	memset(vis, false, sizeof(vis));
	for (int u = 0; u < c; u++) {
		if (!vis[u]) {
			dfs3(u);
		}
	}


	for (int i = 0; i < q; i++) {
		int a, b; cin >> a >> b; --a; --b;
		if (reach[comp[a]][comp[b]]) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
}