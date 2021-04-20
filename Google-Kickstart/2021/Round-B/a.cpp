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
		string s;
		cin >> s;

		cout << "Case #" << tt << ": ";

		int len = 0, last = -1;
		for (int i = 0; i < n; i++) {
			if (s[i] - 'A' > last) {
				len++;
			}
			else {
				len = 1;
			}
			last = s[i] - 'A';
			cout << len << ' ';
		}
		cout << endl;
	}
}