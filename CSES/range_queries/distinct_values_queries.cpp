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

// https://cses.fi/problemset/task/1734
// fenwick tree + sort queries by right boundary
const int mxn = 2e5;
int n, q;
int a[mxn], bit[mxn + 1];
vector<pii> query[mxn];
unordered_map<int, int> mp;

void upd(int idx, int val) {
	for (++idx; idx <= n; idx += idx & -idx) {
		bit[idx] += val;
	}
}

int qry(int idx) {
	int ans = 0;
	for (++idx; idx; idx -= idx & -idx) {
		ans += bit[idx];
	}
	return ans;
}

void solve() {
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < q; i++) {
		int l, r;
		cin >> l >> r; --l; --r;
		query[r].push_back({ l, i });
	}

	mp.reserve(mxn);

	int cnt = 0;
	vector<int> ans(q);
	for (int i = 0; i < n; i++) {
		int x = a[i];
		if (mp.find(x) == mp.end()) {
			cnt++;
		}
		else {
			upd(mp[x], -1);
		}
		mp[x] = i;
		for (pii p : query[i]) {
			ans[p.second] = cnt - p.first - qry(p.first - 1);
		}
	}

	for (int i = 0; i < q; i++) {
		cout << ans[i] << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}