#include <iostream>
using namespace std;

int main() {
    long long L, R;
    cin >> L >> R;
    long long result = 0;
    for (long long i = L; i <= R; i++) {
        result = result ^ i;  
    }
	  if (result % 2 == 0) {
        cout << "even";
    } else {
        cout << "odd";
    }

    return 0;
}
