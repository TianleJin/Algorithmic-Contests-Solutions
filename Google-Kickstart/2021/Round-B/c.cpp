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

bool isPrime(ll x) {
	for (ll i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	for (int tt = 1; tt <= T; tt++) {
		ll z;
		cin >> z;
		ll sqt = (ll)sqrt(z);

		ll above = -1, x = sqt + 1;
		while (above == -1) {
			if (isPrime(x)) {
				above = x;
			}
			x++;
		}
		
		ll below1 = -1, below2 = -1, y = sqt;
		while (below1 == -1 || below2 == -1) {
			if (isPrime(y)) {
				if (below1 == -1) {
					below1 = y;
				}
				else if (below2 == -1) {
					below2 = y;
				}
			}
			y--;
		}

		ll ans = below1 * below2;
		if (z / below1 >= above) {
			ans = max(ans, below1 * above);
		}
		cout << "Case #" << tt << ": " << ans << endl;
	}
}