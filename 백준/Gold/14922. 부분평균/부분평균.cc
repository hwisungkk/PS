#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <functional>
#include <algorithm>
#include <math.h>
#include <map>
using namespace std;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int a, b, c, d;
    int n, m, t;
    char ch;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }

    int ans=0;
    double ma=1e10;
    for(int i=0;i<n-1;i++){
        if(ma > (double)((v[i]+v[i+1])/2)){
            ma = (double)((v[i]+v[i+1])/2);
            ans = i;
        }
    }
    for(int i=0;i<n-2;i++){
        if(ma > (double)((v[i]+v[i+1]+v[i+2])/3)){
            ma = (double)((v[i]+v[i+1]+v[i+2])/3);
            ans = i;
        }
    }
    cout << ans;
    

    return 0;
}