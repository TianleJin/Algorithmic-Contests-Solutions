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

// https://cses.fi/problemset/task/1682
// tarjan's algorithm
const int mxn = 200001;
int n, m, disc[mxn], low[mxn], comp[mxn], c = 0, t = 0;
vector<int> graph[mxn];
stack<int> stk;
bool onStk[mxn];

void dfs(int node, int parent = 0) {
	disc[node] = low[node] = t++;
	stk.push(node);
	onStk[node] = true;
	for (int i : graph[node]) {
		if (disc[i] == -1) {
			dfs(i, node);
			low[node] = min(low[node], low[i]);
		}
		else if (onStk[i]) {
			low[node] = min(low[node], disc[i]);
		}
	}
	if (disc[node] == low[node]) {
		while (!stk.empty()) {
			int u = stk.top(); stk.pop();
			comp[u] = c;
			onStk[u] = false;
			if (u == node) break;
		}
		c++;
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

	for (int i = 1; i <= n; i++) {
		disc[i] = -1; low[i] = n + 1;
	}

	for (int i = 1; i <= n; i++) {
		if (disc[i] == -1) {
			dfs(i);
		}
	}

	if (c == 1) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl; 
		for (int i = 1; i <= n; i++) {
			if (comp[i] == 0) {
				cout << i;
				break;
			}
		}
		for (int i = 1; i <= n; i++) {
			if (comp[i] == 1) {
				cout << ' ' << i;
				break;
			}
		}
	}
}