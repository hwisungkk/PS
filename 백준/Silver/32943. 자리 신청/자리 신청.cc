#define ll long long
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

    long long mod = 1'000'000;

    bool flag = 0;
    long long a, b, c, d;
    long long n, m, t, k = 0;
    long long ans = 0;

    cin >> n >> m >> k; //학생, 좌석, 로그

    vector<pair<ll, pair<ll,ll>>> vp(k);

    for(int i=0;i<k;i++){
        cin >> vp[i].first >> vp[i].second.first >> vp[i].second.second;
    }
    vector<int> stu(n+1, 0);
    vector<bool> sit(m+1,0);
    sort(vp.begin(), vp.end());

    for(int i=0;i<k;i++){
        if(!sit[vp[i].second.first]){
            sit[vp[i].second.first]=1;;
            if(stu[vp[i].second.second]){
                sit[stu[vp[i].second.second]]=0;
            }
            stu[vp[i].second.second]=vp[i].second.first;
        }
    }

    for(int i=1;i<=n;i++){
        if(stu[i]) cout << i << ' ' << stu[i] << '\n';
    }
    

    return 0;
}