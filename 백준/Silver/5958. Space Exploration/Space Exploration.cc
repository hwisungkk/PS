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
long long maxi=0;
int n;
char ar[1002][1002];
int check[1002][1002]={0};
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
int ans=0;
void dfs(int x, int y, int p){
    if(ar[x][y]=='*' && check[x][y]==0){
        check[x][y]=1;
        if(p==0) ans++;
        for(int i=0;i<4;i++){
            dfs(x+dx[i], y+dy[i], 1);
        }
    }
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a, b, c, m, k;
    int t;

    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> ar[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dfs(i,j, 0);
        }
    }
    cout << ans;
    // vector <vector<int>>(n, vector<int>(3));
    // for(int i=0;i<n;i++){

    // }
    // cin >> a >> b >> c;
    return 0;
}
