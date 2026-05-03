#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Account {
    string userID;
    long long balance;
};

class Bank {
private:
    vector<Account> accounts;

    // helper to find index of userID
    int findUser(string X) {
        for (int i = 0; i < accounts.size(); i++) {
            if (accounts[i].userID == X) return i;
        }
        return -1; // not found
    }

public:
    int CREATE(string X, long long Y) {
        int idx = findUser(X);
        if (idx == -1) {
            accounts.push_back({X, Y});
            return 1; // new account created
        } else {
            accounts[idx].balance += Y;
            return 0; // existing account updated
        }
    }

    int DEBIT(string X, long long Y) {
        int idx = findUser(X);
        if (idx == -1) return 0;
        if (accounts[idx].balance < Y) return 0;
        accounts[idx].balance -= Y;
        return 1;
    }

    int CREDIT(string X, long long Y) {
        int idx = findUser(X);
        if (idx == -1) return 0;
        accounts[idx].balance += Y;
        return 1;
    }

    long long BALANCE(string X) {
        int idx = findUser(X);
        if (idx == -1) return -1;
        return accounts[idx].balance;
    }
};

int main() {
    int Q;
    cin >> Q;
    Bank bank;

    while (Q--) {
        string query;
        cin >> query;

        if (query == "CREATE") {
            string X; long long Y;
            cin >> X >> Y;
            cout << bank.CREATE(X, Y) << endl;
        }
        else if (query == "DEBIT") {
            string X; long long Y;
            cin >> X >> Y;
            cout << bank.DEBIT(X, Y) << endl;
        }
        else if (query == "CREDIT") {
            string X; long long Y;
            cin >> X >> Y;
            cout << bank.CREDIT(X, Y) << endl;
        }
        else if (query == "BALANCE") {
            string X;
            cin >> X;
            cout << bank.BALANCE(X) << endl;
        }
    }

    return 0;
}
