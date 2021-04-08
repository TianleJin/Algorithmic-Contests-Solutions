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

// https://cses.fi/problemset/task/2164/
// recursion

int solve(int n, int k, bool f = false) {
	if (k == 1) {
		if (f) {
			return 0;
		}
		else {
			return 1 % n;
		}
	}
	if (f && (n + 1) / 2 >= k) {
		return 2 * (k - 1);
	}
	if (!f && n / 2 >= k) {
		return 2 * (k - 1) + 1;
	}
	if (n & 1) {
		if (f) {
			return 2 * solve(n / 2, k - (n + 1) / 2, false) + 1;
		}
		else {
			return 2 * solve((n + 1) / 2, k - n / 2, true);
		}
	}
	else {
		if (f) {
			return 2 * solve(n / 2, k - n / 2, true) + 1;
		}
		else {
			return 2 * solve(n / 2, k - n / 2, false);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int q;
	cin >> q;
	while (q--) {
		int n, k;
		cin >> n >> k;
		cout << solve(n, k) + 1 << endl;
	}
}