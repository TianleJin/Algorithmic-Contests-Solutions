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

// https://cses.fi/problemset/task/2191/
struct Point {
	ll x, y;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T = 1;
	while (T--) {
		int n;
		cin >> n;
		vector<Point> points(n);
		for (int i = 0; i < n; i++) {
			int x, y;
			cin >> x >> y;
			points[i] = { x, y };
		}
		
		auto orientation = [](Point p1, Point p2, Point p3) {
			ll o = (p2.y - p1.y) * (p3.x - p2.x) - (p2.x - p1.x) * (p3.y - p2.y);
			if (o == 0) {
				return 0;
			}
			return o > 0 ? 1 : 2;
		};

		auto area = [](Point p1, Point p2, Point p3) {
			vector<ll> v1 = { p1.x - p2.x, p1.y - p2.y };
			vector<ll> v2 = { p1.x - p3.x, p1.y - p3.y };
			return abs(v1[0] * v2[1] - v1[1] * v2[0]);
		};

		ll ans = 0;
		for (int i = 1; i + 1 < n; i++) {
			Point p1 = points[0];
			Point p2 = points[i];
			Point p3 = points[i + 1];
			int o = orientation(p1, p2, p3);
			if (o == 1) {
				ans -= area(p1, p2, p3);
			}
			else {
				ans += area(p1, p2, p3);
			}
		}
		cout << abs(ans) << endl;
	}
}