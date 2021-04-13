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
 
const int mod = 1e9 + 7;
const int mxn = 1e3 + 7;
const int mxm = 1e2 + 7;
 
int n, m, lps[mxm];
ll mlt[mxn], dp[mxn][mxm];
string s;
 
void build() {
	int l = 0;
	for (int i = 1; i < m; i++) {
		while (l && s[i] != s[l]) {
			l = lps[l - 1];
		}
		if (s[i] == s[l]) {
			l++;
		}
		lps[i] = l;
	}
}
 
ll dfs(int i, int j) {
	if (dp[i][j] != -1) {
		return dp[i][j];
	}
	if (j == m) {
		return dp[i][j] = mlt[n - i];
	}
	if (i == n) {
		return dp[i][j] = 0;
	}
	ll ans = 0;
	for (int c = 0; c < 26; c++) {
		int k = j;
		while (k && c + 'A' != s[k]) {
			k = lps[k - 1];
		}
		if (c + 'A' == s[k]) {
			k++;
		}
		ans = (ans + dfs(i + 1, k)) % mod;
	}
	return dp[i][j] = ans;
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	cin >> s;
	m = s.size();
	
	mlt[0] = 1;
	for (int i = 0; i + 1 < n; i++) {
		mlt[i + 1] = (mlt[i] * 26) % mod;
	}
 
	build();
	memset(dp, -1, sizeof(dp));
	cout << dfs(0, 0);
}