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
	while (T--) {
		int a, b, c;
		cin >> a >> b >> c;

		ll ans1 = 1, ans2 = 1, x = 1;
		for (int i = 0; i < c - 1; i++) {
			x = x * 10;
		}

		if (a > c) {
			for (int i = 0; i < a - c; i++) {
				ans1 = ans1 * 11;
			}
		}

		if (b > c) {
			for (int i = 0; i < b - c; i++) {
				ans2 = ans2 * 12;
			}
		}

		cout << ans1 * x << ' ' << ans2 * x << endl;
	}
}