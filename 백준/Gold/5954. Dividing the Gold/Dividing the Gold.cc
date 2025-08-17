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
    long long ans = 1e16;

    cin >> n;
    vector<int> v(n);
    int tt=0;
    for(int i=0;i<n;i++){
        cin >> v[i];
        tt+=v[i];
    }
    vector<int> chk(tt/2+1, 0);
    if(v[0]<=tt/2)chk[v[0]]=1;

    for(int i=1;i<n;i++){
        for(int j=tt/2;j>=0;j--){
            if(chk[j]){
                if(j+v[i]<=tt/2){
                    chk[j+v[i]]+=chk[j];
                    if(chk[j+v[i]]>mod)chk[j+v[i]]-=mod;   
                }
            }
        }
        if(v[i]<=tt/2){
            chk[v[i]]++;
        }
    }
    for(int i=tt/2;i>=0;i--){
        if(chk[i]){
            cout << tt-2*i<<'\n';
            cout << chk[i]%mod;
            break;
        }
    }cout<<'\n';
    if(n==1)cout<<v[0]<<'\n'<<"1";

    return 0;
}