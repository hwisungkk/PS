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
    
    long long n, m, t;
    int a, b, c;

    cin >> n >> m;
    vector<pair<long long, long long>> v(n);
    for(int i=0;i<n;i++){
        long long l1, l2;
        cin >> l1 >> l2;
        v[i].first=l1; //가치
        v[i].second=l2; //면적
    }
    sort(v.begin(),v.end());
    long long ans=0;
    for(int i=n-1;i>=0;i--){
        if(v[i].second<=m){
            m-=v[i].second;
            ans+=v[i].first*v[i].second;
        }
        else{
            ans+=m*v[i].first;
            m=0;
        }
    }
    cout << ans;

    return 0;
}