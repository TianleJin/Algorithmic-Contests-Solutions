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
const int dxknight[] = { -1, -1, -2, -2, 1, 1, 2, 2 };
const int dyknight[] = { 2, -2, 1, -1, 2, -2, 1, -1 };

const int mxn = 200005;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
        int n;
        string a, b;
        cin >> n >> a >> b;
        a.push_back('0');
        b.push_back('0');
        bool ok = 1;
        int cnt = 0;
        for (int i = 0; i < n && ok; i++) {
            cnt += (a[i] == '1') - (a[i] == '0');
            if ((a[i] == b[i]) != (a[i + 1] == b[i + 1]) && cnt != 0) {
                ok = 0;
            }
        }
        if (ok) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
	}
}