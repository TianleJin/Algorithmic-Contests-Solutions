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

	const int mxn = 1250;
	vector<int> dp(mxn);
	for (int i = 2; i < mxn; i++) {
		unordered_set<int> s;
		for (int j = 1; j < (i + 1) / 2; j++) {
			s.insert(dp[j] ^ dp[i - j]);
		}
		for (int j = 0; j < mxn; j++) {
			if (s.find(j) == s.end()) {
				dp[i] = j;
				break;
			}
		}
	}

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		if (n >= mxn || dp[n]) {
			cout << "first" << endl;
		}
		else {
			cout << "second" << endl;
		}
	}
}