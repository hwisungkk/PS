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
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m, t;
    int a, b, c;
    cin >> n >> m;

    vector<vector<char>> tet(n+2, vector<char>(m+2, 0));
    vector<vector<bool>> check(n+2, vector<bool>(m+2, 0));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> tet[i][j];
        }
    }
    string s = "";
    int cnt = 0;
    //dx dy 오른쪽, 왼쪽, 위, 아래
    int ans[5]={0}; //0은 네모, 1은 일자, 2는 오른쪽 위 번개, 3은 왼쪽 위 번개, 4가 엿
    function <void(int, int, char)> dfs = [&](int x, int y, char c){
        check[x][y]=1;
        if(cnt==3){
            if(s=="r   d l")ans[0]++;
            else if(s=="rrr" || s== "   d   d   d")ans[1]++;
            else if(s=="r      d l" || s=="   dr   d")ans[2]++;
            else if(s=="r   dr" || s=="   d l   d")ans[3]++;
            else ans[4]++;
            cnt = 0;
            return;
        }
        for(int i=0;i<4;i++){
            if(tet[x+dx[i]][y+dy[i]] == c && check[x+dx[i]][y+dy[i]]==0){
                if(i==0)s+='r';
                else if(i==1)s+='l';
                else if(i==2)s+='u';
                else if(i==3)s+='d';
                cnt++;
                dfs(x+dx[i], y+dy[i], c);
            }
            else s+=' ';
        }
    };

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(tet[i][j]>='a' && tet[i][j]<='z' && check[i][j]==0){
                s = "";
                dfs(i, j, tet[i][j]);
            }
        }
    }

    for(int i=0;i<5;i++){
        cout << ans[i] << '\n';
    }

    return 0;
}