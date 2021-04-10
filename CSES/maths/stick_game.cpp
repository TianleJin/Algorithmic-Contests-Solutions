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

const int mxn = 100;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	vector<int> moves(k);
	for (int i = 0; i < k; i++) {
		cin >> moves[i];
	}
	vector<bool> dp(n + 1);
	dp[0] = false;
	for (int i = 1; i <= n; i++) {
		for (int x : moves) {
			if (i >= x && !dp[i - x]) {
				dp[i] = true;
				break;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (dp[i]) {
			cout << "W";
		}
		else {
			cout << "L";
		}
	}
}