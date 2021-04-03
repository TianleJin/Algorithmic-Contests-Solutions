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
 
const int dx4[] = { -1, 0, 1, 0 };
const int dy4[] = { 0, -1, 0, 1 };
const int dx8[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
const int dy8[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
 
// https://cses.fi/problemset/task/2079
const int mxn = 200005;
int n;
vector<int> graph[mxn];
int subtree[mxn];
 
int get_subtree_size(int node, int parent = 0) {
	subtree[node] = 1;
	for (int i : graph[node]) {
		if (i != parent) {
			subtree[node] += get_subtree_size(i, node);
		}
	}
	return subtree[node];
}
 
int get_centroid(int desired, int node, int parent = 0) {
	for (int i : graph[node]) {
		if (i != parent && subtree[i] > desired) {
			return get_centroid(desired, i, node);
		}
	}
	return node;
}
 
void solve() {
	cin >> n;
	for (int i = 0; i + 1 < n; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	cout << get_centroid(get_subtree_size(1) / 2, 1) << endl;
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}