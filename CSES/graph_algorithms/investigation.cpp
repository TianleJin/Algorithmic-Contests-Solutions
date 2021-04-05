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

// https://cses.fi/problemset/task/1202/
// dijkstra
const int mxn = 2e5;
const ll inf = 1e18;
const int mod = 1e9 + 7;

int n, m;
vector<pii> graph[mxn];
ll dist[mxn];
int way[mxn], lng[mxn], sht[mxn];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		graph[u].push_back({ v, c });
	}
	
    way[1] = 1;
	lng[1] = 0;
	sht[1] = 0;
	dist[1] = 0;
	
    for (int i = 2; i <= n; i++) {
		way[i] = 0;
		lng[i] = 0;
		sht[i] = n;
		dist[i] = inf;
	}
	
	priority_queue<pair<ll, int>> pq;
	pq.push({ 0, 1 });
	while (!pq.empty()) {
		pair<ll, int> cur = pq.top(); pq.pop();
		ll d = -cur.first; int u = cur.second;
		if (d > dist[u]) continue;
		assert(d == dist[u]);
		for (pii e : graph[u]) {
			int v = e.first, c = e.second;
			if (dist[v] == d + c) {
				way[v] = (0LL + way[v] + way[u]) % mod;
				lng[v] = max(lng[v], lng[u] + 1);
				sht[v] = min(sht[v], sht[u] + 1);
			}
			if (dist[v] > d + c) {
				dist[v] = d + c;
				way[v] = way[u];
				lng[v] = lng[u] + 1;
				sht[v] = sht[u] + 1;
				pq.push({ -dist[v], v });
			}
		}
	}
	cout << dist[n] << ' ' << way[n] << ' ' << sht[n] << ' ' << lng[n] << endl;
}