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

// https://cses.fi/problemset/task/1079/
const int mxa = 1e6;
const int mod = 1e9 + 7;

ll fact[mxa + 1], inv[mxa + 1];

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

int main() {
	fact[0] = inv[0] = 1;
	for (int i = 1; i <= mxa; i++) {
		fact[i] = fact[i - 1] * i % mod;
		inv[i] = inv[i - 1] * exp(i, mod - 2) % mod;
	}

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		cout << fact[a] * inv[b] % mod * inv[a - b] % mod << endl;
	}
}