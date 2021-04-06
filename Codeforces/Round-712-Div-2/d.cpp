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

int n;
int main() {
	// ios::sync_with_stdio(false);
	// cin.tie(0);
	cin >> n;
	int x = 0, y = 1;
	for (int i = 0; i < n * n; i++) {
		int ban, cur, row, col; 
		cin >> ban;
		if (ban == 1) {
			cur = y >= n * n ? 3 : 2;
		}
		else if (ban == 2) {
			cur = x >= n * n ? 3 : 1;
		}
		else {
			cur = x >= n * n ? 2 : 1;
		}
		if (cur == 1 || y >= n * n) {
			row = x / n, col = x % n;
			if (n & 1 || col + 2 < n) {
				x += 2;
			}
			else {
				x += col + 1 == n ? 1 : 3;
			}
		}
		else {
			row = y / n, col = y % n;
			if (n & 1 || col + 2 < n) {
				y += 2;
			}
			else {
				y += col + 1 == n ? 1 : 3;
			}
		}
		++row; ++col;
		cout << cur << ' ' << row << ' ' << col << endl;
		cout.flush();
	}
}