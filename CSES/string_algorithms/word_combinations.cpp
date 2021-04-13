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

const int mod = 1e9 + 7;
const int mxs = 1e6 + 7;
const int mxn = 5e3 + 7;

string s;
int n, k, c;
ll dp[mxn];
int trie[mxs][26];
bool word[mxs];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;
	cin >> k;
	
	c = 1;
	n = s.size();
	memset(trie, -1, sizeof(trie));

	for (int i = 0; i < k; i++) {
		string s1;
		cin >> s1;
		int root = 0;
		for (int ch : s1) {
			int idx = ch - 'a';
			if (trie[root][idx] == -1) {
				trie[root][idx] = c++;
			}
			root = trie[root][idx];
		}
		word[root] = true;
	}

	dp[n] = 1;

	for (int i = n - 1; i >= 0; i--) {
		int root = 0;
		for (int j = i; j < n; j++) {
			int idx = s[j] - 'a';
			if (trie[root][idx] == -1) break;
			root = trie[root][idx];
			if (word[root]) {
				dp[i] = (dp[i] + dp[j + 1]) % mod;
			}
		}
	}
	cout << dp[0] << endl;
}