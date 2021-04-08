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
const int mxn = 1e6;
int exp(int x, int n, int mod) {
	if (n == 0) return 1;
	if (n == 1) return x;
	ll ans = exp(x, n >> 1, mod);
	ans *= ans;
	ans %= mod;
	if (n & 1) {
		ans *= x;
		ans %= mod;
	}
	return ans;
}

int a[mxn + 1];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a[x]++;
	}
	for (int i = mxn; i; i--) {
		int cnt = 0;
		for (int j = i; j <= mxn; j += i) {
			cnt += a[j];
		}
		if (cnt > 1) {
			cout << i << endl;
			return 0;
		}
	}
}