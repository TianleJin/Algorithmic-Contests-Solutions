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

const int den = 1e5;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<bool> vis(m + 1);
	vis[0] = 1;
	vector<int> ans(m + 1, -1);
	ans[0] = 0;

	for (int i = 1; i <= n; i++) {
		auto new_vis = vis;
		int t, y; ll x;
		cin >> t >> x >> y;

		auto operation = [&](ll& curr) {
			if (t == 1) {
				curr = curr + (x + den - 1) / den;
			}
			else {
				curr = (curr * x + den - 1) / den;
			}
		};

		for (int a = 0; a < m; a++) {
			if (vis[a]) {
				ll curr = a;
				for (int j = 1; j <= y; j++) {
					operation(curr);
					if (curr > m) break;
					if (vis[curr]) break;
					ans[curr] = i;
					new_vis[curr] = 1;
				}
			}
		}
		vis = new_vis;
	}

	for (int i = 1; i <= m; i++) {
		cout << ans[i] << ' ';
	}
}