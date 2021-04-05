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

// https://cses.fi/problemset/task/1680
// topological sort
const int mxn = 2e5;
const ll inf = 1e18;

int n, m;
vector<int> graph[mxn];
int in[mxn], par[mxn], dist[mxn];
bool can[mxn];

void dfs(int node) {
	can[node] = true;
	for (int i : graph[node]) {
		if (!can[i]) {
			dfs(i);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
	}

	dfs(1);

	if (!can[n]) {
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}

	for (int node = 1; node <= n; node++) {
		if (can[node]) {
			for (int i : graph[node]) {
				in[i]++;
			}
		}
	}

	assert(in[1] == 0);

	queue<int> q;
	q.push(1);

	while (!q.empty()) {
		int node = q.front(); q.pop();
		for (int i : graph[node]) {
			if (dist[i] < dist[node] + 1) {
				dist[i] = dist[node] + 1;
				par[i] = node;
			}

			in[i]--;
			if (in[i] == 0) {
				q.push(i);
			}
		}
	}
	
	stack<int> stk;
	int node = n;
	while (node != 1) {
		stk.push(node);
		node = par[node];
	}

	cout << dist[n] + 1 << endl;
	cout << 1;
	while (stk.size()) {
		cout << ' ' << stk.top(); stk.pop();
	}
}