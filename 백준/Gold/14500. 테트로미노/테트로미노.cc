#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <string>
#include <algorithm>
int ar[502][502]={0};
int n, m;
using namespace std;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long a, b, c, total = 0;
    long long count = 0;
    int ma = -1;
    int ans = 100000000;
    string s1, s2;
    cin >> n >> m;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> ar[i][j];
        }
    }
    int tet=0;
    ma=-1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m-3;j++){
            tet=0;
            tet = ar[i][j]+ar[i][j+1]+ar[i][j+2]+ar[i][j+3];
            if(tet>ma){
                ma=tet;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m-2;j++){
            tet=0;
            tet = ar[i][j]+ar[i][j+1]+ar[i][j+2];
            tet += max({ar[i-1][j], ar[i-1][j+1], ar[i-1][j+2], ar[i+1][j], ar[i+1][j+1], ar[i+1][j+2]});
            if(tet>ma){
                ma=tet;
            }
        }
    }
    for(int i=1;i<=n-3;i++){
        for(int j=1;j<=m;j++){
            tet=0;
            tet = ar[i][j]+ar[i+1][j]+ar[i+2][j]+ar[i+3][j];
            if(tet>ma){
                ma=tet;
            }
        }
    }
    for(int i=1;i<=n-2;i++){
        for(int j=1;j<=m;j++){
            tet=0;
            tet = ar[i][j]+ar[i+1][j]+ar[i+2][j];
            tet += max({ar[i][j-1], ar[i+1][j-1], ar[i+2][j-1], ar[i][j+1], ar[i+1][j+1], ar[i+2][j+1]});
            if(tet>ma){
                ma=tet;
            }
        }
    }
    for(int i=1;i<=n-1;i++){
        for(int j=1;j<=m-1;j++){
            tet=0;
            tet = ar[i][j]+ar[i+1][j]+ar[i+1][j+1]+ar[i][j+1];
            if(tet>ma){
                ma=tet;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m-1;j++){
            tet=0;
            tet = ar[i][j]+ar[i][j+1];
            tet += max((ar[i-1][j]+ar[i+1][j+1]), (ar[i-1][j+1]+ar[i+1][j]));
            if(tet>ma){
                ma=tet;
            }
        }
    }
    for(int i=1;i<=n-1;i++){
        for(int j=1;j<=m;j++){
            tet=0;
            tet = ar[i][j]+ar[i+1][j];
            tet += max((ar[i][j-1]+ar[i+1][j+1]), (ar[i][j+1]+ar[i+1][j-1]));
            if(tet>ma){
                ma=tet;
            }
        }
    }
    cout << ma;
    return 0;
}