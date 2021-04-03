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
typedef vector<int> vi;
typedef pair<int, int> pii;

int n, k;
string s;
int solve() {
	cin >> n >> k;
	cin >> s;
	int score = 0;
	for (int i = 0; i < n / 2; i++) {
		if (s[i] != s[n - i - 1]) {
			score++;
		}
	}
	return abs(score - k);
}
	
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(25);
	
	int T;
	cin >> T;
	for (int tt = 1; tt <= T; tt++) {
		cout << "Case #" << tt << ": " << solve() << endl;
	}
}