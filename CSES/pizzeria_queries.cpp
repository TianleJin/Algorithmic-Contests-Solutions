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

// two segment tree with arithmetic default values
const int mxn = 2e5;
const int inf = 1e9;
int n, m;
int a[mxn], b[mxn];
int st1[mxn << 2], st2[mxn << 2];

void build(int st[], int ar[], int idx = 1, int l = 0, int r = n) {
	if (r - l < 2) {
		st[idx] = ar[l] + l;
		return;
	}

	int mid = (l + r) / 2;
	build(st, ar, 2 * idx, l, mid);
	build(st, ar, 2 * idx + 1, mid, r);
	st[idx] = min(st[2 * idx], st[2 * idx + 1]);
}

void update(int st[], int x, int val, int idx = 1, int l = 0, int r = n) {
	if (r - l < 2) {
		st[idx] = val + l;
		return;
	}

	int mid = (l + r) / 2;
	if (x < mid) {
		update(st, x, val, 2 * idx, l, mid);
	}
	else {
		update(st, x, val, 2 * idx + 1, mid, r);
	}
	st[idx] = min(st[2 * idx], st[2 * idx + 1]);
}

int query(int st[], int x, int y, int idx = 1, int l = 0, int r = n) {
	if (x >= r || l >= y) return inf;
	if (x <= l && r <= y) {
		return st[idx];
	}
	int mid = (l + r) / 2;
	return min(query(st, x, y, 2 * idx, l, mid), query(st, x, y, 2 * idx + 1, mid, r));
}

void solve() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[n - i - 1] = a[i];
	}
	build(st1, a);
	build(st2, b);
	for (int i = 0; i < m; i++) {
		int t;
		cin >> t;
		if (t == 1) {
			int k, x;
			cin >> k >> x; --k;
			update(st1, k, x);
			update(st2, n - k - 1, x);
		}
		else {
			int k;
			cin >> k; --k;
			int ans1 = query(st1, k, n);
			int ans2 = query(st2, n - k - 1, n);
			cout << min(ans1 - k, ans2 - (n - k - 1)) << endl;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	// cout.precision(25);
	solve();
}