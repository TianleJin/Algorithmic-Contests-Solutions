#include <iostream>
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

const int dx4[] = { -1, 0, 1, 0 };
const int dy4[] = { 0, -1, 0, 1 };
const int dx8[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
const int dy8[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

const int mxn = 2e5;
const int mxl = 31;
const int mod = 1e9 + 7;
const ll inf = 1e18;

// https://cses.fi/problemset/task/1750
int n, q;
int par[mxl][mxn + 1];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> par[0][i];
	}

	for (int i = 1; i < mxl; i++) {
		for (int u = 1; u <= n; u++) {
			par[i][u] = par[i - 1][par[i - 1][u]];
		}
	}

	for (int i = 0; i < q; i++) {
		int x, k;
		cin >> x >> k;
		for (int l = mxl - 1; l >= 0; --l) {
			if (k >= 1 << l) {
				x = par[l][x];
				k -= 1 << l;
			}
		}
		cout << x << endl;
	}
}