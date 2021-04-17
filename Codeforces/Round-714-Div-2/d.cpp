#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int mxn = 2e5;
int n, p, a[mxn], par[mxn];

int find(int x) {
	if (par[x] < 0) {
		return x;
	}
	return par[x] = find(par[x]);
}

bool unite(int x, int y) {
	int xp = find(x), yp = find(y);
	if (xp == yp) return false;
	if (par[xp] < par[yp]) {
		par[xp] += par[yp];
		par[yp] = xp;
	}
	else {
		par[yp] += par[xp];
		par[xp] = yp;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		cin >> n >> p;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		for (int i = 0; i < n; i++) {
			par[i] = -1;
		}

		vector<int> ord(n);
		for (int i = 0; i < n; i++) {
			ord[i] = i;
		}

		sort(ord.begin(), ord.end(), [&](const int& i, const int& j) {
			return a[i] < a[j];
		});

		ll ans = 0, comp = n;
		for (int i : ord) {
			if (a[i] >= p) break;
			int l = i - 1, r = i + 1;
			while (l >= 0 && a[l] % a[i] == 0) {
				if (!unite(i, l)) break;
				ans += a[i];
				comp--;
				l--;
			}
			while (r < n && a[r] % a[i] == 0) {
				if (!unite(i, r)) break;
				ans += a[i];
				comp--;
				r++;
			}
		}
		cout << ans + (comp - 1) * p << endl;
	}
}