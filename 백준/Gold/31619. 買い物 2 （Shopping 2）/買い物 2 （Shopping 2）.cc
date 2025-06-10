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

    cin >> n >> m >> t;
    vector<long long> nu_base(n+1, 0); // 얘를 기본 누적으로 하자.
    vector<vector<pair<long long, long long>>> v(m+1, 
    vector<pair<long long, long long>>(1, {0,0})); //앞에가 index, 뒤에가 할인 값으로

    for(int i=0;i<n;i++){ // 얘가 상품임
        cin >> a >> b;
        nu_base[i+1] = nu_base[i] + a;
        v[b].push_back({i+1, v[b][v[b].size()-1].second+a/2});
    }

    for(int i=0;i<t;i++){ // 얘가 사는 사람임
        cin >> a >> b >> c;

        if(v[a].size()==0){
            cout << nu_base[c]-nu_base[b-1] << '\n';
            continue;
        }

        int l=0, r=v[a].size();
        int left, right;
        while(l+1<r){
            int mid = (l+r)>>1;

            if(b>v[a][mid].first){
                l = mid;
            }
            else r = mid;
        }
        left = l;

        l=0, r=v[a].size();
        while(l+1<r){
            int mid = (l+r)>>1;

            if(c>=v[a][mid].first){
                l = mid;
            }
            else r = mid;
        }
        right = l;

        long long dis = v[a][right].second-v[a][left].second;

        //cout << v[a][right].second << ' ' << v[a][left].second << ' ';

        cout << nu_base[c]-nu_base[b-1] - dis << '\n';
    }

    return 0;
}

