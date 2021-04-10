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
const int mod = 1e9 + 7;

// https://cses.fi/problemset/task/2209/
// Polya's enumeration theorem
ll exp(ll x, ll n) {
	ll ans = 1;
	while (n) {
		if (n & 1) {
			ans *= x;
			ans %= mod;
		}
		x *= x;
		x %= mod;
		n >>= 1;
	}
	return ans;
}

ll euler_totient(ll n) {
	ll et = 1;
	for (ll i = 2; i * i <= n; i++) {
		int cnt = 0;
		while (n % i == 0) {
			n /= i;
			cnt++;
		}
		if (cnt) {
			et *= i - 1;
			et %= mod;
			while (cnt > 1) {
				et *= i;
				et %= mod;
				cnt--;
			}
		}
	}
	if (n > 1) {
		et *= n - 1;
		et %= mod;
	}
	return et;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	ll ans = 0, i;
	for (i = 1; i * i < n; i++) {
		if (n % i == 0) {
			ans += euler_totient(i) * exp(m, n / i);
			ans %= mod;
			ans += euler_totient(n / i) * exp(m, i);
			ans %= mod;
		}
	}
	if (i * i == n) {
		ans += euler_totient(i) * exp(m, i);
		ans %= mod;
	}
	cout << ans * exp(n, mod - 2) % mod << endl;
}