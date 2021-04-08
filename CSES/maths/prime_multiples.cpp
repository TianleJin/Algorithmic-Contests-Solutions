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

// https://cses.fi/problemset/task/2185/
// inclusion-exclusion principle

const int mxn = 20;
const int mod = 1e9 + 7;

ll exp(ll x, ll n) {
	x = x % mod;
	ll ans = 1;
	while (n) {
		if (n & 1) {
			ans = (ans * x) % mod;
		}
		ans = (ans * ans) % mod;
		n >>= 1;
	}
	return ans;
}

ll a[mxn];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n; int k;
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		cin >> a[i];
	}
	ll ans = 0;
	for (int i = 1; i < 1 << k; i++) {
		ll cnt = 0, sum = n;
		for (int j = 0; j < k; j++) {
			if (i >> j & 1) {
				sum /= a[j];
				cnt++;
			}
		}
		if (cnt % 2) {
			ans += sum;
		}
		else {
			ans -= sum;
		}
	}
	cout << ans << endl;
}