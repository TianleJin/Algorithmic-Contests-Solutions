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

// https://cses.fi/problemset/task/1673/
// bellman ford
const int mxn = 6000;
const ll inf = 1e15;

int n, m;
bool bad = false;
vector<int> bwd[mxn];
vector<pii> fwd[mxn];
ll dp[mxn];
bool chng[mxn], vis1[mxn], vis2[mxn];

void dfs(int node) {
	vis2[node] = 1;
	if (vis1[node] && chng[node]) {
		bad = true;
		return;
	}
	for (int i : bwd[node]) {
		if (!vis2[i]) {
			dfs(i);
		}
	}
}

void solve() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, s;
		cin >> u >> v >> s;
		bwd[v].push_back(u);
		fwd[u].push_back({ v, s });
	}

	for (int i = 2; i <= n; i++) {
		dp[i] = -inf;
	}

	vis1[1] = true;
	for (int i = 0; i < n - 1; i++) {
		for (int u = 1; u <= n; u++) {
			if (!vis1[u]) continue;
			for (pii e : fwd[u]) {
				int v = e.first, s = e.second;
				if (dp[v] < dp[u] + s) {
					dp[v] = dp[u] + s;
					vis1[v] = true;
				}
			}
		}
	}

	ll ans = dp[n];

	for (int u = 1; u <= n; u++) {
		if (!vis1[u]) continue;
		for (pii e : fwd[u]) {
			int v = e.first, s = e.second;
			if (dp[v] < dp[u] + s) {
				dp[v] = dp[u] + s;
				vis1[v] = true;
				chng[v] = true;
			}
		}
	}

	dfs(n);

	if (bad) {
		cout << -1 << endl;
	}
	else {
		cout << ans << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}