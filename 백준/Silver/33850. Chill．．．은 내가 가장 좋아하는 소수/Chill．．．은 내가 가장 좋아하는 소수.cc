#define ll long long
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long mod = 998'244'353;

    bool flag = 0;
    long long a, b, c, d;
    long long n, m, t, k = 0;
    long long ans = 0;

    cin >> n >> a >> b;
    vector<vector<int>> brd(2, vector<int>(n));

    vector<bool> isprime(200001, 0);

    for(int i=2;i<=200000;i++){
        if(!isprime[i]){
            for(int j=i*2;j<=200000;j+=i){
                isprime[j]=1;
            }
        }
    }

    for(int i=0;i<2;i++){
        for(int j=0;j<n;j++){
            cin>>brd[i][j];
        }
    }

    vector<int> dp(n+1, 0);
    if(!isprime[brd[0][0]+brd[1][0]]){
        dp[1]=a;
    }
    else dp[1]=b;
    
    for(int i=2;i<=n;i++){
        if(!isprime[brd[0][i-1]+brd[1][i-1]]){
            dp[i]=dp[i-1]+a;
        }
        else dp[i]=dp[i-1]+b;

        int tmp=0;
        c=0;
        d=0;
        if(!isprime[brd[0][i-2]+brd[0][i-1]]){
            c++;
        }
        else d++;
        if(!isprime[brd[1][i-2]+brd[1][i-1]]){
            c++;
        }
        else d++;
        tmp=dp[i-2]+a*c+b*d;
        dp[i]=max(dp[i],tmp);
    }
    cout << dp[n];

    return 0;
}