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
#include <iomanip>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int dx4[] = { -1, 0, 1, 0 };
const int dy4[] = { 0, -1, 0, 1 };
const int dx8[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
const int dy8[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

const ll inf = 1e12;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<ll> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		if (n == 1) {
			cout << 0 << endl;
			continue;
		}

		bool ok = true;
		ll f = -inf;
		ll s = -inf;
		for (int i = 0; i + 1 < n; i++) {
			ll x = a[i + 1] - a[i];
			if (x == f || x == s) {
				continue;
			}
			if (x != f && f == -inf) {
				f = x;
				continue;
			}
			if (x != s && s == -inf) {
				s = x;
				continue;
			}
			ok = false;
		}

		if (!ok) {
			cout << -1 << endl;
			continue;
		}

		if (s == -inf) {
			cout << 0 << endl;
			continue;
		}

		if (f * s >= 0) {
			cout << -1 << endl;
			continue;
		}

		ll m = abs(f - s);
		ll c = (m + f) % m;
		for (int i = 0; i < n; i++) {
			if (a[i] > m) {
				ok = false;
			}
		}

		if (!ok) {
			cout << -1 << endl;
			continue;
		}

		cout << m << ' ' << c << endl;
	}
}