#include <iostream>
#include <vector>
#include <string>
#include <algorithm>   // for shuffle
#include <random>      // for mt19937
#include <chrono>      // for system_clock

using namespace std;

int main() {
    string name;
    cout << "Enter student name: ";
    getline(cin, name);

    vector<string> excuses = {
        "'s laptop crashed last night.",
        "'s file got accidentally deleted.",
        "'s internet was down at home.",
        " was sick and couldn’t focus.",
        "'s dog chewed up the notes.",
        " had a family emergency.",
        " misunderstood the deadline.",
        " left the notebook at school.",
        "'s printer ran out of ink.",
        " was helping a friend in need.",
        " had too many assignments at once.",
        " thought the assignment was already submitted.",
        " lost track of time.",
        " was stuck on a bug in the code.",
        " had a power outage at home."
    };

    // Use time-based seed for variety across runs
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    mt19937 gen(seed);

    // Shuffle the excuses
    shuffle(excuses.begin(), excuses.end(), gen);

    // Print the first excuse from the shuffled list
    cout << "\n" << name << excuses[0] << endl;

    return 0;
}
