#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <math.h>
using namespace std;
long long solve(long long a, long long b, long long c){
    if(b==1)return a%c;
    
    long long k = solve(a, b/2, c);
    if(b%2==1){
        return (k * k)%c * a%c;
    }
    else{
        return (k * k) % c;
    }
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long a, b, c;
    int n, m, t;
    char c1, c2, c3;

    cin >> a >> b >> c;
    long long ans;
    ans = solve(a,b,c);
    cout << ans%c;

    return 0;
}