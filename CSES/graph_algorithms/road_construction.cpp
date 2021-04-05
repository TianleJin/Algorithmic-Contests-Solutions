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

// https://cses.fi/problemset/task/1676/
// union find
const int mxn = 2e5;
int n, m;
int components = 0, largest = 1;
int par[mxn + 1];

int find(int v) {
	if (par[v] < 0) return v;
	return par[v] = find(par[v]);
}

bool unite(int u, int v) {
	int x = find(u), y = find(v);
	if (x == y) {
		return false;
	}
	if (par[x] < par[y]) {
		par[x] += par[y];
		par[y] = x;
		largest = max(largest, -par[x]);
	}
	else {
		par[y] += par[x];
		par[x] = y;
		largest = max(largest, -par[y]);
	}
	components--;
	assert(components >= 1);
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		par[i] = -1;
	}

	components = n;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		unite(u, v);
		cout << components << ' ' << largest << endl;
	}

}