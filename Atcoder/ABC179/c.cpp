#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <array>
#include <map>
#include <set>
#include <string>
#include <deque>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <assert.h>
#include <sstream>
typedef long long ll;
#define vi vector<int>
using namespace std;


int count(int x) {
	int i;
	int cnt = 0;
	for (i = 1; i * i < x; i++) {
		if (x % i == 0) {
			cnt += 2;
		}
	}
	return i * i == x ? cnt + 1 : cnt;
}


int main() {
	int N;
	cin >> N;
	ll ans = 0;
	for (int i = 1; i < N; i++) {
		ans += count(i);
	}
	cout << ans << '\n';
}
