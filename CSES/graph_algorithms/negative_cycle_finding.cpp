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

// https://cses.fi/problemset/task/1197
// bellman ford
const int mxn = 6000;
const ll inf = 1e15;

int n, m;
vector<pii> graph[mxn];
int par[mxn];
ll dp[mxn];
bool vis[mxn];

void print(int node) {
	stack<int> stk1;
	while (1) {
		stk1.push(node);
		vis[node] = true;
		node = par[node];
		if (vis[node]) {
			cout << node;
			while (stk1.top() != node) {
				cout << ' ' << stk1.top();
				stk1.pop();
			}
			cout << ' ' << node;
			return;
		}
	}
}

void solve() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, s;
		cin >> u >> v >> s;
		graph[u].push_back({ v, s });
	}

	for (int i = 0; i < n - 1; i++) {
		for (int u = 1; u <= n; u++) {
			for (pii e : graph[u]) {
				int v = e.first, s = e.second;
				if (dp[v] > dp[u] + s) {
					par[v] = u;
					dp[v] = dp[u] + s;
				}
			}
		}
	}

	for (int u = 1; u <= n; u++) {
		for (pii e : graph[u]) {
			int v = e.first, s = e.second;
			if (dp[v] > dp[u] + s) {
				cout << "YES" << endl;
				print(u);
				return;
			}
		}
	}

	cout << "NO" << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}