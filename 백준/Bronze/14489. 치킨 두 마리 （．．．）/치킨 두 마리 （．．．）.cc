#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <functional>
#include <algorithm>
#include <math.h>
#include <map>
using namespace std;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int a, b, c, d;
    int n, m, t;
    char ch;
    string s;
    int ans=0;
    bool flag=0;

    long long aa, bb, cc;
    cin >> aa >> bb >> cc;
    if(aa+bb-cc*2 >= 0) cout << aa+bb-cc*2;
    else cout << aa+bb;
    

    return 0;
}