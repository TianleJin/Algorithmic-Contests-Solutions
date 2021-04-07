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
const int dxknight[] = { -1, -1, -2, -2, 1, 1, 2, 2 };
const int dyknight[] = { 2, -2, 1, -1, 2, -2, 1, -1 };

struct Point {
	int r, c;
	bool operator<(const Point& point) const {
		if (r - c != point.r - point.c) {
			return r - c < point.r - point.c;
		}
		return r < point.r;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<Point> coord(n + 1);
		coord[0].r = 1, coord[0].c = 1;
		for (int i = 1; i <= n; i++) {
			cin >> coord[i].r;
		}
		for (int i = 1; i <= n; i++) {
			cin >> coord[i].c;
		}

		sort(coord.begin(), coord.end());

		ll ans = 0;
		for (int i = 0; i < n; i++) {
			Point p1 = coord[i], p2 = coord[i + 1];
			if (p2.r - p2.c == p1.r - p1.c) {
				ans += p1.r - p1.c & 1 ? 0 : p2.r - p1.r;
				continue;
			}
			int d = p2.r - p2.c - (p1.r - p1.c);
			if (d % 2 && p1.r - p1.c & 1) {
				ans += (d + 1) / 2;
			}
			else {
				ans += d / 2;
			}
		}
		cout << ans << endl;
	}
}