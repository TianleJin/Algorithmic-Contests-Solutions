#include <iostream>
#include <string>
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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n;
		string s;
		cin >> s;
		n = s.size();
		bool ok = true, seen = false;
		int t = s[0] - '0', c = 1;
		for (int i = 1; i < n; i++) {
			if (s[i] - '0' == t) {
				c++;
			}
			else {
				if (seen && t == 0 && c > 1) {
					ok = false;
				}
				if (t == 1 && c > 1) {
					seen = true;
				}
				t = t ^ 1, c = 1;
			}
		}
		if (seen && t == 0 && c > 1) {
			ok = false;
		}
		if (ok) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
}