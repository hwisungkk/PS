#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <queue>
#include <set>
#include <algorithm>
#include <math.h>
using namespace std;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int a, b, c, d;
    long long n, m, t;
    cin >> n;
    long long s_n = n;
    long long ans = n;
    set<long long> s;

    while(n>1){
        int chk = 0;
        for(long long i=2;i*i<=n;i++){
            if(n%i==0){
                s.insert(i);
                n/=i;
                chk = 1;
                break;
            }
        }
        if(!chk){
            s.insert(n);
            break;
        }
    }
    for(auto a : s){
        ans = ans/a*(a-1);
    }
    cout << ans;

    return 0;
}