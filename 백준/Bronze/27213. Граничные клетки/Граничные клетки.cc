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
    int n, m, t, k;
    bool flag=0; 

    string s;

    cin >> n >> m;
    if(n<=2 || m<=2)cout << n*m;
    else cout << n+m+n+m-4;

    return 0;
}
