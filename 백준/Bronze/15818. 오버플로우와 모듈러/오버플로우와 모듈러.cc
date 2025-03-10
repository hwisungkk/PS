#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <queue>
#include <set>
#include <algorithm>
#include <math.h>
using namespace std;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int a, b, c, d;
    long long n, m, t;
    cin >> n >> m;
    long long ans=1;
    for(int i=0;i<n;i++){
        cin >> t;
        ans = ans * (t%m);
        ans%=m;
    }
    cout << ans;
    
    return 0;
}