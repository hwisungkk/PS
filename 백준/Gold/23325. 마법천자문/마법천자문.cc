#define ll long long
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long mod = 1'000'000'007;

    bool flag = 0;
    long long a, b, c, d;
    long long n, m, t, k = 0;
    long long ans = 0;

    string s;
    cin >> s;

    vector<vector<int>> dp(2, vector<int>(s.size(), -1e8)); //0은 숫자, 1은 부호

    if(s[0]=='-')dp[0][0]=1;
    if(s[0]=='+')dp[0][0]=10;

    for(int i=1;i<s.size();i++){
        dp[1][i]=dp[0][i-1];

        if(dp[1][i-1]!=-1e8){
            if(s[i-1]=='+'){
                if(s[i]=='+'){
                    dp[0][i]=dp[1][i-1]+10;
                }
                else{
                    dp[0][i]=dp[1][i-1]+1;
                }
            }
            else{
                if(s[i]=='+'){
                    dp[0][i]=dp[1][i-1]-10;
                }
                else dp[0][i]=dp[1][i-1]-1;
            }
        }
        if(i>=1 && s[i]=='-' && s[i-1]=='+'){
            if(i==1)dp[0][1]=11;
            else if(s[i-2]=='+'){
                dp[0][i]=max(dp[0][i], dp[1][i-2]+11);
            }
            else{
                dp[0][i]=max(dp[0][i], dp[1][i-2]-11);
            }
        }
    }
    // for(int i=0;i<s.size();i++){
    //     cout << dp[0][i] << ' ';
    // }cout<<'\n';
    // for(int i=0;i<s.size();i++){
    //     cout << dp[1][i] << ' ';
    // }
    cout << dp[0][s.size()-1];

    return 0;
}