#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <functional>
#include <algorithm>
#include <math.h>
using namespace std;
int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long a, b, c;
    int t;
    int n, m, x, y;
    int mi = 1e9;
    cin >> n >> m >> x >> y;
    vector<vector<int>> chess(n+5, vector<int>(m+5, 0));
    queue<pair<int, int>> q;
    function<void(int, int)> bfs = [&](int xn, int yn){
        while(!q.empty()){
            pair<int,int> p;
            p = q.front();
            q.pop();
            for(int i=0;i<8;i++){
                if(p.first+dx[i]>=0 && p.second+dy[i] >=0 && 
                p.first+dx[i]<n && p.second+dy[i]<m && chess[p.first+dx[i]][p.second+dy[i]]==0){
                    chess[p.first+dx[i]][p.second+dy[i]] = chess[p.first][p.second]+1;
                    q.push({p.first+dx[i], p.second+dy[i]});
                }
            }
            if(chess[x-1][y-1]!=0){
                cout << chess[x-1][y-1];
                break;
            }
        }
    };
    q.push({0,0});
    int check=0;
    if(x==1 && y==1){
        cout << 0;
        check=1;
    }
    else bfs(0,0);
    if(chess[x-1][y-1]==0 && check == 0){
        cout << "NEVAR";
    }
    

    return 0;
}