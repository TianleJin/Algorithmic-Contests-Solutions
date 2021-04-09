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

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int dx4[] = { -1, 0, 1, 0 };
const int dy4[] = { 0, -1, 0, 1 };
const int dx8[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
const int dy8[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

const int mxn = 2e3;
const int mod = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T = 1;
	while (T--) {
		int n;
		cin >> n;
		vector<pii> count(n);
		for (int i = 0; i < n; i++) {
			int c;
			cin >> c;
			count[i] = { c, i + 1 };
		}

		sort(count.begin(), count.end());

		vector<array<int, 3>> q;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				q.push_back({ abs(count[i].first - count[j].first), count[i].second, count[j].second });
			}
		}

		sort(q.begin(), q.end());
		
		for (int i = q.size() - 1; i >= 0; i--) {
			cout << "? " << q[i][2] << " " << q[i][1] << endl;
			cout.flush();
			string res;
			cin >> res;
			if (res == "Yes") {
				cout << "! " << q[i][2] << " " << q[i][1] << endl;
				exit(0);
			}
		}

		cout << "! 0 0" << endl;
		exit(0);
	}
}