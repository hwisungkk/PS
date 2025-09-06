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
    cin >> n >> m;
    cin >> s;

    ll cha=n-m;

    int left=0;
    int right=s.size()-1;

    while(1){
        while(left <s.size() && s[left]!='W')left++;
        while(right>=0 && s[right]!='B')right--;

        if(left<right){
            (right-left)*cha<=n ? ans+=(right-left)*cha:ans+=n;
            left++;
            right--;
        }
        else break;
    }

    cout << ans;
    

    return 0;
}