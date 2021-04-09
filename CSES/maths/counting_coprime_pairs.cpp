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

// https://cses.fi/problemset/task/2417/
const int mxn = 1e5;
const int mxa = 1e6;
const int mod = 1e9 + 7;

int a[mxn], c[mxa + 1], f[mxa + 1];

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
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		c[a[i]]++;
	}

	f[1] = n;

	for (int i = 2; i <= mxa; i++) {
		for (int j = i; j <= mxa; j += i) {
			f[i] += c[j];
		}
	}

	ll ans = 0;
	for (int i = 0; i < n; i++) {
		ans += n;
		if (a[i] == 1) {
			ans--;
		}
		
		vector<int> factors;
		for (int j = 2; j * j <= a[i]; j++) {
			bool ok = false;
			while (a[i] % j == 0) {
				ok = true;
				a[i] /= j;
			}
			if (ok) {
				factors.push_back(j);
			}
		}
		if (a[i] > 1) {
			factors.push_back(a[i]);
		}
		
		for (int j = 1; j < 1 << factors.size(); j++) {
			int x = 0, y = 1;
			for (int k = 0; k < factors.size(); k++) {
				if (j >> k & 1) {
					y *= factors[k];
					x++;
				}
			}
			if (x % 2) {
				ans -= f[y];
			}
			else {
				ans += f[y];
			}
		}
	}
	cout << ans / 2 << endl;
}