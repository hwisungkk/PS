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
int dx[6]={0, 0, 1, 1, -1, -1};
int dy[6]={1,-1, 0, -1, 0, 1};
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m, t;
    int a, b, c;
    cin >> t;

    while(t-->0){
        bool b_w =0, w_w=0;
        cin >> n;
        vector<vector<char>> hex(n+2, vector<char>(n+2,0));
        vector<vector<bool>> check(n+2, vector<bool>(n+2,0));

        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cin >> hex[i][j];
            }
        }
        function <void(int, int, char)> dfs = [&](int x, int y, char c){
            check[x][y]=1;
            if(c=='B' && x==n){
                b_w=1;
                return;
            }
            if(c=='W' && y==n){
                w_w=1;
                return;
            }
            for(int i=0;i<6;i++){
                if(hex[x+dx[i]][y+dy[i]]==c && check[x+dx[i]][y+dy[i]]==0){
                    dfs(x+dx[i], y+dy[i], c);
                }
            }
        };

        for(int i=1;i<=n;i++){
            if(hex[1][i] == 'B'){
                for(int j=1;j<=n;j++){
                    for(int d=1;d<=n;d++){
                        check[j][d]=0;
                    }
                }
                dfs(1, i, 'B');
            }
        }
        for(int i=1;i<=n;i++){
            if(hex[i][1] == 'W'){
                for(int j=1;j<=n;j++){
                    for(int d=1;d<=n;d++){
                        check[j][d]=0;
                    }
                }
                dfs(i, 1, 'W');
            }
        }
        if(b_w==1)cout<<"Black wins\n";
        else if(w_w==1)cout<<"White wins\n";
        else cout << "Not finished\n";
    }

    return 0;
}