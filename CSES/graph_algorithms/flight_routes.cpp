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

// https://cses.fi/problemset/task/1196
// dijkstra
const int mxn = 2e5;
const ll inf = 1e18;

int n, m, k;
vector<pii> graph[mxn];
int vis[mxn];
ll dp[mxn][10];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		graph[u].push_back({ v, c });
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < k; j++) {
			dp[i][j] = inf;
		}
	}

	dp[1][0] = 0;

	priority_queue<pair<ll, int>> pq;
	pq.push({ 0, 1 });
	while (!pq.empty()) {
		pair<ll, int> cur = pq.top(); pq.pop();
		ll d = -cur.first; int u = cur.second;
		if (vis[u] >= k) continue;
		dp[u][vis[u]++] = d;
		for (pii adj : graph[u]) {
			int v = adj.first, c = adj.second;
			if (vis[v] < k && dp[v][vis[v]] > d + c) {
				pq.push({ -(d + c), v });
			}
		}
	}

	for (int i = 0; i < k; i++) {
		cout << dp[n][i] << endl;
	}
}