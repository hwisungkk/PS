#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int main()
{
    int n, m;
    long long a, b, c, count=0;
    string s;
    vector <pair<pair<string, int>, int>> v;
    int t;
 
    cin >> t;
 
    while(t--){
        cin >> n >>  m;
        cout << n*m/gcd(n,m) << '\n';
    }
 
   
    return 0;
}