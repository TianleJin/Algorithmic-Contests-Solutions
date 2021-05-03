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

const ll inf = 1e15;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a.begin(), a.end());
	
	vector<vector<ll>> dp(n, vector<ll>(n, inf));
	for (int i = 0; i < n; i++) {
		dp[i][i] = 0;
	}

	for (int sz = 2; sz <= n; sz++) {
		for (int i = 0; i + sz <= n; i++) {
			int j = i + sz - 1;
			dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + a[j] - a[i];
		}
	}
	cout << dp[0][n - 1] << endl;
}