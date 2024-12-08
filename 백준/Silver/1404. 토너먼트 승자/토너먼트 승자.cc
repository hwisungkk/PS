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
int main()
{
    ios_base ::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m, k;
    long long a, b, c;

    int t;
    string s;
    double ar[10][10]={0};
    for(int i=0;i<7;i++){
        for(int j=i+1;j<=7;j++){
            cin >> ar[i][j];
            ar[j][i] = 100-ar[i][j];
        }
    }
    double fin[8];
    fin[0] = (ar[0][1] * (ar[2][3]*ar[0][2] + ar[3][2]*ar[0][3]))/1000000;
    fin[1] = (ar[1][0] * (ar[2][3]*ar[1][2] + ar[3][2]*ar[1][3]))/1000000;
    fin[2] = (ar[2][3] * (ar[0][1]*ar[2][0] + ar[1][0]*ar[2][1]))/1000000;
    fin[3] = (ar[3][2] * (ar[0][1]*ar[3][0] + ar[1][0]*ar[3][1]))/1000000;

    fin[4] = (ar[4][5] * (ar[6][7]*ar[4][6] + ar[7][6]*ar[4][7]))/1000000;
    fin[5] = (ar[5][4] * (ar[6][7]*ar[5][6] + ar[7][6]*ar[5][7]))/1000000;
    fin[6] = (ar[6][7] * (ar[4][5]*ar[6][4] + ar[5][4]*ar[6][5]))/1000000;
    fin[7] = (ar[7][6] * (ar[4][5]*ar[7][4] + ar[5][4]*ar[7][5]))/1000000;

    cout.precision(10);
    for(int i=0;i<4;i++){
        double total=0;
        for(int j=4;j<8;j++){
            total += fin[i] * fin[j] * ar[i][j]/100;
        }
        cout << total << ' ';
    }
    for(int i=4;i<8;i++){
        double total=0;
        for(int j=0;j<4;j++){
            total += fin[i] * fin[j] * ar[i][j]/100;
        }
        cout << total << ' ';
    }
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