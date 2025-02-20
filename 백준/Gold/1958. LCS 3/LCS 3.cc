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
    
    int n, m, t;
    int a, b, c;
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    int dp[101][101][101]={0};

    a = s1.size();
    b = s2.size();
    c = s3.size();

    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            for(int k=1;k<=c;k++){
                if(s1[i-1]==s2[j-1] && s2[j-1]==s3[k-1]){
                    dp[i][j][k] = dp[i-1][j-1][k-1]+1;
                }
                else{
                    dp[i][j][k] = max({dp[i-1][j][k], dp[i-1][j-1][k], dp[i][j-1][k], dp[i-1][j][k-1], 
                        dp[i][j][k-1], dp[i][j-1][k-1]});
                }
            }
        }
    }
    cout << dp[a][b][c];
    return 0;
}