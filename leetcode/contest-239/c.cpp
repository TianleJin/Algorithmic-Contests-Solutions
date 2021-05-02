#include <string>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int getMinSwaps(string num, int k) {
        int n = num.size();
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            arr[i] = num[i];
        }
        
        for (int i = 0; i < k; i++) {
            next_permutation(arr.begin(), arr.end());
        }
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (num[i] != arr[i]) {
                bool found = false;
                for (int j = i + 1; !found && j < n; j++) {
                    if (num[j] == arr[i]) {
                        found = true;
                        while (j > i) {
                            swap(num[j - 1], num[j]);
                            ans++;
                            j--;
                        }
                    }
                }
            }
        }
        return ans;
    }
};