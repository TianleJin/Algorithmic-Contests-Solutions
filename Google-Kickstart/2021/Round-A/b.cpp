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
typedef vector<int> vi;
typedef pair<int, int> pii;

// dp
const int mxn = 1005;
int r, c;
int grid[mxn][mxn];
int top[mxn][mxn], bot[mxn][mxn], lft[mxn][mxn], rgt[mxn][mxn];

int get(int x, int y) {
	if (x < 2 || y < 2) return 0;
	return min(x / 2 - 1, y - 1);
}

int solve() {
	memset(top, 0, sizeof(top));
	memset(bot, 0, sizeof(bot));
	memset(lft, 0, sizeof(lft));
	memset(rgt, 0, sizeof(rgt));

	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> grid[i][j];
		}
	}

	for (int i = 0; i < r; i++) {
		lft[i][0] = grid[i][0];
		for (int j = 1; j < c; j++) {
			if (!grid[i][j]) {
				lft[i][j] = 0;
			}
			else {
				lft[i][j] = lft[i][j - 1] + grid[i][j];
			}
		}

		rgt[i][c - 1] = grid[i][c - 1];
		for (int j = c - 2; j >= 0; j--) {
			if (!grid[i][j]) {
				rgt[i][j] = 0;
			}
			else {
				rgt[i][j] = rgt[i][j + 1] + grid[i][j];
			}
		}
	}

	for (int j = 0; j < c; j++) {
		top[0][j] = grid[0][j];
		for (int i = 1; i < r; i++) {
			if (!grid[i][j]) {
				top[i][j] = 0;
			}
			else {
				top[i][j] = top[i - 1][j] + grid[i][j];
			}
		}

		bot[r - 1][j] = grid[r - 1][j];
		for (int i = r - 2; i >= 0; i--) {
			if (!grid[i][j]) {
				bot[i][j] = 0;
			}
			else {
				bot[i][j] = bot[i + 1][j] + grid[i][j];
			}
		}
	}

	ll ans = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			ans += get(top[i][j], lft[i][j]);
			ans += get(lft[i][j], top[i][j]);
			ans += get(bot[i][j], lft[i][j]);
			ans += get(lft[i][j], bot[i][j]);
			ans += get(bot[i][j], rgt[i][j]);
			ans += get(rgt[i][j], bot[i][j]);
			ans += get(top[i][j], rgt[i][j]);
			ans += get(rgt[i][j], top[i][j]);
		}
	}
	return ans;
}
	
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(25);
	
	int T;
	cin >> T;
	for (int tt = 1; tt <= T; tt++) {
		cout << "Case #" << tt << ": " << solve() << endl;
	}
}