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

const int dx4[] = { -1, 0, 1, 0 };
const int dy4[] = { 0, -1, 0, 1 };
const int dx8[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
const int dy8[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

// https://cses.fi/problemset/task/1749
// segment tree + binary search
const int mxn = 2e5;
int n, a[mxn], bit[mxn + 1];

void upd(int idx, int val) {
	for (++idx; idx <= n; idx += idx & -idx) bit[idx] += val;
}

int qry(int idx) {
	int ans = 0;
	for (++idx; idx; idx -= idx & -idx) { ans += bit[idx]; }
	return ans;
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		upd(i, 1);
	}

	vector<int> ans(n);
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		int l = 0;
		int r = n;
		while (l < r) {
			int mid = (l + r) / 2;
			if (qry(mid) >= p) {
				r = mid;
			}
			else {
				l = mid + 1;
			}
		}
		ans[i] = l;
		upd(l, -1);
	}

	for (int i : ans) {
		cout << a[i] << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}