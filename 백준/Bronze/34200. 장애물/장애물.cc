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

    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
        if(i>0 && v[i-1]+1==v[i]){
            cout<<"-1";
            return 0;
        }
    }
    a=0;
    int idx=0;
    while(a<v[n-1]){
        if(a+2==v[idx]){
            a++;
            ans++;
        }
        else{
            a+=2;
            ans++;
        }
        if(a>v[idx])idx++;
    }
    cout << ans;

    return 0;
}