#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--) {
		int n, k;
		cin >> n >> k;
		if (k > (n - 1) / 2) {
			cout << -1 << endl;
			continue;
		}
		vector<int> ans(n);
		int idx = 1, val = n;
		for (int i = 0; i < k; i++) {
			ans[idx] = val;
			idx += 2;
			val--;
		}
		for (int i = n - 1; i >= 0; i--) {
			if (ans[i] == 0) {
				ans[i] = val--;
			}
		}
		for (int i = 0; i < n; i++) {
			cout << ans[i] << ' ';
		}
		cout << endl;
	}
}