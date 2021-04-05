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

// https://cses.fi/problemset/task/1691/
// eulerian circuit
const int mxn = 100001;
int n, m, ind[mxn];
vector<int> graph[mxn], path;
unordered_set<int> vis1[mxn];
bool vis2[mxn];

void dfs(int node) {
	vis2[node] = true;
	while (ind[node] < graph[node].size()) {
		int u = graph[node][ind[node]++];
		if (vis1[u].find(node) == vis1[u].end()) {
			vis1[node].insert(u);
			dfs(u);
		}
	}
	path.push_back(node);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (int u = 1; u <= n; u++) {
		if (graph[u].size() % 2) {
			cout << "IMPOSSIBLE" << endl; return 0;
		}
	}

	dfs(1);

	for (int u = 1; u <= n; u++) {
		if (!vis2[u] && graph[u].size()) {
			cout << "IMPOSSIBLE" << endl; return 0;
		}
	}

	for (int u : path) {
		cout << u << ' ';
	}
}