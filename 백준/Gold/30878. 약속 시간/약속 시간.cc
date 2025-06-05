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
    int a, b, c, d;
    long long n, m, t, k;
    long long ans = 0;
    int cur = 0;

    cin >> n;

    long long kk = 60*60*60;

    ans += (60-n)*n*n*3;
    ans += n*n*n;

    for(int i=2;i<=5;i++){
        if(ans%i==0 && kk%i==0){
            ans/=i;
            kk/=i;
            i=1;
        }
    }
    cout << ans << '/' << kk;

    return 0;
}

