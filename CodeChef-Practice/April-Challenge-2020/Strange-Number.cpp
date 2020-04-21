#include <iostream>
#include <cmath>
using namespace std;


int solve(int N, int K) {
    if ((N % 2 == 0 && K >= 30) || (N % 2 == 1 && K >= 19)) {
        return 0;
    }
    
    int cnt = 0;
    for(int i=2; i<=floor(sqrt(N)); i++) {
        while (N % i == 0) {
            N /= i;
            cnt++;
        }
        if (cnt >= K) {
            return 1;
        } 
        if (N == 1) {
            break;
        }
    }
    if (N > 1) {
        cnt++;
    }
    return cnt >= K ? 1: 0;
}


int main() {
	// your code goes here
	int T, N, K;
	cin >> T;
	for (int i=0; i<T; i++) {
	    cin >> N >> K;
	    cout << solve(N, K) << '\n';
	}
	return 0;
}
