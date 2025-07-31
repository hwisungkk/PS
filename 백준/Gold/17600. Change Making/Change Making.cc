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
    long long a, b, c, d;
    long long n, m, t, k;
    long long ans = 0;

    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    vector<int> as1(100001, 0); //틀린 
    vector<int> as2(100001, 1e7); //맞은
    for(int i=1;i<=100000;i++){
        m=i;
        int cnt=0;
        for(int j=n-1;j>=0;j--){
            cnt += (m/v[j]);
            m%=v[j];
        }
        as1[i]=cnt;
    }
    as2[0]=0;
    for(int i=0;i<n;i++){
        for(int j=1;j<=100000;j++){
            if(j-v[i]>=0){
                as2[j] = min(as2[j], as2[j-v[i]]+1);
            }
        }
    }

    for(int i=1;i<=100000;i++){
        if(as2[i]<as1[i]){
            ans=i;
            flag=1;
            break;
        }
    }
    if(flag)cout << ans;
    else cout << "-1";


    return 0;
}