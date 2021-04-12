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

// https://cses.fi/problemset/task/2189/
const double eps = 1e-9;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int x1, x2, x3, y1, y2, y3;
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
		if (x1 == x2) {
			if (x3 == x1) {
				cout << "TOUCH" << endl;
				continue;
			}
			if (x3 < x1 && y1 < y2 || x3 > x1 && y1 > y2) {
				cout << "LEFT" << endl;
				continue;
			}
			if (x3 < x1 && y1 > y2 || x3 > x1 && y1 < y2) {
				cout << "RIGHT" << endl;
				continue;
			}
		}

		auto f = [&](int x) {
			return 1.0 * (y2 - y1) / (x2 - x1) * (x - x1) + y1;
		};

		if (abs(f(x3) - y3) < eps) {
			cout << "TOUCH" << endl;
			continue;
		}
		if (f(x3) - eps > y3 && x1 > x2 || y3 - eps > f(x3) && x1 < x2) {
			cout << "LEFT" << endl;
			continue;
		}
		if (f(x3) - eps > y3 && x1 < x2 || y3 - eps > f(x3) && x1 > x2) {
			cout << "RIGHT" << endl;
			continue;
		}

	}
}