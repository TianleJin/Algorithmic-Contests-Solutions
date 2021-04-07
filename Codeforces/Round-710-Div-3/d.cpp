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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		unordered_map<int, int> cnt;
		cnt.reserve(n);
		for (int i = 0; i < n; i++) {
			int a;
			cin >> a;
			cnt[a]++;
		}
		
		int mx = 0;
		int tt = 0;
		for (auto it = cnt.begin(); it != cnt.end(); it++) {
			tt += it->second;
			mx = max(mx, it->second);
		}

		int ans;
		if (tt >= 2 * mx) {
			ans = n & 1;
		}
		else {
			ans = 2 * mx - tt;
		}
		cout << ans << endl;
	}
}