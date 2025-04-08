#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long a;
    cin >> a;
    
    double r = sqrt(a / 3.1415926535);
    double len = 2 * 3.1415926535 * r;
    
    cout.precision(9);
    cout << fixed << len << '\n';
    
    return 0;
}