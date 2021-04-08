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

// https://cses.fi/problemset/task/1695/
// max flow min cut

const int mxn = 505;
const int mxm = 2005;

struct Edge {
	int from, to, capacity, rev;
};

int n, m;
vector<int> graph[mxn];
int par[mxn];
bool vis[mxn], can[mxn];
Edge edges[mxm];

void dfs(int cur) {
	can[cur] = true;
	for (int i : graph[cur]) {
		Edge e = edges[i];
		if (!can[e.to] && e.capacity) {
			dfs(e.to);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		int fwd = 2 * i, bwd = 2 * i + 1;
		edges[fwd] = { a, b, 1, bwd };
		edges[bwd] = { b, a, 1, fwd };
		graph[a].push_back(fwd);
		graph[b].push_back(bwd);
	}

	while (1) {
		memset(vis, 0, sizeof(vis));
		memset(par, 0, sizeof(par));
		bool found = false;
		queue<int> q;
		q.push(1);
		vis[1] = true;
		while (!q.empty() && !found) {
			int cur = q.front(); q.pop();
			for (int i : graph[cur]) {
				Edge e = edges[i];
				if (!vis[e.to] && e.capacity) {
					vis[e.to] = 1;
					par[e.to] = i;
					q.push(e.to);
					if (e.to == n) {
						found = true;
						break;
					}
				}
			}
		}
		if (!found) {
			break;
		}
		for (int cur = n; cur != 1; cur = edges[par[cur]].from) {
			int i = par[cur];
			edges[i].capacity = 0;
			edges[edges[i].rev].capacity = 1;
		}
	}

	dfs(1);

	vector<pii> ans;
	for (int i = 0; i < 2 * m; i += 2) {
		Edge e = edges[i];
		if (can[e.from] != can[e.to]) {
			ans.push_back({ e.from, e.to });
		}
	}

	cout << ans.size() << endl;
	for (pii e : ans) {
		cout << e.first << ' ' << e.second << endl;
	}
	
}