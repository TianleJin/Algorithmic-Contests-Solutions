#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int mod = 998244353;
const int mxn = 3e5;
int n, m;
ll two[mxn + 1], pre[mxn + 1];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	vector<string> grid(n);
	for (int i = 0; i < n; i++) {
		cin >> grid[i];
	}

	int white = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == 'o') {
				white++;
			}
		}
	}

	if (white < 2) {
		cout << 0 << endl;
		return 0;
	}

	two[0] = 1;
	for (int i = 1; i <= white; i++) {
		two[i] = two[i - 1] * 2 % mod;
	}

	for (int i = 2; i <= white; i++) {
		if (i & 1) {
			pre[i] = (pre[i - 1] - two[white - i] + mod) % mod;
		}
		else {
			pre[i] = (pre[i - 1] + two[white - i]) % mod;
		}
	}

	ll ans = 0;
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == 'o') {
				cnt++;
			}
			else {
				cnt = 0;
			}
			if (cnt >= 2) {
				ans = (ans + pre[cnt]) % mod;
			}
		}
	}

	for (int j = 0; j < m; j++) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (grid[i][j] == 'o') {
				cnt++;
			}
			else {
				cnt = 0;
			}
			if (cnt >= 2) {
				ans = (ans + pre[cnt]) % mod;
			}
		}
	}

	cout << ans << endl;
}