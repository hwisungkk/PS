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
    int n, m, t;
    vector<string> v;

    cin >> n;
    vector<int> dp(n+1,0);
    for(int i=1;i<=n;i++){
        cin >> a >> b;
        if(i+a-1 <= n && dp[i+a-1] < dp[i-1] + b){
            dp[i+a-1]=dp[i-1] + b;
        }
        if(dp[i]<=dp[i-1])dp[i]=dp[i-1];
    }
    cout << dp[n];
    
    
    return 0;
}