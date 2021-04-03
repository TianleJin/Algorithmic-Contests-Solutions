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

// https://cses.fi/problemset/task/1736
// segment tree with 2 lazy values
const int mxn = 2e5;
int n, q;
int arr[mxn];
ll tree[mxn << 2], lazy1[mxn << 2], lazy2[mxn << 2];

void build(int idx = 1, int l = 0, int r = n) {
	if (r - l < 2) {
		tree[idx] = arr[l];
		return;
	}
	int m = (l + r) / 2;
	build(idx << 1, l, m);
	build(idx << 1 | 1, m, r);
	tree[idx] = tree[idx << 1] + tree[idx << 1 | 1];
}

void apply(int idx, ll x1, ll x2, int l, int r) {
	assert(x1 == 0 || x2 == 0);
	if (x2 == 0) {
		tree[idx] += (r - l) * x1;
		if (lazy2[idx]) {
			lazy2[idx] += x1;
		}
		else {
			lazy1[idx] += x1;
		}
	}
	else {
		tree[idx] = (r - l) * x2;
		lazy2[idx] = x2;
		lazy1[idx] = 0;
	}
}

void push(int idx, int l, int r) {
	if (lazy1[idx] != 0 || lazy2[idx] != 0) {
		int m = (l + r) / 2;
		apply(idx << 1, lazy1[idx], lazy2[idx], l, m);
		apply(idx << 1 | 1, lazy1[idx], lazy2[idx], m, r);
		lazy1[idx] = 0;
		lazy2[idx] = 0;
	}
}

void update(int x, int y, int x1, int x2, int idx = 1, int l = 0, int r = n) {
	if (x >= r || y <= l) return;
	if (x <= l && r <= y) {
		apply(idx, x1, x2, l, r);
		return;
	}
	push(idx, l, r);
	int m = (l + r) / 2;
	update(x, y, x1, x2, idx << 1, l, m);
	update(x, y, x1, x2, idx << 1 | 1, m, r);
	tree[idx] = tree[idx << 1] + tree[idx << 1 | 1];
}

ll query(int x, int y, int idx = 1, int l = 0, int r = n) {
	if (x >= r || y <= l) return 0;
	if (x <= l && r <= y) {
		return tree[idx];
	}
	push(idx, l, r);
	int m = (l + r) / 2;
	return query(x, y, idx << 1, l, m) + query(x, y, idx << 1 | 1, m, r);
}

void solve() {
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	build();

	for (int i = 0; i < q; i++) {
		int t, a, b, x;
		cin >> t >> a >> b;
		a--;
		if (t == 1) {
			cin >> x;
			update(a, b, x, 0);
		}
		else if (t == 2) {
			cin >> x;
			update(a, b, 0, x);
		}
		else if (t == 3) {
			cout << query(a, b) << endl;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(25);
	solve();
}