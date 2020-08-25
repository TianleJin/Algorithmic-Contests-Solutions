#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <array>
#include <map>
#include <set>
#include <string>
#include <deque>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <assert.h>
typedef long long ll;
#define pi pair<int, int>
#define pii pair<pi, pi>
#define pl pair<ll, ll>
#define vi vector<int>
#define vii vector<vi>
#define viii vector<vii>
#define vl vector<ll>
#define vll vector<vl>
#define vlll vector<vll>
using namespace std;


const int mxn = 1e5 + 10;
ll E[mxn], R[mxn], bit[mxn];

void update(int N, int idx, ll val) {
	idx += 1;
	while (idx <= N) {
		bit[idx] += val;
		idx += idx & (-idx);
	}
}

ll query(int idx) {
	ll ans = 0;
	idx += 1;
	while (idx > 0) {
		ans += bit[idx];
		idx -= idx & (-idx);
	}
	return ans;
}

void solve(int tt) {
	int N;
	cin >> N;

	// inputs
	for (int i = 0; i < N; i++) {
		cin >> E[i] >> R[i];
	}

	// clear bit
	for (int i = 0; i <= N; i++) {
		bit[i] = 0;
	}

	set<pl> S;
	set<int> I;

	// calculate total
	ll total = 0;
	for (int i = 0; i < N; i++) {
		total = total + E[i];
		update(N, i, E[i]);
	}

	// insert into set
	for (int i = 0; i < N; i++) {
		S.insert(make_pair(total - E[i] - R[i], i));
	}

	bool ok = 1;
	int remove = 0;
	int best_remove = 0;
	ll ans = 0;
	ll quota = 0;
	while (1) {
		// find bad toys
		for (auto it = S.begin(); it != S.end();) {
			if (it->first - quota >= 0) break;
			I.insert(it->second);
			it = S.erase(it);
		}
		// ran out of toys
		if (S.size() == 0) {
			ok = 0;
		}
		// no more bad toys
		if (I.size() == 0) {
			break;
		}
		else {
			auto it = I.begin();
			int idx = *it;
			ll first = (idx == 0) ? 0 : query(idx - 1);
			ll best = query(N - 1) + first;
			if (best > ans) {
				best_remove = remove;
				ans = best;
			}
			remove++;
			ll delta = E[idx];
			quota += delta;
			update(N, idx, -delta);
			I.erase(it);
		}
	}
	if (ok) {
		cout << "Case #" << tt << ": " << remove << " " << "INDEFINITELY" << '\n';
	}
	else {
		cout << "Case #" << tt << ": " << best_remove << " " << ans << '\n';
	}
}


int main() {
	int T;
	cin >> T;
	for (int tt = 1; tt <= T; tt++) {
		solve(tt);
	}
}