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

const int mxl = 2e1;
const int mxn = 1e5;

string s;
int n, k, rnk[mxn][mxl];
struct Obj { int idx; array<int, 2> x; } ord[mxn];

bool comp(Obj& obj1, Obj& obj2) {
	return obj1.x < obj2.x;
}

void buildArray() {
	for (int i = 0; i < n; i++) {
		rnk[i][0] = s[i] - 'a';
	}
	
	for (int s = 1, i = 1; s <= n; s <<= 1, i++) {
		for (int j = 0; j < n; j++) {
			ord[j] = { j, { rnk[j][i - 1], j + s < n ? rnk[j + s][i - 1] : -1 } };
		}
		sort(ord, ord + n, comp);
		rnk[ord[0].idx][i] = 0;
		for (int j = 1, r = 0; j < n; j++) {
			if (ord[j - 1].x[0] != ord[j].x[0] || ord[j - 1].x[1] != ord[j].x[1]) {
				r++;
			}
			rnk[ord[j].idx][i] = r;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;
	cin >> k;
	n = s.size();
	buildArray();

	for (int i = 0; i < k; i++) {
		string pat;
		cin >> pat;
		bool found = 0;
		int sze = pat.size();
		int lo = 0, hi = n - 1;
		while (!found && lo <= hi) {
			int mi = (lo + hi) >> 1, idx = ord[mi].idx;
			bool equal = 1, small = 1;
			for (int i = idx; equal && i < min(n, idx + sze); i++) {
				if (s[i] < pat[i - idx]) {
					small = 1;
					equal = 0;
				}
				if (s[i] > pat[i - idx]) {
					small = 0;
					equal = 0;
				}
			}
			if (equal && idx + sze <= n) {
				cout << "YES" << endl;
				found = 1;
			}
			else if (equal || small) {
				lo = mi + 1;
			}
			else {
				hi = mi - 1;
			}
		}
		if (!found) {
			cout << "NO" << endl;
		}
	}
}