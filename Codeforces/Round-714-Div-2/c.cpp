#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int mxn = 2e5;
const int mod = 1e9 + 7;
int dp[10][mxn + 1][10];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 0; i < 10; i++) {
		dp[i][0][i] = 1;
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 1; j <= mxn; j++) {
			for (int k = 0; k < 10; k++) {
				if (k == 0) {
					dp[i][j][k] = dp[i][j - 1][9];
				}
				else if (k == 1) {
					dp[i][j][k] = dp[i][j - 1][9] + dp[i][j - 1][0];
					dp[i][j][k] %= mod;
				}
				else {
					dp[i][j][k] = dp[i][j - 1][k - 1];
				}
			}
		}
	}

	int T;
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;

		ll ans = 0;
		while (n) {
			for (int j = 0; j < 10; j++) {
				ans += dp[n % 10][m][j] % mod;
				ans %= mod;
			}
			n /= 10;
		}
		cout << ans << endl;
	}
}