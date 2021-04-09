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

const int mxn = 2e3;
const int mod = 1e9 + 7;

int n, k;
ll dp[mxn][mxn][2];
ll recur(int i, int j, int d) {
	if (dp[i][j][d] != -1) return dp[i][j][d];
	if (i == 0 && d == 1) return dp[i][j][d] = 1;
	if (i == n && d == 0) return dp[i][j][d] = 1;
	if (j == 1) return dp[i][j][d] = 1;

	if (d == 0) {
		dp[i][j][d] = (recur(i + 1, j, d) + recur(i, j - 1, d ^ 1)) % mod;
	}
	else {
		dp[i][j][d] = (recur(i - 1, j, d) + recur(i, j - 1, d ^ 1)) % mod;
	}
	return dp[i][j][d];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--) {
		memset(dp, -1, sizeof(dp));
		cin >> n >> k;
		recur(0, k, 0);
		cout << dp[0][k][0] << endl;
	}
}