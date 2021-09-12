#include <iostream>
#include <array>
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

int solve(int n, int start = 3) {
	if (start == 2) {
		n--;
	}

	if (n == 1) {
		return 0;
	}

	int ans = 1;
	for (int i = start; i * i <= n; i++) {
		if (n % i == 0) {
			ans = max(ans, 1 + solve(n / i, 2));
			ans = max(ans, 1 + solve(i, 2));
		}
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	for (int tt = 1; tt <= T; tt++) {
		int n;
		cin >> n;
		cout << "Case #" << tt << ": " << solve(n) << endl;
	}
}