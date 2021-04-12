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

struct Point {
	double x, y;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T = 1;
	while (T--) {
		int n, m;
		cin >> n >> m;
		vector<Point> points(n);
		for (int i = 0; i < n; i++) {
			cin >> points[i].x >> points[i].y;
		}

		auto orientation = [](Point p1, Point p2, Point p3) {
			ll o = (p2.y - p1.y) * (p3.x - p2.x) - (p2.x - p1.x) * (p3.y - p2.y);
			if (o == 0) {
				return 0;
			}
			return o > 0 ? 1 : 2;
		};

		auto overlap = [](Point p1, Point p2, Point p3) {
			return min(p1.x, p2.x) <= p3.x && p3.x <= max(p1.x, p2.x) && min(p1.y, p2.y) <= p3.y && p3.y <= max(p1.y, p2.y);
		};
		
		for (int j = 0; j < m; j++) {
			Point p;
			cin >> p.x >> p.y;

			bool go = true;
			for (int i = 0; i < n && go; i++) {
				Point p1 = points[i], p2 = points[(i + 1) % n];
				if (orientation(p1, p2, p) == 0 && overlap(p1, p2, p)) {
					cout << "BOUNDARY" << endl;
					go = false;
				}
			}
			if (!go) {
				continue;
			}

			int counter = 0;
			for (int i = 0; i < n; i++) {
				Point p1 = points[i], p2 = points[(i + 1) % n];
				if (p.y > min(p1.y, p2.y)) {
					if (p.y <= max(p1.y, p2.y)) {
						if (p.x <= max(p1.x, p2.x)) {
							double xinters = (p.y - p1.y) * (p2.x - p1.x) / (p2.y - p1.y) + p1.x;
							if (p.x <= xinters) {
								counter++;
							}
						}
					}
				}
			}

			if (counter % 2) {
				cout << "INSIDE" << endl;
			}
			else {
				cout << "OUTSIDE" << endl;
			}
		}
	}
}