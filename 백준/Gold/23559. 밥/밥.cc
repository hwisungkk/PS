#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <queue>
#include <set>
#include <algorithm>
#include <math.h>
using namespace std;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long a, b, c;
    int n, m, t;
    vector<pair<long long, long long>> v;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> a >> b;
        v.push_back({a-b,a}); //차이랑, 5000원 값 저장
    }
    int i;
    for(i=0;i<=n;i++){
        if(5000*i + 1000*(n-i) > m){
            break;
        }
    }
    int mx = i-1; //5000원 먹을 수 있는 최대 개수

    sort(v.begin(), v.end(), greater<>()); //내림차 정렬

    long long ans=0;
    for(i=0;i<n;i++){ 
        if(v[i].first > 0 && (i < mx)){
            ans += v[i].second;
        }
        else{
            ans += (v[i].second - v[i].first);
        }
    }
    cout << ans;

    return 0;
}