#include <iostream>
#include <string>

using namespace std;
int main() {
    string name;
    while (getline(cin, name)) {
        for (char &c : name) {
            if (c == 'i') c = 'e';
            else if (c == 'e') c = 'i';
            else if (c == 'I') c = 'E';
            else if (c == 'E') c = 'I';
        }
        cout << name << '\n';
    }
    return 0;
}