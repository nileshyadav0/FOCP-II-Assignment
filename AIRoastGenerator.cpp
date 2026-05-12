#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <chrono>

using namespace std;

int main() {
    string name;
    cout << "Enter your name: ";
    getline(cin, name);

    // List of roasts
    vector<string> roasts = {
        "'s debugging technique is staring at the screen until the bug gets embarrassed and runs away.",
        " thinks semicolons are optional… like showering.",
        " once tried to fix a bug by yelling at the computer. Spoiler: it didn’t work.",
        " writes code so confusing even Google asks for clarification.",
        " thinks recursion is when you curse repeatedly at your code.",
        " believes version control means saving files as final_final_v2_reallyfinal.cpp.",
        " treats compiler errors like inspirational quotes.",
        " thinks binary search is looking for snacks in two cupboards.",
        " believes multithreading is just gossiping with multiple friends at once.",
        " once declared a variable and immediately forgot what it was for."
    };

    // Better seeding: mix random_device with current time
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    mt19937 gen(seed);
    uniform_int_distribution<> dist(0, roasts.size() - 1);

    // Pick a random roast
    int index = dist(gen);
    cout << name << roasts[index] << endl;

    return 0;
}
