#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	for (int tt = 1; tt <= T; tt++) {
		int n;
		cin >> n;

		unordered_map<int, vector<pii>> mp;
		mp.reserve(n);

		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		int ans = 0;
		int l = 0, d = a[1] - a[0];
		for (int r = 2; r < n; r++) {
			if (a[r] - a[r - 1] != d) {
				if (r + 1 < n && a[r - 1] + 2 * d == a[r + 1]) {
					ans = max(ans, r - l + 2);
				}
				if (r < n) {
					ans = max(ans, r - l + 1);
				}
				if (l > 1 && a[l - 2] + 2 * d == a[l]) {
					ans = max(ans, r - l + 2);
				}
				if (l > 0) {
					ans = max(ans, r - l + 1);
				}
				ans = max(ans, r - l);
				mp[d].push_back({ l, r - 1 });
				l = r - 1, d = a[r] - a[r - 1];
			}
		}
		if (l > 1 && a[l - 2] + 2 * d == a[l]) {
			ans = max(ans, n - l + 2);
		}
		if (l > 0) {
			ans = max(ans, n - l + 1);
		}
		ans = max(ans, n - l);
		mp[d].push_back({ l, n - 1 });

		for (auto it = mp.begin(); it != mp.end(); it++) {
			int d = it->first;
			vector<pii> x = it->second;
			if (x.size() == 1) continue;
			for (int i = 0; i < (int)x.size() - 1; i++) {
				pii f = x[i];
				pii s = x[i + 1];
				if (a[f.second] + 2 * d == a[s.first] && f.second + 2 == s.first) {
					ans = max(ans, s.second - f.first + 1);
				}
			}
		}
		cout << "Case #" << tt << ": " << ans << endl;
	}
}