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
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<vector<ll>> vvll;
typedef vector<vector<int>> vvi;
typedef vector<vector<bool>> vvb;
typedef pair<int, int> pii;

const int dx4[] = { -1, 0, 1, 0 };
const int dy4[] = { 0, -1, 0, 1 };
const int dx8[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
const int dy8[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

// fenwick tree + monotone deque + binary search + sort queries by left boundary
const int mxn = 200002;
const ll inf = 1e18;
int N, Q;
ll arr[mxn], cont[mxn], pref[mxn], bit[mxn];
vector<pii> q[mxn];

void update(int idx, ll val) {
	for (int i = idx; i <= N; i += i & -i) {
		bit[i] += val;
	}
}

ll query(int idx) {
	ll ans = 0;
	for (int i = idx; i; i -= i & -i) {
		ans += bit[i];
	}
	return ans;
}

void solve() {
	cin >> N >> Q;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		pref[i] = pref[i - 1] + arr[i];
	}
	arr[N + 1] = inf;
	pref[N + 1] = pref[N] + arr[N + 1];

	for (int i = 1; i <= Q; i++) {
		int l, r;
		cin >> l >> r;
		q[l].push_back({ r, i });
	}

	vector<ll> ans(N + 1);
	deque<int> dq;
	dq.push_front(N + 1);
	for (int i = N; i; --i) {
		while (!dq.empty() && arr[i] >= arr[dq.front()]) {
			update(dq.front(), -cont[dq.front()]);
			dq.pop_front();
		}
		cont[i] = ((ll)dq.front() - i - 1) * arr[i] - (pref[dq.front() - 1] - pref[i]);
		dq.push_front(i);
		update(i, cont[i]);
		for (pii j : q[i]) {
			int idx = upper_bound(dq.begin(), dq.end(), j.first) - dq.begin() - 1;
			ans[j.second] = (idx ? query(dq[idx - 1]) : 0) + (j.first - dq[idx]) * arr[dq[idx]] - (pref[j.first] - pref[dq[idx]]);
		}
	}

	for (int i = 1; i <= Q; i++) {
		cout << ans[i] << endl;
	}


}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	// cout.precision(25);
	solve();
}