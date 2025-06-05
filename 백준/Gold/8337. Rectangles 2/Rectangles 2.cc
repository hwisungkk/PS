#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <functional>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <map>
using namespace std;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long mod = 1e9+7;
        
    bool flag=0; 
    int a, b, c, d;
    long long n, m, t, k;
    long long ans = 0;
    int cur = 0;

    cin >> n;

    for(int i=1;i<=sqrt(n);i++){
        ans += (n/i-i+1);
    }
    cout << ans;

    return 0;
}

