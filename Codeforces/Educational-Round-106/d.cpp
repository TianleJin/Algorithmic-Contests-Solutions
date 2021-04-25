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

const int mxn = 2e7;
int factorCnt[mxn + 1];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 2; i <= mxn; i++) {
		if (factorCnt[i] == 0) {
			for (int j = i; j <= mxn; j += i) {
				factorCnt[j]++;
			}
		}
	}

	int T;
	cin >> T;
	while (T--) {
		int c, d, x;
		cin >> c >> d >> x;
		ll ans = 0;

		int i;
		for (i = 1; i * i < x; i++) {
			if (x % i == 0) {
				if ((x / i + d) % c == 0) {
					int m = (x / i + d) / c;
					ans += 1LL << factorCnt[m];
				}
				if ((i + d) % c == 0) {
					int m = (i + d) / c;
					ans += 1LL << factorCnt[m];
				}
			}
		}
		if (i * i == x) {
			if ((i + d) % c == 0) {
				int m = (i + d) / c;
				ans += 1LL << factorCnt[m];
			}
		}
		cout << ans << endl;
	}
}