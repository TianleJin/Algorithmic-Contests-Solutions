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
	int T;
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;
		vector<int> indegree(m), outdegree(n);
		vector<vector<int>> daysFree(n);
		for (int d = 0; d < m; d++) {
			cin >> indegree[d];
			for (int i = 0; i < indegree[d]; i++) {
				int p;
				cin >> p; --p;
				daysFree[p].push_back(d);
				outdegree[p]++;
			}
		}

		vector<int> done(m, -1);
		for (int p = 0; p < n; p++) {
			vector<int> rem;
			for (int d : daysFree[p]) {
				if (done[d] == -1) {
					rem.push_back(d);
				}
				else {
					outdegree[p]--;
				}
			}
			
			assert(outdegree[p] == rem.size());
			if (outdegree[p] > (m + 1) / 2) {
				sort(rem.begin(), rem.end(), [&](const int d1, const int d2) {
					return indegree[d1] < indegree[d2];
					});

				while (outdegree[p] > (m + 1) / 2) {
					int d = rem.back(); rem.pop_back();
					outdegree[p]--; indegree[d]--;
				}
			}

			for (int d : rem) {
				done[d] = p;
			}
		}	

		bool possible = true;
		for (int x : done) {
			if (x == -1) {
				possible = false;
			}
		}

		if (possible) {
			cout << "YES" << endl;
			for (int x : done) {
				cout << x + 1 << ' ';
			}
			cout << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
}