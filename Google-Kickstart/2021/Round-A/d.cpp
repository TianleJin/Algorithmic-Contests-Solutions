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
typedef vector<int> vi;
typedef pair<int, int> pii;

// Kruskal's algorithm
struct Edge {
	int r;
	int c;
	int cost;
	Edge(int _r, int _c, int _cost) : r(_r), c(_c), cost(_cost) {}
	bool operator<(const Edge& cell) const {
		return cost > cell.cost;
	}
};

const int mxn = 500;
int grid[mxn][mxn], cost[mxn][mxn], row[mxn], col[mxn], par[mxn << 1];

int find(int u) {
	if (par[u] < 0) return u;
	return par[u] = find(par[u]);
}

bool unite(int u, int v) {
	int x = find(u);
	int y = find(v);
	if (x == y) {
		return false;
	}
	if (par[x] < par[y]) {
		par[x] += par[y];
		par[y] = x;
	}
	else {
		par[y] += par[x];
		par[x] = y;
	}
	return true;
}

int solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> cost[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		cin >> row[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> col[i];
	}

	for (int i = 0; i < n << 1; i++) {
		par[i] = -1;
	}

	int total = 0;

	vector<Edge> edges;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (grid[i][j] == -1) {
				edges.push_back(Edge(i, j, cost[i][j]));
				total += cost[i][j];
			}
		}
	}

	int keep = 0;
	sort(edges.begin(), edges.end());
	for (Edge edge : edges) {
		if (unite(edge.r, edge.c + n)) {
			keep += edge.cost;
		}
	}
	return total - keep;
}
	
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(25);
	
	int T;
	cin >> T;
	for (int tt = 1; tt <= T; tt++) {
		cout << "Case #" << tt << ": " << solve() << endl;
	}
}