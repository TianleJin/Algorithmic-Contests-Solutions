#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <assert.h>
using namespace std;

const int mxn = 1e5;
int n, gap, rnk[mxn], tmp[mxn], sa[mxn], lcp[mxn];
long long k;
string s;

bool comp(int i, int j) {
    if (rnk[i] != rnk[j]) return rnk[i] < rnk[j];
    i += gap; j += gap;
    return i < n && j < n ? rnk[i] < rnk[j] : i > j;
}

long long enumerate(int i, int l) {
    vector<int> dp(i + 1); 
    dp[i] = l;

    for (int j = i - 1, cp = l; j >= 0; j--) {
        cp = min(cp, lcp[j]);
        if (cp < l) {
            dp[j] = n - sa[j];
        }
        else {
            dp[j] = cp;
        }
    }
    
    long long ans = l;
    for (int j = 0; j < i; j++) {
        ans += max(0, dp[j] - min(dp[j + 1], lcp[j]));
    }
    return ans;
}

int bs1() {
    int lo = 0, hi = n - 1;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (enumerate(mid, n - sa[mid]) >= k) {
            hi = mid;
        }
        else {
            lo = mid + 1;
        }
    }
    return lo;
}

int bs2(int idx) {
    int lo = 1, hi = n - sa[idx];
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (enumerate(idx, mid) >= k) {
            hi = mid;
        }
        else {
            lo = mid + 1;
        }
    }
    return lo;
}

int main() {
    cin >> s >> k;
    n = s.size();
    
    for (int i = 0; i < n; i++) sa[i] = i;
    for (int i = 0; i < n; i++) rnk[i] = s[i] - 'a';
    
    for (gap = 1;; gap *= 2) {
        sort(sa, sa + n, comp);
        tmp[0] = 0;
        for (int i = 1; i < n; i++) tmp[i] = tmp[i - 1] + comp(sa[i - 1], sa[i]);
        for (int i = 0; i < n; i++) rnk[sa[i]] = tmp[i];
        if (tmp[n - 1] == n - 1) break;
    }

    for (int i = 0, l = 0; i < n; i++) {
        if (rnk[i] != n - 1) {
            int j = sa[rnk[i] + 1];
            while (i + l < n && j + l < n && s[i + l] == s[j + l]) l++;
            lcp[rnk[i]] = l;
            if (l) --l;
        }
    }

    int idx = bs1();
    int len = bs2(idx);
    cout << s.substr(sa[idx], len) << "\n";
}