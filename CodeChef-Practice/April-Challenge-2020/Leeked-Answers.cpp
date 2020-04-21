#include <iostream>
#include <array>
using namespace std;

int T, N, M, K;
int a[500][5000];
int main() {
	// your code goes here
	cin >> T;
	while (T--) {
	    cin >> N >> M >> K;
	    for (int n=0; n<N; n++) {
	        for (int k=0; k<K; k++) {
	            cin >> a[n][k];
	        }
	    }
	    
	    for (int n=0; n<N; n++) {
	        int b[M + 1];
	        for (int m=0; m<=M; m++) {
	            b[m] = 0;
	        }
	        
	        for (int k=0; k<K; k++) {
	            b[a[n][k]]++;
	        }
	        
	        int ans = 0, highest = 0;
	        for (int m=1; m<=M; m++) {
	            if (b[m] > highest) {
	                highest = b[m];
	                ans = m;
	            }
	        }
	        
	        cout << ans << ' ';
	    }
	}
	return 0;
}
