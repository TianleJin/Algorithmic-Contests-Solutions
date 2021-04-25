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

const ll inf = 1e15;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<ll> cost(n);
		for (int i = 0; i < n; i++) {
			cin >> cost[i];
		}

		ll ans = inf, oddSum = 0, evenSum = cost[0], oddCnt = 0, evenCnt = 1;
		set<ll> oddSet, evenSet;
		evenSet.insert(cost[0]);
		
		for (int i = 1; i < n; i++) {
			if (i % 2 == 0) {
				evenSet.insert(cost[i]);
				evenSum += cost[i];
				evenCnt++;
			}
			else {
				oddSet.insert(cost[i]);
				oddSum += cost[i];
				oddCnt++;
			}

			ll oddMin = *oddSet.begin(), evenMin = *evenSet.begin();
			ll oddAns = oddSum - oddMin + (n - oddCnt + 1) * oddMin;
			ll evenAns = evenSum - evenMin + (n - evenCnt + 1) * evenMin;
			ans = min(ans, oddAns + evenAns);
		}

		cout << ans << endl;
	}
}