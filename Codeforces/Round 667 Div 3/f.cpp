#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <array>
#include <map>
#include <set>
#include <string>
#include <deque>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <assert.h>
#include <sstream>
typedef long long ll;
#define vi vector<int>
using namespace std;


int n, k;
string s, t;
int dp[205][205][205];
int helper(int i, int j, int k) {
	if (i == n) return 0;
	if (dp[i][j][k] != -1) return dp[i][j][k];
	if (s[i] == t[0]) {
		dp[i][j][k] = max(dp[i][j][k], helper(i + 1, j + 1, k) + (t[0] == t[1] ? j : 0));
		if (k > 0 && t[0] != t[1]) {
			dp[i][j][k] = max(dp[i][j][k], helper(i + 1, j, k - 1) + j);
		}
	}
	else if (s[i] == t[1]) {
		dp[i][j][k] = max(dp[i][j][k], helper(i + 1, j, k) + j);
		if (k > 0) {
			dp[i][j][k] = max(dp[i][j][k], helper(i + 1, j + 1, k - 1));
		}
	}
	else {
		dp[i][j][k] = max(dp[i][j][k], helper(i + 1, j, k));
		if (k > 0) {
			dp[i][j][k] = max(dp[i][j][k], helper(i + 1, j + 1, k - 1) + (t[0] == t[1] ? j : 0));
			dp[i][j][k] = max(dp[i][j][k], helper(i + 1, j + (t[0] == t[1] ? 1 : 0), k - 1) + j);
		}
	}
	return dp[i][j][k];
}

int main() {
	cin >> n >> k;
	memset(dp, -1, sizeof dp);
	cin >> s;
	cin >> t;
	cout << helper(0, 0, k) << '\n';
}