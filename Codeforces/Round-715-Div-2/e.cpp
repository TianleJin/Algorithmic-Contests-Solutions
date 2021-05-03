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

	vector<ll> two(61, 1);
	for (int i = 1; i <= 60; i++) {
		two[i] = two[i - 1] << 1;
	}

	auto index = [](int x) {
		return max(0, min(60, x));
	};

	int T;
	cin >> T;
	while (T--) {
		int n; ll k;
		cin >> n >> k;

		if (k > two[index(n - 1)]) {
			cout << -1 << endl;
			continue;
		}

		vector<int> ans(n);
		
        int i = 0;
		int l = 1;
		while (l <= n) {
			int x = l;
			while (x <= n) {
				int idx = index(n - x - 1);
				if (two[idx] >= k) break;
				k -= two[idx];
				x++;
			}
			
			for (int j = x; j >= l; j--) {
				ans[i++] = j;
			}
			l = x + 1;
		}

		for (int num : ans) {
			cout << num << ' ';
		}
	}
}