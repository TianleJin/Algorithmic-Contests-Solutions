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

int n;
void reverse(vector<int>& a, int l, int r) {
	while (l < r) {
		swap(a[l++], a[r--]);
	}
}

ll solve() {
	cin >> n;
	vi a(n), s(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		s[i] = a[i];
	}
	ll ans = 0;
	sort(s.begin(), s.end());
	for (int i = 0; i < n - 1; i++) {
		int j = -1;
		for (j = i; j < n; j++) {
			if (a[j] == s[i]) break;
		}
		assert(j >= i);
		ans += 1LL + j - i;
		reverse(a, i, j);
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