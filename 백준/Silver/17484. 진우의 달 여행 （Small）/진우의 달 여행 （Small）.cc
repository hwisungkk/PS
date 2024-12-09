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
long long mi = 1e16;
int total=0;
int main()
{
    ios_base ::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, k;
    long long a, b, c;

    a=0;
    int d;
    cin >> n >> m;
    int ar[102][102]={0};
    int dp[102][300][3];

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> ar[i][j];
            for(int k=0;k<3;k++){
                if(j==1 && k==0)dp[i][j][k]=1e9;
                else if(j==m && k==2)dp[i][j][k]=1e9;
                else dp[i][j][k]  =ar[i][j];
            }
        }
    }
    for(int i=2;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(j>1)
                dp[i][j][0] = min(dp[i-1][j-1][1], dp[i-1][j-1][2]) + dp[i][j][0];
            dp[i][j][1] = min(dp[i-1][j][0], dp[i-1][j][2]) + dp[i][j][1];
            if(j<m)
                dp[i][j][2] = min(dp[i-1][j+1][0], dp[i-1][j+1][1]) + dp[i][j][2];

        }
        dp[i][1][0] = 1e9;
        dp[i][m][2] = 1e9;
    }
    int mi = 1e9;
    for(int j=1;j<=m;j++){
        for(int k=0;k<3;k++){
            //cout << dp[i][j][k] << ' ';
            mi = min(mi, dp[n][j][k]);
        }
    }
    cout << mi;
    /*
5 8 5 1
3 5 8 4
9 77 65 5
2 1 5 2
5 98 1 5
4 95 67 58
------------------
100 5 5 / 8 8 8 / 5 5 5 / 1 1 100
100 3 3 / 5 5 5 / 8 8 8 / 4 4 100

    */

    
    return 0;
}