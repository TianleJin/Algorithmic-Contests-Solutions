#include <iostream>
#include <string>
#include <array>
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

// https://cses.fi/problemset/task/1686/
// Kosaraju's algorithm + DP
const int mxn = 100001;
int n, m, c = 0;
int comp[mxn], coin[mxn];
ll total[mxn], dp[mxn];
bool vis[mxn];
vector<int> g[mxn], gt[mxn], gc[mxn];
stack<int> stk;

void dfs1(int node) {
	vis[node] = true;
	for (int i : g[node]) {
		if (!vis[i]) {
			dfs1(i);
		}
	}
	stk.push(node);
}

void dfs2(int node) {
	comp[node] = c;
	for (int i : gt[node]) {
		if (comp[i] == -1) {
			dfs2(i);
		}
	}
}

ll dfs3(int node) {
	if (dp[node] != -1) {
		return dp[node];
	}
	dp[node] = total[node];
	for (int i : gc[node]) {
		dp[node] = max(dp[node], dfs3(i) + total[node]);
	}
	return dp[node];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> coin[i];
		comp[i] = -1;
	}

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		gt[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			dfs1(i);
		}
	}

	while (!stk.empty()) {
		int node = stk.top(); stk.pop();
		if (comp[node] == -1) {
			dfs2(node);
			c++;
		}
	}

	for (int u = 1; u <= n; u++) {
		for (int i : g[u]) {
			if (comp[u] != comp[i]) {
				gc[comp[u]].push_back(comp[i]);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		total[comp[i]] += coin[i];
	}

	for (int i = 0; i < c; i++) {
		dp[i] = -1;
	}

	ll ans = 0;
	for (int i = 0; i < c; i++) {
		ans = max(ans, dfs3(i));
	}
	cout << ans << endl;
}