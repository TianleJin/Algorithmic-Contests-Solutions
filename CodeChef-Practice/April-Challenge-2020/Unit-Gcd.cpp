#include <iostream>
using namespace std;

int T, N;
int main() {
	// your code goes here
	cin >> T;
	while (T--) {
	    cin >> N;
	    if (N == 1) {
	        cout << 1 << '\n';
	        cout << 1 << ' ' << 1 << '\n';
	        continue;
	    }
	    cout << N / 2 << '\n';
	    if (N % 2) {
	        cout << 3 << ' ' << 1 << ' ' << 2 << ' ' << N << '\n'; 
	    } else {
	        cout << 2 << ' ' << 1 << ' ' << 2 << '\n'; 
	    }
	    for (int i=1; i<N/2; i++) {
	        cout << 2 << ' ' << 2 * i + 1 << ' ' << 2 * i + 2 << '\n';
	    }
	}
	return 0;
}