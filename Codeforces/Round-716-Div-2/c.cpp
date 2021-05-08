#include <iostream>
#include <array>
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


int gcd(int x, int y) {
	int r;
	while (y) {
		r = x % y;
		x = y;
		y = r;
	}
	return x;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; 
	cin >> n;

	ll mod = 1;
	vector<int> ans;
	for (ll i = 1; i < n; i++) {
		if (gcd(i, n) == 1) {
			if (i * i % n == 1) {
				mod = mod * i % n;
			}
			ans.push_back(i);
		}
	}
		
	if (mod == 1) {
		cout << ans.size() << endl;
		for (int x : ans) {
			cout << x << ' ';
		}
	}
	else {
		cout << ans.size() - 1 << endl;
		for (int x : ans) {
			if (x + 1 != n) {
				cout << x << ' ';
			}
		}
	}
}