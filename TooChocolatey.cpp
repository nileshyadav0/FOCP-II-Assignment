#include <iostream>
using namespace std;

int main() {
    int T; 
    cin >> T;   //test cases

    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;
        int arr[N];//array of chocolates available
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        for (int i = 0; i < N-1; i++) {
            for (int j = 0; j < N-i-1; j++) {
                if (arr[j] < arr[j+1]) {
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }
        long long alex = 0, bob = 0;
        int turn = 0; 

        for (int i = 0; i < N; i++) {
            int k;
            for (k = 0; k < i; k++) {
                if (arr[k] == arr[i]) {
                    break;
                }
            }
            if (k != i) continue; 
            if (turn == 0) {
                alex += arr[i];
                turn = 1;
            } else {
                bob += arr[i];
                turn = 0;
            }
        }
        if (alex > bob) cout << "Alex\n";
        else cout << "Bob\n";
    }

    return 0;
}
