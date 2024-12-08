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
int ar[51][51]={0};
int visited[51]={0};
int main()
{
    ios_base ::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m, k;
    long long a, b, c;

    int t;
    string s;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> s;
        for(int j=0;j<n;j++){
            if(s[j]=='Y'){
                ar[i][j+1]=1;
            }
        }
    }
    int ma = -1;
    for(int i=1;i<=n;i++){
        int fr =0;
        for(int j=1;j<=n;j++){
            visited[j]=0;
        }
        for(int j=1;j<=n;j++){
            if(ar[i][j]==1){
                visited[j]=1;
                for(int k=1;k<=n;k++){
                    if(ar[j][k]==1){
                        visited[k]=1;
                    }
                }
            }
        }
        for(int j=1;j<=n;j++){
            if(visited[j]==1)fr++;
        }
        fr-=visited[i];
        ma = max(fr, ma);
    }
    cout << ma;
    // int ar[1002][1002];
    // cin >> n >> m;
    // for(int i=1;i<=n;i++){
    //     for(int j=0;j<=m+1;j++){
    //         if(j==0 || j==m+1){
    //             ar[i][j] = 105;
    //         }
    //         else{
    //             cin >> ar[i][j];
    //         }
    //     }
    // }
    // int mi = 1000;
    // int dp[1002][3002];
    // for(int i=2;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         dp[i][j*3-2] = ar[i][j];
    //         dp[i][j*3-1] = ar[i][j] + dp[];
    //         dp[i][j*3] = ar[i][j] + dp[];
    //     }
    // }
    
    
    return 0;
}