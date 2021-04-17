#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int mod = 1e9 + 7;
const int mxn = 1e5;
int n, a[mxn + 1]; 
ll fact[mxn + 1];
ll exp(ll x, ll n) {
	ll ans = 1;
	while (n) {
		if (n & 1) {
			ans = (ans * x) % mod;
		}
		x = (x * x) % mod;
		n >>= 1;
	}
	return ans;
}

ll inv(ll n) {
	return exp(n, mod - 2);
}

ll ncr(ll n, ll r) {
	return fact[n] * inv(fact[n - r]) % mod * inv(fact[r]) % mod;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	ll sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
	}

	if (sum % n) {
		cout << 0; 
		return 0;
	}

	fact[0] = 1;
	for (int i = 1; i <= n; i++) {
		fact[i] = fact[i - 1] * i % mod;
	}

	int target = sum / n;
	int l = 0, m = 0, h = 0;
	unordered_map<int, int> mp; 
	mp.reserve(n);

	for (int i = 0; i < n; i++) {
		if (a[i] == target) {
			m++;
		}
		else if (a[i] < target) {
			l++;
			mp[a[i]]++;
		}
		else {
			h++;
			mp[a[i]]++;
		}
	}

	if (l == 0) {
		cout << 1;
		return 0;
	}

	ll ways = fact[l] * fact[h] % mod;
	for (auto it = mp.begin(); it != mp.end(); it++) {
		ways = ways * inv(fact[it->second]) % mod;
	}

	if (l == 1) {
		ways = ways * (h + 1LL) % mod;
	}
	else if (h == 1) {
		ways = ways * (l + 1LL) % mod;
	}
	else {
		ways = ways * 2 % mod;
	}
	cout << ncr(n, m) * ways % mod;
}