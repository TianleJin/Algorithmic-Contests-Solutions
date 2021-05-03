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
	int T;
	cin >> T;
	while (T--) {
		int n; string s;
		cin >> n >> s;

		bool ok = true;
		if (n % 3) {
			ok = false;
		}

		vector<int> t, m;
		for (int i = 0; i < n; i++) {
			if (s[i] == 'M') {
				m.push_back(i);
			}
			else {
				t.push_back(i);
			}
		}

		if (t.size() == m.size() * 2) {
			int k = m.size();
			for (int i = 0; i < k; i++) {
				if (t[i] > m[i] || m[i] > t[i + k]) {
					ok = false;
				}
			}
		}
		else {
			ok = false;
		}
		
		if (!ok) {
			cout << "NO" << endl;
		}
		else {
			cout << "YES" << endl;
		}
	}
}