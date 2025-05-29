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
        
    int a, b, c, d;
    long long n, m, t, k;
    bool flag=0; 

    cin >> n;
    vector<long long> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    long long gi = 1e18;
    int ans=0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(abs(v[i]-v[j])<gi){
                gi=abs(v[i]-v[j]);
                ans=0;
            }
            if(abs(v[i]-v[j])==gi)ans++;
        }
    }
    cout << gi << ' ' << ans;

    return 0;
}
