#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, k, t;
    int ans = 0;
    cin >> n >> m >> k;
    
    for(int i=n;i>0;i--){
        if(m>=pow(2, i-1)){
            m -= pow(2, i-1);
            ans += pow(2,i-1)*pow(2,i);
        }
        if(k>=pow(2, i-1)){
            k -= pow(2, i-1);
            ans += pow(2,i-1)*pow(2,i-1);
        }
    }
    cout << ans;
    return 0;
}