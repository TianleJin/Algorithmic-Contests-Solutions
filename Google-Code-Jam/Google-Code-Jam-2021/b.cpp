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
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<vector<ll>> vvll;
typedef vector<vector<int>> vvi;
typedef vector<vector<bool>> vvb;
typedef pair<int, int> pii;

const int dx4[] = { -1, 0, 1, 0 };
const int dy4[] = { 0, -1, 0, 1 };
const int dx8[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
const int dy8[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

const ll INF = 1e9;
ll solve() {
	int x, y;
	string s;
	cin >> x >> y >> s;
	int ans = 0;
	int n = s.size();
	vll dp1(n, -INF), dp2(n, -INF);
	if (s[0] != 'C') {
		dp1[0] = 0;
	}
	if (s[0] != 'J') {
		dp2[0] = 0;
	}
	for (int i = 0; i + 1 < n; i++) {
		if (s[i + 1] != 'C') {
			dp1[i + 1] = max(dp1[i], dp2[i] - x);
		}
		if (s[i + 1] != 'J') {
			dp2[i + 1] = max(dp2[i], dp1[i] - y);
		}
	}
	return -max(dp1[n - 1], dp2[n - 1]);
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