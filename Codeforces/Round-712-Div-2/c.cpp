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

const int mxn = 200005;
int ones[mxn];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		string s;
		cin >> s;

		for (int i = n - 1; i >= 0; --i) {
			ones[i] += ones[i + 1];
			if (s[i] == '1') {
				ones[i]++;
			}
		}

		bool ok = true;
		int c1 = 0, c2 = 0;
		vector<char> ans1(n), ans2(n);
		for (int i = 0; i < n; i++) {
			if (s[i] == '0') {
				if (c1 < c2) {
					c1++;
					c2--;
					ans1[i] = '(';
					ans2[i] = ')';
				}
				else {
					c1--;
					c2++;
					ans1[i] = ')';
					ans2[i] = '(';
				}
			}
			else {
				if (c1 + c2 + 2 > 2 * ones[i + 1]) {
					c1--;
					c2--;
					ans1[i] = ')';
					ans2[i] = ')';
				}
				else {
					c1++;
					c2++;
					ans1[i] = '(';
					ans2[i] = '(';
				}
			}
			if (c1 < 0 || c2 < 0) {
				ok = false;
			}
		}
		if (c1 || c2) {
			ok = false;
		}
		if (!ok) {
			cout << "NO" << endl;
		}
		else {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++) {
				cout << ans1[i];
			}
			cout << endl;
			for (int i = 0; i < n; i++) {
				cout << ans2[i];
			}
			cout << endl;
		}
	}
}