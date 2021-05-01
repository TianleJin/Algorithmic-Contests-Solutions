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
	for (int tt = 1; tt <= T; tt++) {
		int n, a, b;
		cin >> n >> a >> b;
		vector<int> cnt(n + 1);
		for (int i = 1; i <= n; i++) {
			cin >> cnt[i];
		}

		bool found = false;
		map<int, int> need, have;
		for (int m = 1; m <= 500 && !found; m++) {
			need.clear();
			have.clear();
			have[m] = 1;
			for (int i = 1; i <= n; i++) {
				if (cnt[i] > 0) {
					need[i] = cnt[i];
				}
			}

			while (true) {
				for (auto it1 = have.begin(); it1 != have.end(); ) {
					if (need.find(it1->first) != need.end()) {
						auto it2 = need.lower_bound(it1->first);
						int take = min(it1->second, it2->second);
						
						if (take >= it1->second) {
							it1 = have.erase(it1);
						}
						else {
							have[it1->first] -= take;
							++it1;
						}
						if (take >= it2->second) {
							need.erase(it2);
						}
						else {
							need[it2->first] -= take;
						}
					}
					else {
						++it1;
					}
				}
				
				if (need.size() == 0) {
					found = true;
					break;
				}

				if (have.size() == 0) {
					break;
				}

				auto it1 = have.end(); --it1;
				auto it2 = need.end(); --it2;
				if (*it2 > *it1) {
					break;
				}

				if (it1->first - a > 0) {
					have[it1->first - a] += it1->second;
				}
				if (it1->first - b > 0) {
					have[it1->first - b] += it1->second;
				}

				have.erase(it1);
			}

			if (found) {
				cout << "Case #" << tt << ": " << m << endl;
			}
		}
		if (!found) {
			cout << "Case #" << tt << ": IMPOSSIBLE" << endl;
		}
	}
}