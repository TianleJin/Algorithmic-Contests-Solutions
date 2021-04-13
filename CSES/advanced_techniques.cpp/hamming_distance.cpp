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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	auto str2Int = [](string x) {
		int num = 0;
		for (char ch : x) {
			num <<= 1;
			if (ch == '1') {
				num++;
			}
		}
		return num;
	};

	auto popcount = [](int x) {
		int count = 0;
		while (x) {
			if (x & 1) {
				count++;
			}
			x >>= 1;
		}
		return count;
	};

	int n, k;
	cin >> n >> k;
	vector<vector<int>> buckets(k + 1);
	for (int i = 0; i < n; i++) {
		string x; int y;
		cin >> x; y = str2Int(x);
		buckets[popcount(y)].push_back(y);
	}

	for (vector<int>& b : buckets) {
		int sze = b.size();
		sort(b.begin(), b.end());
		b.erase(unique(b.begin(), b.end()), b.end());
		if (b.size() < sze) {
			cout << 0 << endl;
			return 0;
		}
	}

	int ans = k;
	for (int i = 0; i <= k; i++) {
		if (ans <= 1) break;
		vector<int>& b1 = buckets[i];
		if (b1.empty()) continue;
		for (int x = 0; x < (int)b1.size(); x++) {
			if (ans <= 2) break;
			for (int y = x + 1; y < (int)b1.size(); y++) {
				ans = min(ans, popcount(b1[x] ^ b1[y]));
			}
		}
		for (int j = i + 1; j < min(k + 1, i + ans); j++) {
			vector<int>& b2 = buckets[j];
            if (b2.empty()) continue;
			for (int x = 0; x < (int)b1.size(); x++) {
				if (ans + i <= j) break;
				for (int y = 0; y < (int)b2.size(); y++) {
					ans = min(ans, popcount(b1[x] ^ b2[y]));
				}
			}
		}
	}
	cout << ans << endl;
}