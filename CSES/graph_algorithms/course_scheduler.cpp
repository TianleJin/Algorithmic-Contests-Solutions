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

// https://cses.fi/problemset/task/1679/
// topological sort
const int mxn = 2e5;
const ll inf = 1e18;

int n, m;
vector<int> graph[mxn];
int vis[mxn];
stack<int> stk;

bool dfs(int node) {
	vis[node] = 1;
	for (int i : graph[node]) {
		if (vis[i] == 1 || !vis[i] && dfs(i)) {
			return true;
		}
	}
	vis[node] = 2;
	stk.push(node);
	return false;
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

	for (int i = 1; i <= n; i++) {
		if (!vis[i] && dfs(i)) {
			cout << "IMPOSSIBLE" << endl;
			return 0;
		}
	}

	assert(stk.size() == n);
	while (!stk.empty()) {
		cout << stk.top() << ' '; stk.pop();
	}
}