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

// https://cses.fi/problemset/task/1684/
// Kosaraju's SCC algorithm + 2-SAT 
const int mxn = 200005;
int n, m, c = 0;
int comp[mxn];
bool vis[mxn];
vector<int> g[mxn], gt[mxn];
stack<int> stk;

int tr(int i) {
	return i & 1 ? i - 1 : i + 1;
}

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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		char c1, c2;
		int t1, t2;
		cin >> c1 >> t1 >> c2 >> t2; --t1; --t2;
		t1 = c1 == '+' ? 2 * t1 + 1 : 2 * t1;
		t2 = c2 == '+' ? 2 * t2 + 1 : 2 * t2;
		g[tr(t1)].push_back(t2);
		g[tr(t2)].push_back(t1);
		gt[t1].push_back(tr(t2));
		gt[t2].push_back(tr(t1));
	}

	for (int i = 0; i < 2 * m; i++) {
		comp[i] = -1;
	}

	for (int i = 0; i < 2 * m; i++) {
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

	for (int i = 0; i < 2 * m; i += 2) {
		if (comp[i] == comp[i + 1]) {
			cout << "IMPOSSIBLE" << endl; return 0;
		}
	}

	for (int i = 0; i < m; i++) {
		if (comp[2 * i] > comp[2 * i + 1]) {
			cout << '-' << ' ';
		}
		else {
			cout << '+' << ' ';
		}
	}
}