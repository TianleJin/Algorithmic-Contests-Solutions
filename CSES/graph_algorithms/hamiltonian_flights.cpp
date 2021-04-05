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

// https://cses.fi/problemset/task/1690/
// travelling salesperson
const int mxn = 20;
const int mod = 1e9 + 7;
int l, n, m;
int dp[1 << mxn][mxn];
vector<int> graph[mxn];

int helper(int msk, int last) {
	if (dp[msk][last] != -1) return dp[msk][last];
	if (msk == 1) return 1;

	dp[msk][last] = 0;
	for (int i : graph[last]) {
		if (i != last && msk >> i & 1) {
			dp[msk][last] = (0LL + dp[msk][last] + helper(msk ^ 1 << last, i)) % mod;
		}
	}
	return dp[msk][last];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m; l = 1 << n;

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v; --u; --v;
		graph[v].push_back(u);
	}

	for (int i = 0; i < l; i++) {
		for (int j = 0; j < n; j++) {
			dp[i][j] = -1;
		}
	}

	cout << helper(l - 1, n - 1) << endl;
}