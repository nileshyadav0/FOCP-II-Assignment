#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    string bulbs;
    cin >> bulbs;

    int low = 1, high = n, ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;

        int ops = 0;

        // count operations using only for loop + if
        for (int i = 0; i < n; ) {
            if (bulbs[i] == '1') {
                ops++;
                i += mid;  // skip l bulbs
            } else {
                i++;
            }
        }

        if (ops <= k) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << ans << endl;
    return 0;
}
