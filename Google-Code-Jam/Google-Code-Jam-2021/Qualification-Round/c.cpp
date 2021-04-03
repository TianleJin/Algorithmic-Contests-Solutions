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
typedef vector<bool> vb;
typedef vector<vector<int>> vvi;
typedef vector<vector<bool>> vvb;
typedef pair<int, int> pii;

const int dx4[] = { -1, 0, 1, 0 };
const int dy4[] = { 0, -1, 0, 1 };
const int dx8[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
const int dy8[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

void _reverse(vi& a, int l, int r) {
	while (l < r) {
		swap(a[l++], a[r--]);
	}
}

void check(vi a, int n, int C) {
	vi s(n);
	for (int i = 0; i < n; i++) {
		s[i] = a[i];
	}
	int ans = 0;
	sort(s.begin(), s.end());
	for (int i = 0; i < n - 1; i++) {
		int j = -1;
		for (j = i; j < n; j++) {
			if (a[j] == s[i]) break;
		}
		assert(j >= i);
		ans += j - i + 1;
		_reverse(a, i, j);
	}
	assert(ans == C);
}


void solve(int tt) {
	int n, c;
	cin >> n >> c;
	if (c > n * (n + 1) / 2 - 1 || c < n - 1) {
		cout << "Case #" << tt << ": IMPOSSIBLE" << endl;
		return;
	}

	vi nums;
	for (int i = 0; i < n - 1; i++) {
		nums.push_back(n - i - 1);
	}
	
	int t = c - n + 1;
	vvb dp(n, vb(t + 1));
	dp[0][0] = 1;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j <= t; j++) {
			if (dp[i][j]) {
				dp[i + 1][j] = 1;
			}
		}
		for (int j = t - nums[i]; j >= 0; j--) {
			if (dp[i][j]) {
				dp[i + 1][j + nums[i]] = 1;
			}
		}
 	}
	
	if (!dp[n - 1][t]) {
		cout << "Case #" << tt << ": IMPOSSIBLE" << endl;
		return;
	}

	vi index;
	int pos = t;
	int idx = n - 1;
	while (pos > 0) {
		if (pos - nums[idx - 1] >= 0 && dp[idx - 1][pos - nums[idx - 1]]) {
			index.push_back(idx - 1);
			pos -= nums[idx - 1];
		}
		idx--;
	}
	
	vi ans(n);
	for (int i = 0; i < n; i++) {
		ans[i] = i + 1;
	}

	for (int idx : index) {
		int h = n - 1;
		while (idx < h) {
			swap(ans[idx++], ans[h--]);
		}
	}

	cout << "Case #" << tt << ": ";
	for (int i = 0; i < n; i++) {
		cout << ans[i] << ' ';
	}
	cout << endl;
	
	// check(ans, n, c);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(25);
	
	int T;
	cin >> T;
	for (int tt = 1; tt <= T; tt++) {
		solve(tt);
	}
}