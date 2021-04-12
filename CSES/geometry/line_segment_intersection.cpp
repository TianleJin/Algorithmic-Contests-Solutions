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

// https://cses.fi/problemset/task/2190/
const double eps = 1e-9;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int x1, x2, x3, x4, y1, y2, y3, y4;
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

		auto orientation = [](int x1, int y1, int x2, int y2, int x3, int y3) {
			ll o = 1LL * (y2 - y1) * (x3 - x2) - 1LL * (y3 - y2) * (x2 - x1);
			if (o == 0) {
				return 0;
			}
			return o > 0 ? 1 : 2;
		};

		auto overlap = [](int x1, int y1, int x2, int y2, int x3, int y3) {
			return min(x1, x2) <= x3 && x3 <= max(x1, x2) && min(y1, y2) <= y3 && y3 <= max(y1, y2);
		};

		bool intersect = false;
		int o1 = orientation(x1, y1, x2, y2, x3, y3);
		int o2 = orientation(x1, y1, x2, y2, x4, y4);
		int o3 = orientation(x3, y3, x4, y4, x1, y1);
		int o4 = orientation(x3, y3, x4, y4, x2, y2);

		if (o1 != o2 && o3 != o4) {
			intersect = true;
		}

		if (o1 == 0 && overlap(x1, y1, x2, y2, x3, y3)) {
			intersect = true;
		}

		if (o2 == 0 && overlap(x1, y1, x2, y2, x4, y4)) {
			intersect = true;
		}

		if (o3 == 0 && overlap(x3, y3, x4, y4, x1, y1)) {
			intersect = true;
		}

		if (o4 == 0 && overlap(x3, y3, x4, y4, x2, y2)) {
			intersect = true;
		}

		if (intersect) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
}