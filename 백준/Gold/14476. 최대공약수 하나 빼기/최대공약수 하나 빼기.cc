#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <math.h>
using namespace std;
int gcd(int a, int b){
    if(a<b)swap(a,b);
    int temp;
    while(b!=0){
        temp = a%b;
        a = b;
        b = temp;
    }
    return a;
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long a, b, c;
    int t;
    int n, m, k;
    int mi = 1e9;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    vector<int> pre(n);
    pre[0]=v[0];
    for(int i=1;i<n;i++){
        pre[i] = gcd(v[i], pre[i-1]);
    }
    vector<int> suf(n);
    suf[n-1] = v[n-1];
    for(int i=n-2;i>=0;i--){
        suf[i] = gcd(v[i], suf[i+1]);
    }
    // for(int i=0;i<n;i++){
    //     cout << pre[i] << ' ';
    // }cout << '\n';
    // for(int i=0;i<n;i++){
    //     cout << suf[i] << ' ';
    // }cout << '\n';
    int rm = 0;
    int ma = -1;
    if(v[0]%suf[1]!=0){
        if(ma < suf[1]){
            ma = suf[1];
            rm = v[0];
        }
    }
    if(v[n-1]%suf[n-2]!=0){
        if(ma < suf[n-2]){
            ma = suf[n-2];
            rm = v[n-1];
        }
    }
    for(int i=1;i<n-1;i++){
        if(v[i]%gcd(pre[i-1], suf[i+1])!=0){
            if(ma < gcd(pre[i-1], suf[i+1])){
                ma = gcd(pre[i-1], suf[i+1]);
                rm = v[i];
            }
        }
    }
    if(ma==-1)cout << ma;
    else cout << ma << ' ' << rm;

    return 0;
}