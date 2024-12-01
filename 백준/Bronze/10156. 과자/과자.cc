#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;
int al = 0;
int main()
{
    ios_base ::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    long long a, b, c, total = 0;
    long long n, k = -1;
    int m;
    int t;
    string s1, s2;
    cin >> a >> b >> c;
    if(a*b>c)cout<<a*b-c;
    else cout << '0';
    return 0;
}