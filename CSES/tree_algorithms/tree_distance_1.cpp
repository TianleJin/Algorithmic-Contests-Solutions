#include <iostream>
#include <string>
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

// https://cses.fi/problemset/task/1132
// dp on tree
const int mxn = 200005;
int n;
int timer = 0;
vector<int> graph[mxn];
int ans[mxn], fst[mxn], snd[mxn];

int dfs1(int node, int parent = 0) {
	for (int i : graph[node]) {
		if (i != parent) {
			int longest = dfs1(i, node);
			if (longest > fst[node]) {
				snd[node] = fst[node];
				fst[node] = longest;
			}
			else if (longest > snd[node]) {
				snd[node] = longest;
			}
		}
	}
	return fst[node] + 1;
}

void dfs2(int node, int parent = 0, int mx = 0) {
	ans[node] = max(ans[node], mx);
	for (int i : graph[node]) {
		if (i != parent) {
			int mx1;
			if (fst[i] + 1 == fst[node]) {
				mx1 = max(mx + 1, snd[node] + 1);
			}
			else {
				mx1 = max(mx + 1, fst[node] + 1);
			}
			dfs2(i, node, mx1);
		}
	}
}

void solve() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	dfs1(1);

	/*
	for (int i = 1; i <= n; i++) {
		cout << "node " << i << " first: " << fst[i] << endl;
		cout << "node " << i << " second: " << snd[i] << endl;
	}
	*/

	dfs2(1);
	
	for (int i = 1; i <= n; i++) {
		cout << max(fst[i], ans[i]) << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}