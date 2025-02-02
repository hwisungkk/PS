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
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m, t;
    int a, b, c;
    long long ans = 0;

    cin >> n >> m >> t;
    int f, s;
    vector<vector<int>> rc(n, vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> rc[i][j];
            if(rc[i][j]==-1){
                f = i-1;
                s = i;
            }
        }
    }
    function <void(void)> bfs=[&](){
        vector<vector<int>> change(n, vector<int>(m, 0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int can_go=0;
                int mi_ch = (int)rc[i][j]/5;
                for(int k=0;k<4;k++){
                    if(i+dx[k]>=0 && i+dx[k]<n && j+dy[k]>=0 && j+dy[k]<m && rc[i+dx[k]][j+dy[k]]!=-1){
                        can_go++;
                    }
                }
                for(int k=0;k<4;k++){
                    if(i+dx[k]>=0 && i+dx[k]<n && j+dy[k]>=0 && j+dy[k]<m && rc[i+dx[k]][j+dy[k]]!=-1){
                        change[i+dx[k]][j+dy[k]] += mi_ch;
                    }
                }
                change[i][j] -= can_go*mi_ch;
            }   
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                rc[i][j] += change[i][j];
            }
        }
    };
    function <void(void)> air=[&](){
        for(int i=f;i>=1;i--){
            rc[i][0] = rc[i-1][0];
        }
        for(int i=0;i<m-1;i++){
            rc[0][i] = rc[0][i+1];
        }
        for(int i=0;i<f;i++){
            rc[i][m-1] = rc[i+1][m-1];
        }
        for(int i=m-1;i>=1;i--){
            rc[f][i] = rc[f][i-1];
        }
        rc[f][1] = rc[f][0] = 0;
        
        for(int i=s;i<=n-2;i++){ //밑에
            rc[i][0] = rc[i+1][0];
        }
        for(int i=0;i<=m-2;i++){
            rc[n-1][i] = rc[n-1][i+1];
        }
        for(int i=n-1;i>=s+1;i--){
            rc[i][m-1] = rc[i-1][m-1];
        }
        for(int i=m-1;i>1;i--){
            rc[s][i] = rc[s][i-1];
        }
        rc[s][1] = rc[s][0] = 0;
    };
    while(t-->0){
        bfs();
        air();
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ans += rc[i][j];
        }
    }
    cout << ans;
    return 0;
}