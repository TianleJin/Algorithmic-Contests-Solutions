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

const int mxn = 100;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	vector<vector<double>> dp(n + 1, vector<double>(mxn + 1));
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	double ans = 0;
	for (int i = n - 1; ~i; --i) {
		for (int j = 1; j <= mxn; j++) {
			dp[i][j] = dp[i][j] + dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1];
			if (j <= a[i]) {
				dp[i][j] += 1.0 / a[i];
				ans += dp[i + 1][j - 1] / a[i];
			}
		}
	}
	cout << setprecision(6) << fixed << ans << endl;
}