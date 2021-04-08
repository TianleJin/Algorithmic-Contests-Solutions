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
const int dxknight[] = { -1, -1, -2, -2, 1, 1, 2, 2 };
const int dyknight[] = { 2, -2, 1, -1, 2, -2, 1, -1 };

// https://cses.fi/problemset/task/1694/
// Ford Fulkerson Algorithm
struct Edge {
	int u, v, rev, cap;
};

const int mxn = 501;
const int mxe = 1001;
const ll inf = 1e15;
int n, m;
Edge edges[mxe << 1];
vector<int> graph[mxn];
int par[mxn];
bool vis[mxn];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		int fwd = 2 * i;
		int rev = 2 * i + 1;
		edges[fwd] = { u, v, c, rev };
		edges[rev] = { v, u, 0, fwd };
		graph[u].push_back(fwd);
		graph[v].push_back(rev);
	}

	ll mf = 0;
	const int src = 1;
	const int snk = n;
	while (1) {
		queue<int> q;
		q.push(src);
		memset(vis, false, sizeof(vis));
		vis[src] = true;
		bool found = false;
		while (!q.empty() && !found) {
			int u = q.front(); q.pop();
			for (int i : graph[u]) {
				Edge e = edges[i];
				if (!vis[e.v] && e.cap > 0) {
					vis[e.v] = true;
					par[e.v] = i;
					q.push(e.v);
					if (e.v == snk) {
						found = true;
						break;
					}
				}
			}
		}

		if (!vis[snk]) {
			break;
		}

		ll pf = inf;
		int v = snk;
		while (v != src) {
			int i = par[v];
			pf = min(pf, (ll)edges[i].cap);
			v = edges[i].u;
		}

		mf += pf;
		v = snk;
		while (v != src) {
			int i = par[v];
			edges[i].cap -= pf;
			edges[edges[i].rev].cap += pf;
			v = edges[i].u;
		}
	}
	cout << mf << endl;
}