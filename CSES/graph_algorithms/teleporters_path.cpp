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

// https://cses.fi/problemset/task/1693/
// eulerian path
const int mxn = 100001;
int n, m, in[mxn], out[mxn];
stack<int> graph[mxn];
stack<int> stk;
bool vis[mxn];

void dfs(int node) {
	vis[node] = true;
	while (!graph[node].empty()) {
		int u = graph[node].top(); graph[node].pop();
		dfs(u);
	}
	stk.push(node);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push(v);
		in[v]++; out[u]++;
	}

	bool ok = true;
	if (out[1] != in[1] + 1) ok = false;
	if (out[n] != in[n] - 1) ok = false;
	for (int u = 2; u < n; u++) {
		if (in[u] != out[u]) ok = false;
	}
	if (!ok) {
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}

	dfs(1);

	for (int u = 1; u <= n; u++) {
		if (!vis[u] && out[u]) {
			cout << "IMPOSSIBLE" << endl;
			return 0;
		}
	}

	while (!stk.empty()) {
		cout << stk.top() << ' '; stk.pop();
	}
}