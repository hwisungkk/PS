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
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    long long n, m;
    int a, b, c;

    int t;
    int i=0;
    cin >> t;
    vector<long long> v(t);
    for(int i=0;i<t;i++){
        cin >> v[i];
    }
    long long ans=0;
    bool flag = false;
    while(!flag){
        flag = true;
        for(int i=1;i<t-1;i++){
            if(v[i-1]+v[i+1]<v[i]*2){
                ans += v[i] - (v[i-1]+v[i+1])/2;
                v[i] = (v[i-1]+v[i+1])/2;
                flag = false;
            }
        }
    }
    cout << ans;

    return 0;
}