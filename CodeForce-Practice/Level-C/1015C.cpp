// Songs Compression
# include <iostream>
# include <algorithm>
# include <array>
typedef long long int ll;
using namespace std;


bool comp(int a, int b) { return a > b; }

int n, m; 
std::array<int, 100000> a;
int main() {
    std::cin >> n >> m;

    int x, y; 
    ll sum = 0;
    for (int i=0; i<n; i++) {
        cin >> x >> y;
        sum += (ll) x;
        a[i] = x - y;
    } 

    if (sum <= m) {
        cout << 0 << '\n';
        return 0;
    }

    std::sort(a.begin(), a.begin() + n, comp);

    for (int i=0; i<n; i++) {
        sum -= (ll) a[i];
        if (sum <= m) {
            cout << i + 1 << '\n';
            return 0;
        }
    }

    std::cout << -1 << '\n';
    return 0;
}
