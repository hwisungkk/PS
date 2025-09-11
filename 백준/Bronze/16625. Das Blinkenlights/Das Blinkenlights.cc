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

    cin >> n >> m >> k;

    for(int i=1;i<=k;i++){
        if(i%n==0 && i%m==0)flag=1;
    }
    if(flag)cout<<"yes";
    else cout << "no";

    return 0;
}