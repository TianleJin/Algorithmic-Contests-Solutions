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

const int mxn = 1e6;
int lps[mxn];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	int l = 0;
	int n = s.size();
	for (int i = 1; i < n; i++) {
		while (l && s[i] != s[l]) {
			l = lps[l - 1];
		}
		if (s[i] == s[l]) {
			l++;
		}
		lps[i] = l;
	}

	vector<int> ans;

	while(l) {
		ans.push_back(l);
		l = lps[l - 1];
	}

	reverse(ans.begin(), ans.end());

	for (int x : ans) {
		cout << x << ' ';
	}
}