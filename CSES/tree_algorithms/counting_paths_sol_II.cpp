#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int dx4[] = { -1, 0, 1, 0 };
const int dy4[] = { 0, -1, 0, 1 };
const int dx8[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
const int dy8[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

// https://cses.fi/problemset/task/1136
// binary lifting lca
const int mxn = 200005;
const int mxl = 22;
int n, m;
int timer = 0;
vector<int> graph[mxn];
int ans[mxn], par[mxn][mxl], st[mxn], en[mxn];

int isAncestor(int node1, int node2) {
	return st[node1] <= st[node2] && en[node2] <= en[node1];
}

int query(int node1, int node2) {
	if (isAncestor(node1, node2)) return node1;
	if (isAncestor(node2, node1)) return node2;
	for (int i = mxl - 1; i >= 0; i--) {
		if (!isAncestor(par[node1][i], node2)) {
			node1 = par[node1][i];
		}
	}
	return par[node1][0];
}

void dfs1(int node, int parent = 1) {
	st[node] = timer++;
	par[node][0] = parent;
	for (int i = 1; i < mxl; i++) {
		par[node][i] = par[par[node][i - 1]][i - 1];
	}
	for (int i : graph[node]) {
		if (i != parent) {
			dfs1(i, node);
		}
	}
	en[node] = timer++;
}

void dfs2(int node, int parent = 1) {
	for (int i : graph[node]) {
		if (i != parent) {
			dfs2(i, node);
			ans[node] += ans[i];
		}
	}
}

void solve() {
	cin >> n >> m;
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	dfs1(1);

	/*
	for (int i = 0; i < timer; i++) {
		cout << "time " << i << ": " << range[i] << endl;
	}

	for (int i = 1; i <= n; i++) {
		cout << "depth of node " << i << ": " << depth[i] << endl;
	}
	*/

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		int lca = query(a, b);
		// cout << a << ' ' << b << ' ' << lca << endl;
		if (lca == a) {
			++ans[b];
			if (par[a][0] != a) --ans[par[a][0]];
		}
		else if (lca == b) {
			++ans[a];
			if (par[b][0] != b) --ans[par[b][0]];
		}
		else {
			++ans[a];
			++ans[b];
			--ans[lca];
			if (par[lca][0] != lca) --ans[par[lca][0]];
		}
	}

	dfs2(1);

	for (int i = 1; i <= n; i++) {
		cout << ans[i] << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}