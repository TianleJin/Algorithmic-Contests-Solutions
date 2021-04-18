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
	int n, q;
	cin >> n >> q;
	vector<int> ind(51, -1);
	for (int i = 0; i < n; i++) {
		int c;
		cin >> c;
		if (ind[c] == -1) {
			ind[c] = i;
		}
	}
	for (int i = 0; i < q; i++) {
		int c;
		cin >> c;
		cout << ind[c] + 1 << ' ';
		for (int j = 1; j < 51; j++) {
			if (ind[j] != -1 && ind[j] < ind[c]) {
				ind[j]++;
			}
		}
		ind[c] = 0;
	}
}