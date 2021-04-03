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

// https://cses.fi/problemset/task/1195
// dijkstra
const int mxn = 100005;
const ll inf = 1e15;

struct Node {
	int u;
	int l;
	ll d;
	Node(int _u, int _l, ll _d) : u(_u), l(_l), d(_d) {}
	bool operator<(const Node& node) const 
	{
		return d > node.d;
	}
};

int n, m;
vector<pii> graph[mxn];
ll dist[2][mxn];
bool vis[2][mxn];

void solve() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		graph[u].push_back({ v, c });
	}

	for (int i = 2; i <= n; i++) {
		dist[0][i] = inf;
		dist[1][i] = inf;
	}

	priority_queue<Node> pq;
	pq.push(Node(1, 0, 0));

	while (!pq.empty()) {
		Node node = pq.top();
		int u = node.u;
		int l = node.l;
		ll d = node.d;
		pq.pop();

		if (vis[l][u]) continue;
		vis[l][u] = true;
		dist[l][u] = d;

		for (pii e : graph[u]) {
			int v = e.first, c = e.second; 
			if (l == 0 && dist[l + 1][v] > d + c / 2) {
				dist[l + 1][v] = d + c / 2;
				pq.push(Node(v, l + 1, d + c / 2));
			}
			if (dist[l][v] > d + c) {
				dist[l][v] = d + c;
				pq.push(Node(v, l, d + c));
			}
		}
	}
	cout << dist[1][n] << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}