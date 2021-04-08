#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int dx4[] = { -1, 0, 1, 0 };
const int dy4[] = { 0, -1, 0, 1 };
const int dx8[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
const int dy8[] = { -1, 0, 1, -1, 1, -1, 0, 1 };


// https://cses.fi/problemset/task/1696/
// bipartite matching
const int mxn = 501;
int n, m, k;
int match[mxn];
bool vis[mxn];
vector<int> graph[mxn];

int dfs(int node) {
	vis[node] = 1;
	for (int i : graph[node]) {
		if (match[i] < 0 || !vis[match[i]] && dfs(match[i])) {
			match[i] = node;
			return 1;
		}
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
	}
	memset(match, -1, sizeof(match));
	memset(vis, 0, sizeof(vis));
	
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		memset(vis, 0, sizeof(vis));
		ans += dfs(i);
	}
	cout << ans << endl;
	for (int i = 1; i <= m; i++) {
		if (match[i] != -1) {
			cout << match[i] << ' ' << i << endl;
		}
 	}
}