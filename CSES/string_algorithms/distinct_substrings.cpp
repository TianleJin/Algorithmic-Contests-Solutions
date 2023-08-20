#include <iostream>
#include <algorithm>
#include <string>
#include <assert.h>
using namespace std;

const int mxn = 1e5;
int n, gap, rnk[mxn], tmp[mxn], sa[mxn], lcp[mxn];
string s;

bool comp(int i, int j) {
    if (rnk[i] != rnk[j]) return rnk[i] < rnk[j];
    i += gap; j += gap;
    return i < n && j < n ? rnk[i] < rnk[j] : i > j;
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
    
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += n - sa[i] - lcp[i];
    }
    cout << ans << endl;
}