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


const int mod = 998244353;
int main() {
	int R, C;
	cin >> R >> C;
	vector<string> grid(R);
	for (int i = 0; i < R; i++) {
		cin >> grid[i];
	}

	ll ans = 1;
	vector<bool> hasRed(R + C - 1), hasBlue(R + C - 1);
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (grid[i][j] == 'R') {
				hasRed[i + j] = true;
			}
			if (grid[i][j] == 'B') {
				hasBlue[i + j] = true;
			}
		}
	}

	for (int i = 0; i < R + C - 1; i++) {
		if (hasRed[i] && hasBlue[i]) {
			ans = 0;
		}
		if (!hasRed[i] && !hasBlue[i]) {
			ans = ans * 2 % mod;
		}
	}
	cout << ans << endl;
}