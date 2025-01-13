#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <stack>
#include <map>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long a, b, c;
    long long mi = 1e16;
    int n, m, k;
    int t;
    cin >> n;
    vector<long long>v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int l = 0;
    int r = n-1;
    while(l<r){
        if(abs(mi) > abs(v[l]+v[r])){
            mi = abs(v[l]+v[r]);
            a = v[l];
            b = v[r];
        }
        if(v[l]+v[r] > 0){
            r--;
        }
        else if(v[l]+v[r] < 0){
            l++;
        }
        else break;
    }
    cout << a << ' ' << b;
    return 0;
}
