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

// https://cses.fi/problemset/task/2182/
const ll mod = 1e9 + 7;
const int mxn = 1e5;
ll exp(ll x, ll n) {
	if (n == 0) return 1;
	if (n == 1) return x;
	ll ans = exp(x, n >> 1);
	ans *= ans;
	ans %= mod;
	if (n & 1) {
		ans *= x;
		ans %= mod;
	}
	return ans;
}

ll geometric(ll x, ll n) {
	return (exp(x, n + 1) + mod - 1) % mod * exp(x - 1, mod - 2) % mod;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	ll count = 1, sum = 1, product = 1;
	vector<ll> A(n), B(n);
	for (int i = 0; i < n; i++) {
		cin >> A[i] >> B[i];
	}

	for (int i = 0; i < n; i++) {
		count = count * (B[i] + 1) % mod;
	}

	for (int i = 0; i < n; i++) {
		sum = sum * geometric(A[i], B[i]) % mod;
	}

	bool f = false;
	ll c = 1, p = 1;
	for (int i = 0; i < n; i++) {
		ll x = B[i] + 1;
		if (x % 2 == 0) {
			if (f) {
				c = c * 2 % (mod - 1);
			}
			p = x / 2 * p % (mod - 1);
			f = true;
		}
		else {
			p = x * p % (mod - 1);
		}
	}

	for (int i = 0; i < n; i++) {
		ll y;
		if (f) {
			y = B[i] * p % (mod - 1) * c % (mod - 1);
		}
		else {
			y = B[i] / 2 * p % (mod - 1) * c % (mod - 1);
		}
		product = product * exp(A[i], y) % mod;
	}
	cout << count << ' ' << sum << ' ' << product << endl;
}