#include <iostream>
#define ll long long
using namespace std;

int T, N;
int a[100000];
int main() {
	// your code goes here
	cin >> T;
	while (T--) {
	    cin >> N;
	    for (int i=0; i<N; i++) {
	        cin >> a[i];
	    }
	    for (int i=0; i<N; i++) {
	        if (a[i] < 0) {
	            a[i] = -a[i];
	        }
	        a[i] = a[i] % 4;
	    }
	    ll ans = 0; 
	    int zero = -1; int two = -1; int one = 0; int curr = 1;
	    for (int i=0; i<N; i++) {
	        curr = (curr * a[i]) % 4;
	        if (curr == 0) {
	            if (a[i] == 0) {
	                ans += i + 1;
	                zero = i;
	                two = -1;
	                curr = 1;
	            } else if (a[i] == 2) {
	                ans += two + 1;
	                zero = two;
	                two = i;
	                curr = 2;
	            }
	            one = 0;
	            continue;
	        } else if (curr == 2) {
	            if (a[i] == 2) {
	                two = i;
	                one = 0;
	            } else {
	                one++;
	                ans += one;
	            }
	        } else {
	            one++;
	            ans += one;
	        }
	        if (zero != -1) {
	            ans += zero + 1;
	        }
	    }
	    cout << ans << '\n';
	}
	return 0;
}