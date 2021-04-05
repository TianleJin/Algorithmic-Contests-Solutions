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

// https://cses.fi/problemset/task/1160/
// binary lifting + functional graphs
const int mxn = 200001;
const int mxl = 31;
int n, q, par[mxn][mxl], idx[mxn], sze[mxn], depth[mxn], comp[mxn], tmp[mxn];
vector<int> adj[mxn], chd[mxn];
bool isCycle[mxn];

void dfs1(int node) {
	int head = node;
	while (tmp[node] == 0) {
		tmp[node] = head;
		node = par[node][0];
	}

	while (tmp[node] == head) {
		tmp[node] += n;
		isCycle[node] = true;
		idx[node] = sze[comp[node]]++;
		node = par[node][0];
	}
}

void dfs2(int node) {
	for (int i : chd[node]) {
		if (!isCycle[i]) {
			depth[i] = depth[node] + 1;
			dfs2(i);
		}
	}
}

int getAncestor(int node, int k) {
	for (int i = 0; i < mxl; i++) {
		if (k >> i & 1) {
			node = par[node][i];
		}
	}
	return node;
}

void preprocess() {
	for (int i = 1; i <= n; i++) {
		dfs1(i);
	}
	
	for (int i = 1; i < mxl; i++) {
		for (int u = 1; u <= n; u++) {
			par[u][i] = par[par[u][i - 1]][i - 1];
		}
	}
	for (int i = 1; i <= n; i++) {
		if (isCycle[i]) {
			dfs2(i);
		}
	}
}

void getComp(int node, int head) {
	if (comp[node]) {
		return;
	}
	comp[node] = head;
	for (int i : adj[node]) {
		getComp(i, head);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		int p;
		cin >> p;
		par[i][0] = p;
		adj[i].push_back(p);
		adj[p].push_back(i);
		chd[p].push_back(i);
	}

	for (int i = 1; i <= n; i++) {
		if (comp[i] == 0) {
			getComp(i, i);
		}
	}

	preprocess();

	for (int i = 1; i <= q; i++) {
		int a, b;
		cin >> a >> b;
		if (comp[a] != comp[b]) {
			cout << -1 << endl;
			continue;
		}
		if (!isCycle[a]) {
			if (isCycle[b]) {
				int x = getAncestor(a, depth[a]);
				cout << depth[a] + (idx[b] - idx[x] + sze[comp[a]]) % sze[comp[a]] << endl;
			}
			else {
				if (getAncestor(a, depth[a] - depth[b]) == b) {
					cout << depth[a] - depth[b] << endl;
				}
				else {
					cout << -1 << endl;
				}
			}
		}
		else {
			if (isCycle[b]) {
				cout << (idx[b] - idx[a] + sze[comp[a]]) % sze[comp[a]] << endl;
			}
			else {
				cout << -1 << endl;
			}
		}
	}
}