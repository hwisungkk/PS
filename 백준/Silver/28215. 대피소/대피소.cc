#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;
int al = 0;
int dis[51][51]={0};
int main()
{
    ios_base ::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    long long a, b, c, total = 0;
    long long n, k = -1;
    int m;
    int t;
    string s1, s2;
    cin >> n >> m;
    vector <pair<int, int>> v;
    for(int i=0;i<n;i++){
        cin >> a >> b;
        v.push_back({a,b});
    }
    for(int i=0;i<n;i++){
        int max = -1;
        for(int j=0;j<n;j++){
            dis[i][j] = abs(v[i].first - v[j].first) + abs(v[i].second - v[j].second);
        }
        dis[i][n] = max;
    }
    if(m==1){
        int mi = 10000000;
        for(int i=0;i<n;i++){
            int ma = -1;
            for(int j=0;j<n;j++){
                if(ma<dis[i][j])ma=dis[i][j];
            }
            if(mi > ma)mi = ma;
        }
        cout << mi;
    }
    else if(m==2){
        int mi = 10000000;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int ma = -1;
                for(int k=0;k<n;k++){
                    if(ma< min(dis[i][k], dis[j][k])) ma = min(dis[i][k], dis[j][k]);
                }
                if(mi > ma)mi = ma;
            }
        }
        cout << mi;
    }
    else if(m==3){
        int mi = 10000000;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    int ma = -1;
                    for(int p=0;p<n;p++){
                        if(ma< min({dis[i][p], dis[j][p], dis[k][p]})) ma = min({dis[i][p], dis[j][p], dis[k][p]});
                    }
                    if(mi > ma)mi = ma;
                }
            }
        }
        cout << mi;
    }
    
    return 0;
}