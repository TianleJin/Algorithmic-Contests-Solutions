#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int mxn = 2e5;
int n, k;
char ans[mxn];
bool vis[26][26];

bool dfs(int idx, int s) {
	if (idx == k * k + 1) {
		return true;
	}

	for (int i = 0; i < k; i++) {
		if (!vis[s][i]) {
			ans[idx] = 'a' + i;
			vis[s][i] = true;
			if (dfs(idx + 1, i)) return true;
			vis[s][i] = false;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;

	ans[0] = 'a';
	dfs(1, 0);
	
	int l = k * k;
	for (int i = l + 1; i < n; i++) {
		ans[i] = ans[i - l];
	}

	for (int i = 0; i < n; i++) {
		cout << ans[i];
	}
}