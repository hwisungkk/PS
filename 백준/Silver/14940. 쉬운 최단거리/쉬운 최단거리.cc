#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int main(){
    int n, m, k, a, b=0, c = 0;
    int count=0;
    int ar[1005][1005] = {0};
    int ch[1005][1005] = {0};
    pair <int, int> p;
    queue <pair<int, int>> q;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> ar[i][j];
            if(ar[i][j]==2){
                q.push({i,j});
                ch[i][j] = 1;
                ar[i][j] = 0;
            }
        }
    }
    while(!q.empty()){
        p = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            if(ar[p.first+dx[i]][p.second+dy[i]]==1 && ch[p.first+dx[i]][p.second+dy[i]] == 0){
                q.push({p.first+dx[i], p.second+dy[i]});
                ar[p.first+dx[i]][p.second+dy[i]] = ar[p.first][p.second] + 1;
            }
            ch[p.first+dx[i]][p.second+dy[i]] = 1;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(ar[i][j]==0){
                cout << ar[i][j] << ' ';
            }
            else if(ch[i][j]==0)
                cout<< "-1 ";
            else
                cout << ar[i][j] << ' ';
        }
        cout << '\n';
    }
}