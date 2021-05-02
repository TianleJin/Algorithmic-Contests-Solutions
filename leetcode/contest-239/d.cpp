#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int inf = 1e9;
    int mxn, seg[20000002];
    void update(int l, int r, int val) {
        for (l += mxn, r += mxn; l < r; l >>= 1, r >>= 1) {
            if (l & 1) {
                seg[l] = min(seg[l], val);
                l++;
            }
            if (r & 1) {
                r--;
                seg[r] = min(seg[r], val);
            }
        }
    }
    
    int query(int num) {
        if (num > mxn) {
            return -1;
        }
        
        int ans = inf;
        for (num += mxn; num; num >>= 1) {
            ans = min(ans, seg[num]);
        }
        return ans == inf ? -1 : ans;
    }
    
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        mxn = 0;
        for (auto& interval : intervals) {
            mxn = max(mxn, interval[0] + 1);
            mxn = max(mxn, interval[1] + 1);
        }
        
        for (int i = 0; i < mxn << 1; i++) {
            seg[i] = inf;
        }
        
        for (auto& interval : intervals) {
            update(interval[0], interval[1] + 1, interval[1] - interval[0] + 1);
        }
        
        int n = queries.size();
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = query(queries[i]);
        }
        return ans;
    }
};