#define ll long long
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

    long long mod = 1'000'000;

    bool flag = 0;
    long long a, b, c, d;
    long long n, m, t, k = 0;
    long long ans = 0;

    while(1){
        ans=0;
        cin >> n >> m;
        if(!n&&!m)break;
        vector<ll> v(n);
        vector<vector<ll>> chk(m+1, vector<ll>(n, 0));
        for(int i=0;i<n;i++)cin>>v[i];
        for(int i=0;i<n;i++){
            chk[1][i]=1;
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(v[i]>=v[j]){
                    for(int k=1;k<=m;k++){
                        chk[k][i]+=chk[k-1][j];
                    }
                }
            }
        }
        // for(int i=0;i<=m;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<chk[i][j]<<' ';
        //     }cout<<'\n';
        // }

        for(int i=0;i<n;i++){
            ans+=chk[m][i];
        }
        cout << ans<<'\n';
    }

    

    return 0;
}