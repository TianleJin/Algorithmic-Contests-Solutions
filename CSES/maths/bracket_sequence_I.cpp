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

// https://cses.fi/problemset/task/2064/
const int mxa = 2e6;
const int mod = 1e9 + 7;

ll fact[mxa + 1], invf[mxa + 1];

ll exp(ll x, ll n) {
	x = x % mod;
	ll ans = 1;
	while (n) {
		if (n & 1) {
			ans = (ans * x) % mod;
		}
		x = (x * x) % mod;
		n >>= 1;
	}
	return ans;
}

ll ncr(int n, int r) {
    return fact[n] * invf[r] % mod * invf[n - r] % mod;
}

void build(int n) {
	fact[0] = invf[0] = 1;
	for (int i = 1; i <= n; i++) {
		fact[i] = fact[i - 1] * i % mod;
		invf[i] = invf[i - 1] * exp(i, mod - 2) % mod;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n;
	cin >> n;
	if (n & 1) {
		cout << 0 << endl;
		return 0;
	}
	build(n);
	cout << ncr(n, n / 2) * exp(n / 2 + 1, mod - 2) % mod << endl;
}