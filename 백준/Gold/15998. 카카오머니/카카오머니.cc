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
using namespace std;
long long gcd(long long x, long long y){
    if(x<y)swap(x,y);
    if(y==0)return x;
    if(x%y==0){
        return y;
    }
    else {
        x = x%y;
        return gcd(y,x);
    }
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;
    long long n, m;
    long long current=0;
    long long minist=-1;
    long long re_gcd=0;
    int err = 0;
    while(t-->0){
        cin >> n >> m;
        if(n<0){
            if(current + n < 0){
                re_gcd = gcd(m-n -current, re_gcd); // current-n과 기존거.
                minist = max(minist, m);
            }
            else{
                if(current + n != m)err=1;
            }
        }
        else{
            if(current + n != m)err=1;
        }
        current = m;
    }
    if(err==1)cout<<"-1\n";
    else if (re_gcd==0)cout << "1\n";
    else if(re_gcd > minist)cout << re_gcd<<'\n';
    else cout << "-1\n";
    

    return 0;
}