#include <vector>
#include <map>
#include <algorithm>
using namespace std;


class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& res) {
        map<int, int> mp; 
        mp[0] = 0;
        
        for (int i = 0; i < res.size(); i++) {
            --res[i][0];
            swap(res[i][0], res[i][1]);
        }
        
        sort(res.begin(), res.end());
        
        for (int i = 0; i < res.size(); i++) {
            int h = res[i][0], x = res[i][1];
            auto it = mp.upper_bound(x);
            if (it != mp.end()) {
                h = min(h, it->second + it->first - x);
            }
            if (it != mp.begin()) {
                --it;
                h = min(h, it->second + x - it->first);
            }
            mp[x] = h;
        }
        
        int ans = 0;
        auto it1 = mp.begin(), it2 = mp.begin(); ++it2; 
        while (it2 != mp.end()) {
            int x1 = it1->first, x2 = it2->first, h1 = it1->second, h2 = it2->second;
            int diff = abs(h2 - h1);
            int gaps = x2 - x1 - 1;
            if (diff >= gaps) {
                ans = max(ans, max(h1, h2));
            }
            else {
                ans = max(ans, max(h1, h2) + (x2 - x1 - diff) / 2);
            }
            ++it1; ++it2;
        }
        return max(ans, it1->second + n - it1->first - 1);
    }
};