#define ll long long
#include <bits/stdc++.h>
using namespace std;
int chk[301][301][301];
long long n, m, t, k = 0;
bool flag = 0;
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
vector<pair<int,int>> ansq;
void back(int x, int y, int cnt){
    if(cnt==k){
        flag=1;
        return;
    }
    for(int i=0;i<4;i++){
        int dxx = x+dx[i];
        int dyy = y+dy[i];
        if(dxx>=1 && dxx <=n && dyy>=1 && dyy<=m && !chk[dxx][dyy][cnt+1]){
            ansq.push_back({dxx, dyy});
            back(dxx, dyy, cnt+1);
            if(flag)return;
        }
    }
    chk[x][y][cnt]=1;
    ansq.pop_back();
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long mod = 998'244'353;

    long long a, b, c, d;
    long long ans = 0;

    cin >> n >> m;

    cin >> k;

    for(int i=1;i<=k;i++){
        cin >> a >> b >> c >> d;
        for(int x=a;x<=c;x++){
            for(int y=b;y<=d;y++){
                chk[x][y][i]=1;
            }
        }
    }

    for(int i=1;i<=n;i++){
        if(flag)break;
        for(int j=1;j<=m;j++){
            if(flag)break;
            if(!chk[i][j][1]){
                ansq.push_back({i, j});
                //cout << i << ' ' << j << "push\n";
                back(i, j, 1);
            }
        }
    }

    if(flag){
        for(int i=0;i<ansq.size();i++){
            cout << ansq[i].first << ' ' << ansq[i].second<<'\n';
        }
    }
    else cout << "Impossible";

    return 0;
}