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

// https://cses.fi/problemset/task/2166 
// segment tree with prefix sum and sum
const int mxn = 2e5;
const ll inf = 1e18;
int n, m;
int a[mxn];
ll sum[mxn << 2], pre[mxn << 2];

void build(int idx = 1, int l = 0, int r = n) {
	if (r - l < 2) {
		sum[idx] = a[l];
		pre[idx] = a[l];
		return;
	}

	int mid = (l + r) / 2;
	build(2 * idx, l, mid);
	build(2 * idx + 1, mid, r);
	sum[idx] = sum[2 * idx] + sum[2 * idx + 1];
	pre[idx] = max(pre[2 * idx], sum[2 * idx] + pre[2 * idx + 1]);
}

void update(int x, int val, int idx = 1, int l = 0, int r = n) {
	if (r - l < 2) {
		sum[idx] = val;
		pre[idx] = val;
		return;
	}

	int mid = (l + r) / 2;
	if (x < mid) {
		update(x, val, 2 * idx, l, mid);
	}
	else {
		update(x, val, 2 * idx + 1, mid, r);
	}
	sum[idx] = sum[2 * idx] + sum[2 * idx + 1];
	pre[idx] = max(pre[2 * idx], sum[2 * idx] + pre[2 * idx + 1]);
}

pair<ll, ll> query(int x, int y, int idx = 1, int l = 0, int r = n) {
	if (x >= r || l >= y) return { -inf, 0 };
	if (x <= l && r <= y) {
		return { pre[idx], sum[idx] };
	}
	int mid = (l + r) / 2;
	pair<ll, ll> ans1 = query(x, y, 2 * idx, l, mid);
	pair<ll, ll> ans2 = query(x, y, 2 * idx + 1, mid, r);
	return { max(ans1.first, ans1.second + ans2.first), ans1.second + ans2.second };
}

void solve() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	build();

	for (int i = 0; i < m; i++) {
		int t;
		cin >> t;
		if (t == 1) {
			int k, u;
			cin >> k >> u; --k;
			update(k, u);
		}
		else {
			int a, b;
			cin >> a >> b; --a;
			cout << max(0LL, query(a, b).first) << endl;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	// cout.precision(25);
	solve();
}