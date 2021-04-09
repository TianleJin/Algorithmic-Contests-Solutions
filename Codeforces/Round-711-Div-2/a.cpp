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

ll gcd(ll x, ll y) {
	while (y) {
		ll tmp = x % y;
		x = y;
		y = tmp;
	}
	return x;
}

bool chk(ll x) {
	ll sum = 0;
	ll y = x;
	while (y) {
		sum += y % 10;
		y /= 10;
	}
	return gcd(x, sum) > 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		ll n;
		cin >> n;
		for (ll i = n; i < n + 3; i++) {
			if (chk(i)) {
				cout << i << endl;
				break;
			}
		}
	}
}