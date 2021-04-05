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

// https://cses.fi/problemset/task/1692
// eulerian trail
const int mxn = 100001;
int n, l;
bool vis[mxn];
stack<int> graph[mxn];
vector<int> ans;

void dfs(int node) {
	if (vis[node]) return;
	vis[node] = true;
	ans.push_back(node);
	while (!graph[node].empty()) {
		int u = graph[node].top(); graph[node].pop();
		dfs(u);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n; l = 1 << n;

	for (int i = 0; i < l; i++) {
		int x = (i << 1) & (l - 1);
		int y = x | 1;
		if (x != i) {
			graph[i].push(x);
		}
		if (y != i) {
			graph[i].push(y);
		}
	}

	dfs(0);

	for (int i = n - 1; i >= 0; i--) {
		cout << (ans[0] >> i & 1);
	}

	for (int i = 1; i < ans.size(); i++) {
		cout << (ans[i] & 1);
	}
}