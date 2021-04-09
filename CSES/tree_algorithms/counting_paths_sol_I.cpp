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
// eulerian tour + rmq lca query
const int mxn = 200005;
int n, m;
int timer = 0;
vector<int> graph[mxn];
int ans[mxn], par[mxn], start[mxn], depth[mxn], range[2 * mxn], seg[8 * mxn];

void build(int idx = 1, int l = 0, int r = timer) {
	if (r - l < 2) {
		seg[idx] = range[l];
		return;
	}
	int mid = (l + r) / 2;
	build(2 * idx, l, mid);
	build(2 * idx + 1, mid, r);
	seg[idx] = depth[seg[2 * idx]] < depth[seg[2 * idx + 1]] ? seg[2 * idx] : seg[2 * idx + 1];
}

int query(int x, int y, int idx = 1, int l = 0, int r = timer) {
	if (x >= r || y <= l) return n + 1;
	if (x <= l && r <= y) {
		return seg[idx];
	}
	int mid = (l + r) / 2;
	int ans1 = query(x, y, 2 * idx, l, mid);
	int ans2 = query(x, y, 2 * idx + 1, mid, r);
	return depth[ans1] < depth[ans2] ? ans1 : ans2;
}

void dfs1(int node, int parent = 0, int level = 1) {
	par[node] = parent;
	depth[node] = level;
	start[node] = timer;
	range[timer++] = node;
	for (int i : graph[node]) {
		if (i != parent) {
			dfs1(i, node, level + 1);
			range[timer++] = node;
		}
	}
}

void dfs2(int node, int parent = 0) {
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

	depth[n + 1] = n + 1;

	build();

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
		int lca = query(min(start[a], start[b]), max(start[a], start[b]) + 1);
		
		// cout << a << ' ' << b << ' ' << lca << endl;
		
		if (lca == a) {
			++ans[b];
			--ans[par[a]];
		}
		else if (lca == b) {
			++ans[a];
			--ans[par[b]];
		}
		else {
			++ans[a];
			++ans[b];
			--ans[lca];
			--ans[par[lca]];
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