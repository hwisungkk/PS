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
        
    long long a, b, c, d;
    long long n, m, t;
    bool flag=1; 
    
    cin >> n >> m;
    long long mod = 1000001; 
    vector <long long> v(n+1,0);
    for(int i=0;i<n;i++){
        cin >> a >> b >> c >> d;
        v[a] = b*mod*mod + c*mod + d;
    }
    int cnt=1;
    for(int i=1;i<=n;i++){
        if(i!=m){
            if(v[i]>v[m])cnt++;
        }
    }
    cout << cnt;

    return 0;
}