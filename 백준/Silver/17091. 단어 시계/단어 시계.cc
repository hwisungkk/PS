#include <iostream>
#include <string>
using namespace std;

int main() {
    string timeWords[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", 
                          "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", 
                          "nineteen", "twenty", "twenty one", "twenty two", "twenty three", "twenty four", 
                          "twenty five", "twenty six", "twenty seven", "twenty eight", "twenty nine", "half"};
    int h, m;
    cin >> h >> m;

    if (m == 0) {
        cout << timeWords[h - 1] << " o' clock" << endl;
    } else if (m == 15) {
        cout << "quarter past " << timeWords[h - 1] << endl;
    } else if (m == 30) {
        cout << "half past " << timeWords[h - 1] << endl;
    } else if (m == 45) {
        cout << "quarter to " << timeWords[h % 12] << endl;
    } else if (m < 30) {
        if (m == 1) {
            cout << "one minute past " << timeWords[h - 1] << endl;
        } else {
            cout << timeWords[m - 1] << " minutes past " << timeWords[h - 1] << endl;
        }
    } else {
        m = 60 - m;
        if (m == 1) {
            cout << "one minute to " << timeWords[h % 12] << endl;
        } else {
            cout << timeWords[m - 1] << " minutes to " << timeWords[h % 12] << endl;
        }
    }

    return 0;
}