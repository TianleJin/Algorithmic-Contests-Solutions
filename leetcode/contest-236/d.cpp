#include <deque>
#include <multiset>


class MKAverage {
public:
    int m, k, n;
    long long tot;
    deque<int> dq;
    multiset<int> s1, s2, s3;
    MKAverage(int _m, int _k) {
        tot = 0;
        m = _m;
        k = _k;
        n = m - 2 * k;
    }
    
    void addElement(int num) {
        dq.push_back(num);
        if (dq.size() > m) {
            int num1 = dq.front(); dq.pop_front();
            if (s1.find(num1) != s1.end()) {
                s1.erase(s1.find(num1));
            }
            else if (s2.find(num1) != s2.end()) {
                s2.erase(s2.find(num1));
                tot -= num1;
            }
            else if (s3.find(num1) != s3.end()) {
                s3.erase(s3.find(num1));
            }
        }
        
        s2.insert(num);
        tot += num;
        
        if (dq.size() < m) {
            return;
        }
        
        while (s1.size() && s2.size()) {
            auto it1 = s1.end(); --it1;
            auto it2 = s2.begin();
            int num1 = *it1;
            int num2 = *it2;
            if (num2 < num1) {
                s1.erase(it1);
                s2.erase(it2);
                s1.insert(num2);
                s2.insert(num1);
                tot += num1;
                tot -= num2;
            }
            else {
                break;
            }
        }
        
        while (s2.size() && s3.size()) {
            auto it2 = s2.end(); --it2;
            auto it3 = s3.begin();
            int num2 = *it2;
            int num3 = *it3;
            if (num3 < num2) {
                s2.erase(it2);
                s3.erase(it3);
                s2.insert(num3);
                s3.insert(num2);
                tot += num3;
                tot -= num2;
            }
            else {
                break;
            }
        }
        
        while (s3.size() > k) {
            auto it = s3.begin();
            int num3 = *it;
            tot += num3;
            s2.insert(num3);
            s3.erase(it);
        }
        
        while (s1.size() > k) {
            auto it = s1.end(); --it;
            int num1 = *it;
            tot += num1;
            s2.insert(num1);
            s1.erase(it);
        }
        
        while (s3.size() < k) {
            auto it = s2.end(); --it;
            int num2 = *it;
            tot -= num2;
            s3.insert(num2);
            s2.erase(it);
        }
        
        while (s1.size() < k) {
            auto it = s2.begin();
            int num2 = *it;
            tot -= num2;
            s1.insert(num2);
            s2.erase(it);
        }
    }

    int calculateMKAverage() {
        return dq.size() < m ? -1 : tot / n;
    }
};