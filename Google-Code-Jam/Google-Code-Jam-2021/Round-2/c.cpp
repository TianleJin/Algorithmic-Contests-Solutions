#include <iostream>
#include <array>
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
typedef pair<int, int> pii;

const int mxn = 1e5;
const int mod = 1e9 + 7;
int n, ar[mxn], bit[mxn + 1], st[mxn << 1];
ll inv[mxn], fact[mxn];

void build() {
	for (int i = 0; i < n; i++) {
		st[i + n] = i;
	}
	for (int i = n - 1; i; i--) {
		st[i] = ar[st[2 * i]] < ar[st[2 * i + 1]] ? st[2 * i] : st[2 * i + 1];
	}
}

int minQuery(int l, int r) {
	int ans = l;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l & 1) {
			if (ar[st[l]] < ar[ans] || ar[st[l]] == ar[ans] && st[l] > ans) {
				ans = st[l];
			}
			l++;
		}
		if (r & 1) {
			r--;
			if (ar[st[r]] < ar[ans] || ar[st[r]] == ar[ans] && st[r] > ans) {
				ans = st[r];
			}
		}
	}
	return ans;
}

void update1(int idx, int val) {
	for (idx++; idx <= n; idx += idx & -idx) {
		bit[idx] += val;
	}
}

void update(int l, int r, int val) {
	update1(l, val);
	if (r < n - 1) {
		update1(r + 1, -val);
	}
}

int sumQuery(int idx) {
	int ans = 0;
	for (idx++; idx; idx -= idx & -idx) {
		ans += bit[idx];
	}
	return ans;
}

int ncr(int n, int r) {
	return fact[n] * inv[n - r] % mod * inv[r] % mod;
}

int exp(ll x, int n) {
	ll ans = 1;
	while (n) {
		if (n & 1) {
			ans = ans * x % mod;
		}
		x = x * x % mod;
		n >>= 1;
	}
	return ans;
}

int solve(int l, int r) {
	if (l > r) {
		return 1;
	}

	int idx = minQuery(l, r + 1);
	if (ar[idx] + sumQuery(idx) != 1) {
		return 0;
	}

	ll ans = ncr(r - l, idx - l);
	if (idx + 1 <= r) {
		update(idx + 1, r, -1);
	}
	return ans * solve(l, idx - 1) % mod * solve(idx + 1, r) % mod;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	fact[0] = 1;
	inv[0] = 1;
	for (int i = 1; i < mxn; i++) {
		fact[i] = fact[i - 1] * i % mod;
		inv[i] = inv[i - 1] * exp(i, mod - 2) % mod;
	}
	
	int T;
	cin >> T;
	for (int tt = 1; tt <= T; tt++) {
		memset(bit, 0, sizeof(bit));
		memset(st, 0, sizeof(bit));

		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
		}

		build();

		cout << "Case #" << tt << ": " << solve(0, n - 1) << endl;
	}
}