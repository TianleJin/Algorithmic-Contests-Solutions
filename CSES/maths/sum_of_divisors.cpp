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

// https://cses.fi/problemset/task/1082/
const ll mod = 1e9 + 7;
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

ll arithmetic(ll start, ll end) {
	ll a = (start + end) % mod;
	ll b = (end - start + 1) % mod;
	ll c = exp(2, mod - 2) % mod;
	return a * b % mod * c % mod;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n;
	cin >> n;

	ll ans = 0;
	ll m = 1;
	ll i = n;
	while (i > 1 && i > n / (m + 1)) {
		ans = (ans + m % mod * arithmetic(n / (m + 1) + 1, i) % mod) % mod;
		i = n / (m + 1);
		m++;
	}
	while (i > 0) {
		ans = (ans + n / i * i % mod) % mod;
		i--;
	}
	cout << ans << endl;
}