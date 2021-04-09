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

// https://cses.fi/problemset/task/1684/
const int mxn = 100001;
int n, m;
int fst[mxn], snd[mxn];
unordered_set<int> constraints[2 * mxn];
bool must[2 * mxn];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		char c1, c2;
		int t1, t2, t3, t4;
		cin >> c1 >> t1 >> c2 >> t2;
		fst[i] = t3 = c1 == '+' ? m + t1 : m - t1;
		snd[i] = t4 = c2 == '+' ? m + t2 : m - t2;
		if (constraints[t3].find(2 * m - t4) != constraints[t3].end()) {
			must[t3] = true;
		}
		if (constraints[t4].find(2 * m - t3) != constraints[t4].end()) {
			must[t4] = true;
		}
		constraints[t3].insert(t4);
		constraints[t4].insert(t3);
	}

	for (int i = 0; i < m; i++) {
		if (must[i] && must[2 * m - i]) {
			cout << "IMPOSSIBLE" << endl; return 0;
		}
	}

	bool ok = true;
	for (int i = 1; i <= n; i++) {
		if (must[fst[i]] || must[snd[i]]) {
			continue;
		}
		else if (!must[2 * m - fst[i]]) {
			must[fst[i]] = true;
			continue;
		}
		else if (!must[2 * m - snd[i]]) {
			must[snd[i]] = true;
			continue;
		}
		else {
			ok = false;
		}
	}

	if (!ok) {
		cout << "IMPOSSIBLE" << endl; return 0;
	}

	for (int i = m - 1; i >= 0; i--) {
		if (must[i]) {
			cout << '-' << ' ';
		}
		else {
			cout << '+' << ' ';
		}
	}
}