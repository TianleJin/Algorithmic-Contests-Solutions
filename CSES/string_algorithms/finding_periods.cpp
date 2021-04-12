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

// https://cses.fi/problemset/task/1733
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	int n = s.size();
	vector<int> z(n);
	int l = 0, r = 0;
	for (int i = 1; i < n; i++) {
		if (i > r) {
			l = i;
			r = i;
			while (r < n && s[r] == s[r - l]) {
				r++;
			}
			z[i] = r - l;
			r--;
		}
		else {
			int k = i - l;
			if (z[k] < r - i + 1) {
				z[i] = z[k];
			}
			else {
				l = i;
				while (r < n && s[r] == s[r - l]) {
					r++;
				}
				z[i] = r - l;
				r--;
			}
		}
		if (z[i] == n - i) {
			cout << i << ' ';
		}
	}
	cout << n << endl;
}