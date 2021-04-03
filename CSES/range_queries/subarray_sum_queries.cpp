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
 
// https://cses.fi/problemset/task/1190
// lazy propagation
const int mxn = 2e5;
const ll inf = 1e18;
int n, m;
int a[mxn];
struct Node {
	ll sum;
	ll pre;
	ll suf;
	ll sub;
} st[mxn << 2];
 
void apply(int idx, int val) {
	st[idx].sum = val;
	st[idx].pre = val;
	st[idx].suf = val;
	st[idx].sub = val;
}
 
void pull(int idx) {
	int lc = 2 * idx;
	int rc = 2 * idx + 1;
	st[idx].sum = st[lc].sum + st[rc].sum;
	st[idx].pre = max(st[lc].pre, st[lc].sum + st[rc].pre);
	st[idx].suf = max(st[rc].suf, st[rc].sum + st[lc].suf);
	st[idx].sub = max(st[lc].suf + st[rc].pre, max(st[lc].sub, st[rc].sub));
}
 
void build(int idx = 1, int l = 0, int r = n) {
	if (r - l < 2) {
		apply(idx, a[l]);
		return;
	}
 
	int mid = (l + r) / 2;
	build(2 * idx, l, mid);
	build(2 * idx + 1, mid, r);
	pull(idx);
}
 
void update(int x, int val, int idx = 1, int l = 0, int r = n) {
	if (r - l < 2) {
		apply(idx, val);
		return;
	}
 
	int mid = (l + r) / 2;
	if (x < mid) {
		update(x, val, 2 * idx, l, mid);
	}
	else {
		update(x, val, 2 * idx + 1, mid, r);
	}
	pull(idx);
}
 
vector<ll> query(int x, int y, int idx = 1, int l = 0, int r = n) {
	if (x >= r || l >= y) return { -inf, -inf, -inf, 0 };
	if (x <= l && r <= y) {
		return { st[idx].sub, st[idx].pre, st[idx].suf, st[idx].sum };
	}
	int mid = (l + r) / 2;
	vector<ll> ans1 = query(x, y, 2 * idx, l, mid);
	vector<ll> ans2 = query(x, y, 2 * idx + 1, mid, r);
	vector<ll> ans3(4);
	ans3[0] = max(ans1[2] + ans2[1], max(ans1[0], ans2[0]));
	ans3[1] = max(ans1[1], ans1[3] + ans2[1]);
	ans3[2] = max(ans2[2], ans2[3] + ans1[2]);
	ans3[3] = ans1[3] + ans2[3];
	return ans3;
}
 
void solve() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
 
	build();
 
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b; --a;
		update(a, b);
		cout << max(0LL, query(0, n)[0]) << endl;
	}
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	// cout.precision(25);
	solve();
}