#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <stack>
#include <set>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;
long long maxi=0;
int n;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a, b, c, m, k;
    int t;

    cin >> a >> b;
    vector<vector<int>>dp(a+2, vector<int>(b+2, 0));
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            cin >> dp[i][j];
        }
    }
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            dp[i][j]=max({dp[i-1][j-1], dp[i-1][j], dp[i-1][j+1]})+dp[i][j];
        }
    }
    int ans=-1;
    for(int i=1;i<=b;i++){
        if(ans<dp[a][i])ans=dp[a][i];
    }cout<<ans;
    return 0;
}
