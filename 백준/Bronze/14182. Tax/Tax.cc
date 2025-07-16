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
    long long a, b, c, d;
    long long n, m, t, k;
    long long ans = 0;

    while(1){
        cin >> n;
        if(n==0)break;

        if(n>=5000000)cout<<n*8/10<<'\n';
        else if(n>=1000000)cout<<n*9/10<<'\n';
        else cout << n << '\n';
    }

    return 0;
}