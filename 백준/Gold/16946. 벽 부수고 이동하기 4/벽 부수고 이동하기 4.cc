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
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long a, b, c;
    int t;

    string s;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n+2, vector<int>(m+2, -1));
    vector<vector<int>> can_go(n+2, vector<int>(m+2, 0));
    vector<vector<int>> try_c(n+2, vector<int>(m+2, 0));
    int t_c=0;
    for(int i=1;i<=n;i++){
        cin >> s;
        for(int j=0;j<m;j++){
            arr[i][j+1] = s[j]-48;
        }
    }
    function <void(int, int)> bfs=[&](int x, int y){
        queue <pair<int, int>> paint;
        queue <pair<int, int>> save;
        if(arr[x][y]==0 && can_go[x][y]==0){
            t_c++;
            save.push({x,y});
            paint.push({x,y});
            pair<int, int> p;
            can_go[x][y]=1;
            try_c[x][y]=t_c;
            int count = 1;
            while(!paint.empty()){
                p = paint.front();
                paint.pop();
                for(int i=0;i<4;i++){
                    if(arr[p.first+dx[i]][p.second+dy[i]]==0 && can_go[p.first+dx[i]][p.second+dy[i]]==0){
                        count++;
                        save.push({p.first+dx[i], p.second+dy[i]});
                        paint.push({p.first+dx[i], p.second+dy[i]});
                        can_go[p.first+dx[i]][p.second+dy[i]]=1;
                        try_c[p.first+dx[i]][p.second+dy[i]]=t_c;
                    }
                }
            }
            while(!save.empty()){ //채워주기
                p = save.front();
                save.pop();
                can_go[p.first][p.second]=count;
            }
        }
        else return;
    };
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            bfs(i, j);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(arr[i][j]==1){
                vector<int> cc;
                for(int k=0;k<4;k++){
                    int fin_ch=0;
                    for(int zx=0;zx<cc.size();zx++){
                        if(cc[zx]==try_c[i+dx[k]][j+dy[k]])fin_ch=1;
                    }
                    if(!fin_ch){
                        arr[i][j] += can_go[i+dx[k]][j+dy[k]];
                        cc.push_back(try_c[i+dx[k]][j+dy[k]]);
                    }
                }
            }
            cout << arr[i][j]%10;
        }cout << '\n';
    }
    
    return 0;
}