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
		int n;
		cin >> n;
		int ans = 0;
		for (int i = 0; i < n; i++) {
			int t;
			cin >> t;
			if (t != 2) {
				ans++;
			}
		}
		cout << ans << endl;
	}
}