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
typedef long long ll;
#define pi pair<int, int>
#define pl pair<ll, ll>
#define vi vector<int>
#define vii vector<vi>
#define viii vector<vii>
#define vl vector<ll>
#define vll vector<vl>
#define vlll vector<vll>
using namespace std;


int main() {
	int n;
	cin >> n;
	vl A(n);
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	ll ans = 1e14;
	for (int i = 0; i <= 100000; i++) {
		ll cost = 0;
		ll curr = 1;
		for (int j = 0; j < n; j++) {
			cost += abs(A[j] - curr);
			if (cost > 1e14) break;
			curr *= i;
		}
		if (cost > 1e14) break;
		ans = min(ans, cost);
	}
	cout << ans << '\n';
}