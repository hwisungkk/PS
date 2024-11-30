#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;

using namespace std;

int main()
{
    char c1, c2, c3, c4;
    int score1 = 0, score2 = 0;

    cin >> c1 >> c2 >> c3 >> c4;

    auto d = [](char choice1, char choice2) -> int {
        if (choice1 == 'R') {
            if (choice2 == 'S') return 0;
            else if (choice2 == 'R') return 2;
            else return 1;
        }
        if (choice1 == 'S') {
            if (choice2 == 'P') return 0;
            else if (choice2 == 'S') return 2;
            else return 1;
        }
        if (choice1 == 'P') {
            if (choice2 == 'R') return 0;
            else if (choice2 == 'P') return 2;
            else return 1;
        }
        return 2;
    };

    if (d(c1, c3) == 0) score1++;
    if (d(c1, c3) == 1) score2++;

    if (d(c1, c4) == 0) score1++;
    if (d(c1, c4) == 1) score2++;

    if (d(c2, c3) == 0) score1++;
    if (d(c2, c3) == 1) score2++;

    if (d(c2, c4) == 0) score1++;
    if (d(c2, c4) == 1) score2++;

    if (c1 != c2 && c3 != c4) {
        if (score1 > 0 && score2 > 0)
            cout << "?" << endl;
        if (score1 == 4)
            cout << "MS" << endl;
        if (score2 == 4)
            cout << "TK" << endl;
    }
    else {
        if (c1 == c2 && score2 > 0)
            cout << "TK" << endl;
        else if (c3 == c4 && score1 > 0)
            cout << "MS" << endl;
        else
            cout << "?" << endl;
    }

    return 0;
}