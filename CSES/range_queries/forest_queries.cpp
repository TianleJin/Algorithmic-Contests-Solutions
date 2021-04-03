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
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<vector<ll>> vvll;
typedef vector<vector<int>> vvi;
typedef vector<vector<bool>> vvb;
typedef pair<int, int> pii;

const int dx4[] = { -1, 0, 1, 0 };
const int dy4[] = { 0, -1, 0, 1 };
const int dx8[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
const int dy8[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

// https://cses.fi/problemset/task/1739
// 2D segment tree
const int mxn = 1000;
int n, q;
int grid[mxn][mxn];
int xst[mxn][mxn << 2], yst[mxn << 2][mxn << 2];

void xbuild(int node, int row, int idx = 1, int l = 0, int r = n) {
	if (r - l < 2) {
		yst[node][idx] = grid[row][l];
		return;
	}
	int mid = (l + r) / 2;
	xbuild(node, row, idx << 1, l, mid);
	xbuild(node, row, idx << 1 | 1, mid, r);
	yst[node][idx] = yst[node][idx << 1] + yst[node][idx << 1 | 1];
}

void ybuild(int idx = 1, int l = 0, int r = n) {
	if (r - l < 2) {
		xbuild(idx, l);
        return;
	}
	int mid = (l + r) / 2;
	ybuild(idx << 1, l, mid);
	ybuild(idx << 1 | 1, mid, r);
	for (int i = 0; i < 4 * n; i++) {
		yst[idx][i] = yst[idx << 1][i] + yst[idx << 1 | 1][i];
	}
}

void xupdate(int node, int x, int idx = 1, int l = 0, int r = n) {
	if (r - l < 2) {
		yst[node][idx] ^= 1;
		return;
	}
	int mid = (l + r) / 2;
	if (x < mid) {
		xupdate(node, x, idx << 1, l, mid);
	}
	else {
		xupdate(node, x, idx << 1 | 1, mid, r);
	}
	yst[node][idx] = yst[node][idx << 1] + yst[node][idx << 1 | 1];
}

void yupdate(int x, int y, int idx = 1, int l = 0, int r = n) {
	if (r - l < 2) {
		xupdate(idx, x);
		return;
	}
	int mid = (l + r) / 2;
	if (y < mid) {
		yupdate(x, y, idx << 1, l, mid);
	}
	else {
		yupdate(x, y, idx << 1 | 1, mid, r);
	}
	for (int i = 0; i < 4 * n; i++) {
		yst[idx][i] = yst[idx << 1][i] + yst[idx << 1 | 1][i];
	}
}

int xquery(int node, int x1, int x2, int idx = 1, int l = 0, int r = n) {
	if (x1 >= r || x2 <= l) return 0;
	if (x1 <= l && x2 >= r) {
		return yst[node][idx];
	}
	int mid = (l + r) / 2;
	return xquery(node, x1, x2, idx << 1, l, mid) + xquery(node, x1, x2, idx << 1 | 1, mid, r);
}

int yquery(int y1, int y2, int x1, int x2, int idx = 1, int l = 0, int r = n) {
	if (y1 >= r || y2 <= l) return 0;
	if (y1 <= l && y2 >= r) {
		return xquery(idx, x1, x2);
	}
	int mid = (l + r) / 2;
	return yquery(y1, y2, x1, x2, idx << 1, l, mid) + yquery(y1, y2, x1, x2, idx << 1 | 1, mid, r);
}

void solve() {
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		string row;
		cin >> row;
		for (int j = 0; j < n; j++) {
			if (row[j] == '.') {
				grid[i][j] = 0;
			}
			else {
				grid[i][j] = 1;
			}
		}
	}

	ybuild();

	for (int i = 0; i < q; i++) {
		int t;
		cin >> t;
		if (t == 1) {
			int y, x;
			cin >> y >> x;
			y--;
			x--;
			yupdate(x, y);
		}
		else {
			int y1, x1, y2, x2;
			cin >> y1 >> x1 >> y2 >> x2;
			x1--;
			y1--;
			cout << yquery(y1, y2, x1, x2) << endl;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	// cout.precision(25);
	solve();
}