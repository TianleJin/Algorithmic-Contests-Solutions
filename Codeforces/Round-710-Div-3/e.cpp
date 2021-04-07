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

void getMax(int n, vector<int>& p) {
	set<int> st;
	for (int i = 1; i <= n; i++) {
		st.insert(i);
	}

	vector<int> ans(n);
	int mx = 0;
	for (int i = 0; i < n; i++) {
		if (p[i] > mx) {
			ans[i] = p[i];
			st.erase(st.find(p[i]));
		}
		else {
			auto it = st.lower_bound(mx); --it;
			ans[i] = *it;
			st.erase(it);
		}
		mx = p[i];
	}

	for (int i = 0; i < n; i++) {
		cout << ans[i] << ' ';
	}
	cout << endl;
}

void getMin(int n, vector<int>& p) {
	set<int> st;
	for (int i = 1; i <= n; i++) {
		st.insert(i);
	}

	vector<int> ans(n);
	int mx = 0;
	for (int i = 0; i < n; i++) {
		if (p[i] > mx) {
			ans[i] = p[i];
			st.erase(st.find(p[i]));
		}
		else {
			auto it = st.begin();
			ans[i] = *it;
			st.erase(it);
		}
		mx = p[i];
	}

	for (int i = 0; i < n; i++) {
		cout << ans[i] << ' ';
	}
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<int> p(n);
		for (int i = 0; i < n; i++) {
			cin >> p[i];
		}
		getMin(n, p);
		getMax(n, p);
	}
}