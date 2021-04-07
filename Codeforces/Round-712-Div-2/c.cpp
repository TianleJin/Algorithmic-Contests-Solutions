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

		int ones = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == '1') {
				ones++;
			}
		}

		if (ones % 2 || s[0] == '0' || s[n - 1] == '0') {
			cout << "NO" << endl;
			continue;
		}

		vector<char> ans1(n), ans2(n);
		for (int i = 0, c = 0; i < n; i++) {
			if (s[i] == '1') {
				c++;
				if (c <= ones / 2) {
					ans1[i] = '(';
					ans2[i] = '(';
				}
				else {
					ans1[i] = ')';
					ans2[i] = ')';
				}
			}
		}

		for (int i = 0, c = 0; i < n; i++) {
			if (s[i] == '0') {
				c++;
				if (c % 2) {
					ans1[i] = ')';
					ans2[i] = '(';
				}
				else {
					ans1[i] = '(';
					ans2[i] = ')';
				}
			}
		}

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