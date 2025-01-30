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
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long a, b, c;
    long long n, m, k;
    cin >> n >> m >> k;
    vector<long long> v(51);
    v[0] = n%k;
    for(int i=1;i<=50;i++){
        v[i] = (v[i-1]*v[i-1])%k;
    }
    long long ans=1;
    for(int i=50;i>=0;i--){
        if(pow(2, i) > m) continue;
        else{
            ans *= v[i];
            m -= pow(2,i);
            ans = ans%k;
        }
        //cout << m << ' ' << ans << '\n';
    }
    cout << ans%k;
    return 0;
}