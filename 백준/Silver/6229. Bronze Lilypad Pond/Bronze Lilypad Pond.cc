#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <queue>
#include <set>
#include <algorithm>
#include <math.h>
using namespace std;
int dx[4]={-1,-1,1,1};
int dy[4]={-1,1,-1,1};
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b, c;
    int n, m, t;
    
    cin >> n >> m >> a >> b;
    vector<vector<int>> v(n, vector<int>(m));
    vector<vector<int>> check(n, vector<int>(m, 0));

    int s_x, s_y;
    int f_x, f_y;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> v[i][j];
            if(v[i][j]==3){
                s_x=i;
                s_y=j;
            }
            if(v[i][j]==4){
                f_x=i;
                f_y=j;
            }
        }
    }
    int cnt=0;
    queue <pair<int, int>> q;
    function <void()> bfs=[&](){
        pair<int, int> p;
        while(!q.empty()){
            p=q.front();
            int x = p.first;
            int y = p.second;
            q.pop();
            for(int i=0;i<4;i++){
                if(x+dx[i]*a >= 0 && x+dx[i]*a < n && y+dy[i]*b >= 0 && y+dy[i]*b < m && check[x+dx[i]*a][y+dy[i]*b]==0 && (v[x+dx[i]*a][y+dy[i]*b]==1 || v[x+dx[i]*a][y+dy[i]*b]==4)){
                    q.push({x+dx[i]*a, y+dy[i]*b});
                    check[x+dx[i]*a][y+dy[i]*b] = check[x][y]+1;
                }
            }
            for(int i=0;i<4;i++){
                if(x+dx[i]*b >= 0 && x+dx[i]*b < n && y+dy[i]*a >= 0 && y+dy[i]*a < m && check[x+dx[i]*b][y+dy[i]*a]==0 && (v[x+dx[i]*b][y+dy[i]*a]==1 || v[x+dx[i]*b][y+dy[i]*a]==4)){
                    q.push({x+dx[i]*b, y+dy[i]*a});
                    check[x+dx[i]*b][y+dy[i]*a] = check[x][y]+1;
                }
            }
            if(check[f_x][f_y]!=0)break;
        }
    };
    q.push({s_x, s_y});
    check[s_x][s_y]=1;
    bfs();

    cout << check[f_x][f_y]-1;

    return 0;
}