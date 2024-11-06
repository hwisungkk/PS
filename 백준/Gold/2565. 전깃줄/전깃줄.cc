#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include<math.h>
using namespace std;
int al=0;
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a, b, c, total=0;
    long long count=0;
    int ma = -1000;
    long long n, m, k=-1;
    int dp[101]={0};
    vector <vector <int>>kc;
    cin >> n;
    kc.push_back({0,0});
    for(int i=1;i<=n;i++){
        cin >> a >> b;
        kc.push_back({a,b});
    }
    dp[1]=1;
    sort(kc.begin(), kc.end());
    for(int i=2;i<=n;i++){
        for(int j=1;j<i;j++){
            if((kc[i][1]>kc[j][1])){
                if(dp[i] < dp[j]+1)
                    dp[i] = dp[j]+1;
            }
        }
        if(dp[i]==0)dp[i]=1;
    }
    for(int i=1;i<=n;i++){
        //cout << dp[i] << '\n';
        if(ma<dp[i])ma=dp[i];
    }
    cout << n-ma;
    
    return 0;
}