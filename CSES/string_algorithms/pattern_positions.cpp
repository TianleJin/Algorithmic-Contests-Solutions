#include <iostream>
#include <algorithm>
#include <string>
#include <assert.h>
using namespace std;

const int mxn = 1e5;
int n, q, gap, rnk[mxn], tmp[mxn], sa[mxn], lcp[mxn], seg[2 * mxn];
string s, p;

bool comp(int i, int j) {
    if (rnk[i] != rnk[j]) return rnk[i] < rnk[j];
    i += gap; j += gap;
    return i < n && j < n ? rnk[i] < rnk[j] : i > j;
}

void build() {
    for (int i = 0; i < n; i++) {
        seg[i + n] = sa[i];
    }

    for (int i = n - 1; i; i--) {
        seg[i] = min(seg[2 * i], seg[2 * i + 1]);
    }
}

int query(int l, int r) {
    int i = 2 * n;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) {
            i = min(i, seg[l++]);
        }
        if (r & 1) {
            i = min(i, seg[--r]);
        }
    }
    return i;
}

int lowerbound(string& p) {
    int lo = 0, hi = n - 1;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (p <= s.substr(sa[mid], p.size())) hi = mid;
        else lo = mid + 1;
    }
    return lo;
}

int upperbound(string& p) {
    int lo = 0, hi = n - 1;
    while (lo < hi) {
        int mid = (lo + hi + 1) / 2;
        if (p >= s.substr(sa[mid], p.size())) lo = mid;
        else hi = mid - 1;
    }
    return lo;
}

int main() {
    cin >> s;
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

    for (int i = 0, k = 0; i < n; i++) {
        if (rnk[i] != n - 1) {
            int j = sa[rnk[i] + 1];
            while (i + k < n && j + k < n && s[i + k] == s[j + k]) k++;
            lcp[rnk[i]] = k;
            if (k) --k;
        }
    }

    build();

    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> p;
        int l = lowerbound(p), r = upperbound(p);
        if (l > r || p != s.substr(sa[l], p.size())) cout << -1 << '\n';
        else cout << query(l, r + 1) + 1 << '\n';
    }
}
