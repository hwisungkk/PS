#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    int a, b;
    vector <pair<int,int>> v;
    int dp[200001] = {0};
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> a >> b;
        v.push_back({a,b});
    }
    dp[0] = 1;
    for(int j=0;j<n;j++){
        for(int i=100000;i>=0;i--){
            if(dp[i]!=0){
                if(dp[i+v[j].first] < dp[i]+v[j].second)
                    dp[i+v[j].first] = dp[i]+v[j].second;
            }
        }
    }
    for(int i=1;i<=m;i++){
        if(dp[i-1]>dp[i]){
            dp[i] = dp[i-1];
        }
    }
    cout << dp[m]-1 <<'\n';
}