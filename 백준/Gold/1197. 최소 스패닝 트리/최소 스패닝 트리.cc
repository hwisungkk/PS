#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <queue>
#include <set>
#include <algorithm>
#include <math.h>
using namespace std;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int parent[10001];

int find(int x){
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void uni(int a, int b){
    a = find(a);
    b = find(b);
    parent[b] = a;
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int a, b, c, d;
    int n, m, t;
    cin >> n >> m;

    vector<pair<int, pair<int, int>>> v(m);
    for(int i=0;i<m;i++){
        cin >> a >> b >> c;
        v[i] = {c, {a, b}};
    }
    sort(v.begin(), v.end());

    for(int i=0;i<=10000;i++){
        parent[i]=i;
    }

    long long ans = 0;
    for(int i=0;i<m;i++){
        if(find(v[i].second.first)!=find(v[i].second.second)){
            uni(v[i].second.first, v[i].second.second);
            ans += v[i].first;
        }
    }
    cout << ans;

    return 0;
}