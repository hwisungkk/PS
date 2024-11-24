#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;
int al = 0;
int m;
int gcd(int x, int y){
    if(y == 0){
        return x;
    } 
    else {
        return gcd(y, x%y);
    }
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long a, b, c, total = 0;
    long long count = 0;
    int ma = 0;
    int ans = 100000000;
    long long n, k = -1;
    string s1, s2;
    
    cin >> n;
    
    while(n--){
        cin >> a >> b >> c >> k;
        int lk = a*b/gcd(a,b);
        int ans = c;
        int namu = ans%b;
        if(namu==0)namu=b;
        while(namu!=k){
            if(ans>lk){
                ans=-1;
                break;
            }
            ans+=a;
            namu = ans%b;
            if(namu==0)namu=b;
            
        }
        cout<<ans<<'\n';    
    }
}