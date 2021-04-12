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

// https://cses.fi/problemset/task/2194/
const ll inf = 8e18;
struct Point {
	ll x, y;
	bool operator<(const Point& p) const {
		if (x == p.x) {
			return y < p.y;
		}
		return x < p.x;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<Point> points(n);
	for (int i = 0; i < n; i++) {
		cin >> points[i].x >> points[i].y;
	}

	sort(points.begin(), points.end());

	set<pair<ll, ll>> st;
	ll ans = inf;
	int l = 0;
	for (int r = 0; r < n; r++) {
		ll lb = points[r].x - sqrt(ans);
		while (l < r && points[l].x <= lb) {
			st.erase(st.find({ points[l].y, points[l].x }));
			l++;
		}
		ll lo = points[r].y - sqrt(ans);
		ll hi = points[r].y + sqrt(ans);
		auto it1 = st.upper_bound({ lo, -inf });
		auto it2 = st.upper_bound({ hi, -inf });
		while (it1 != it2) {
			ll dx = (points[r].y - it1->first) * (points[r].y - it1->first);
			ll dy = (points[r].x - it1->second) * (points[r].x - it1->second);
			ans = min(ans, dx + dy);
			it1++;
		}
		st.insert({ points[r].y, points[r].x });
	}
	cout << ans << endl;
}