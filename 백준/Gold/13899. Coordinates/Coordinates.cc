#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <stack>
#include <set>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;
int n, m;
vector <pair<long long, long long>> pp(100001, {0,0});
vector <vector <pair<int, pair<int, int>>>> check(100001);
vector <int> v(100001, 0);
void dfs(int k){
    for(int j=0;j<check[k].size();j++){
        if(v[check[k][j].first]==0){
            v[check[k][j].first]=1;
            pp[check[k][j].first].first = pp[k].first + check[k][j].second.first;
            pp[check[k][j].first].second = pp[k].second + check[k][j].second.second;
            dfs(check[k][j].first);
        }
    }
}
int main()
{
    ios_base ::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    
    long long a, b, c, d;

    string s;
    int t;
    cin >> n >> m; //기지, 반군

    for(int i=0;i<m;i++){
        cin >> a >> b >> c >> d;
        check[a].push_back({b, {c,d}});
        check[b].push_back({a, {-1*c,-1*d}});
    }
    v[1]=1;
    dfs(1);
    long long xmin = 1e16;
    long long xmax = -1e16;
    long long ymin = 1e16;
    long long ymax = -1e16;
    for(int i=1;i<=n;i++){
        if(pp[i].first < xmin)xmin = pp[i].first;
        if(pp[i].first > xmax)xmax = pp[i].first;
        if(pp[i].second < ymin)ymin = pp[i].second;
        if(pp[i].second > ymax)ymax = pp[i].second;
    }
    long long dx=0, dy=0;
    if(xmin<-1e9){
        dx = -1e9 - xmin;
    }
    else if(xmax>1e9){
        dx = 1e9 - xmax;
    }
    if(ymin<-1e9){
        dy = -1e9 - ymin;
    }
    else if(ymax>1e9){
        dy = 1e9 - ymax;
    }
    for(int i=1;i<=n;i++){
        cout << pp[i].first+dx << ' ' << pp[i].second+dy << '\n';
    }
    
    return 0;
}