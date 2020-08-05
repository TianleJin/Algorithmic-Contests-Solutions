#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <array>
#include <map>
#include <set>
#include <string>
#include <deque>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <assert.h>
using namespace std;
typedef long long ll;
#define pi pair<int, int>
#define pii pair<pi, pi>


unordered_map<int, bool> cache;
bool isPrime(int i) {
	if (cache.find(i) != cache.end()) {
		return cache[i];
	}

	for (int j = 2; j * j <= i; j++) {
		if (i % j == 0) {
			cache[i] = false;
			return false;
		}
	}
	cache[i] = true;
	return true;
}


int main() {
	int T, L, R;
	cin >> T;
	for (int tt = 1; tt <= T; tt++) {
		cin >> L >> R;
		int ans = 0;

		// manual checks
		if (L <= 0) {
			ans++;
		}

		if (L <= 1) {
			ans++;
		}

		// get all primes
		for (int i = max(3, L); i <= R; i++) {
			if ((i & 1) && isPrime(i)) {
				ans++;
			}
		}

		// 2 * odd
		for (int i = L; i <= R; i++) {
			if (i % 2 == 0 && i % 4) {
				ans++;
			}
		}

		// 4 * prime
		for (int i = L; i <= R; i++) {
			if (i % 4 == 0) {
				int val = i / 4;
				if (val == 1 || isPrime(val)) {
					ans++;
				}
			}
		}
		cout << "Case #" << tt << ": " << ans << '\n';
	}
}