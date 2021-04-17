#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int mxn = 2e5;
const int mod = 1e9 + 7;
ll fact[mxn + 1];
ll exp(ll x, ll n) {
	ll ans = 1;
	while (n) {
		if (n & 1) {
			ans = ans * x % mod;
		}
		x = x * x % mod;
		n >>= 1;
	}
	return ans;
}

ll inv(ll x) {
	return exp(x, mod - 2);
}

ll ncr(ll n, ll r) {
	return fact[n] * inv(fact[r]) % mod * inv(fact[n - r]) % mod;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	fact[0] = 1;
	for (int i = 1; i <= mxn; i++) {
		fact[i] = fact[i - 1] * i % mod;
	}

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		
		int sum = a[0];
		for (int i = 1; i < n; i++) {
			sum = sum & a[i];
		}
		
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] == sum) {
				cnt++;
			}
		}

		if (cnt < 2) {
			cout << 0 << endl;
			continue;
		}

		cout << (ll)cnt * ((ll)cnt - 1) % mod * fact[n - 2] % mod << endl;
	}
}