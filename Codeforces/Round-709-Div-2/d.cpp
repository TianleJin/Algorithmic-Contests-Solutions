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

int gcd(int x, int y) {
	while (y) {
		int r = x % y;
		x = y;
		y = r;
	}
	return x;
}

const int mxn = 1e5;
int arr[mxn], prv[mxn], nxt[mxn];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		for (int i = 0; i < n; i++) {
			prv[i] = (n + i - 1) % n;
			nxt[i] = (i + 1) % n;
		}

		queue<int> q;
		for (int i = 0; i < n; i++) {
			int j = (i + 1) % n;
			if (gcd(arr[i], arr[j]) == 1) {
				q.push(j);
			}
		}
		vector<int> ans;
		while (q.size()) {
			int i = q.front(); q.pop();
			ans.push_back(i);
			if (q.size() && q.front() == nxt[i]) {
				q.pop();
			}
			int x = nxt[i];
			int y = prv[i];
			if (i == x) {
				break;
			}
			if (gcd(arr[x], arr[y]) == 1) {
				q.push(x);
			}
			nxt[y] = x;
			prv[x] = y;
		}

		cout << ans.size();
		for (int i : ans) {
			cout << ' ' << i + 1;
		}
		cout << endl;
	}
}