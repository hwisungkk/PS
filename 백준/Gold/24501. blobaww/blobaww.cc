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

    cin >> n >> m;

    vector<string> v(n);

    for(int i=0;i<n;i++){
        cin >> v[i];
    }

    vector<vector<long long>> vE(n+1, vector<long long>(m+1,0));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(v[i-1][j-1]=='E'){
                vE[i][j] = vE[i-1][j]+vE[i][j-1]+1-vE[i-1][j-1]+mod;
            }
            else{
                vE[i][j] = vE[i-1][j]+vE[i][j-1]-vE[i-1][j-1]+mod;
            }
            vE[i][j]%=mod;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(v[i-1][j-1]=='S'){
                vE[i][j] = vE[i-1][j]+vE[i][j-1]+vE[i][j]-vE[i-1][j-1]+mod;
            }
            else{
                vE[i][j] = vE[i-1][j]+vE[i][j-1]-vE[i-1][j-1]+mod;
            }
            vE[i][j]%=mod;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(v[i-1][j-1]=='M'){
                vE[i][j] = vE[i-1][j]+vE[i][j-1]+vE[i][j]-vE[i-1][j-1]+mod;
            }
            else{
                vE[i][j] = vE[i-1][j]+vE[i][j-1]-vE[i-1][j-1]+mod;
            }
            vE[i][j]%=mod;
        }
    }

    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<=m;j++){
    //         cout << vE[i][j] << ' ';
    //     }cout << '\n';
    // }

    ans = vE[n][m]%mod;

    cout << ans;

    

    return 0;
}

