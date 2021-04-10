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

#define mat vector<vector<ll>>
const ll inf = 2e18;

mat get(int r, int c) {
	return mat(r, vector<ll>(c));
}

mat mult(mat a, mat b) {
	mat ans = get(a.size(), b[0].size());
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < b[0].size(); j++) {
			ans[i][j] = inf;
		}
	}

	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < b[0].size(); j++) {
			for (int k = 0; k < a[0].size(); k++) {
				ans[i][j] = min(ans[i][j], a[i][k] + b[k][j]);
			}
		}
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	mat edges(n, vector<ll>(n)), start(n, vector<ll>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			start[i][j] = edges[i][j] = inf;
		}
		start[i][i] = 0;
	}
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w; --u; --v;
		edges[u][v] = min(edges[u][v], w + 0LL);
	}
	while (k) {
		if (k & 1) {
			start = mult(start, edges);
		}
		edges = mult(edges, edges);
		k >>= 1;
	}
	if (start[0][n - 1] >= inf) {
		cout << -1 << endl;
	}
	else {
		cout << start[0][n - 1] << endl;
	}
}