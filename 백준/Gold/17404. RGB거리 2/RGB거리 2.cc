#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>
#include<stack>
#include<cstring>
#include<string>
#include<queue>
using namespace std;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m=0;
    int k=1, a, count=0;
    int check = 0;
    int ar[1000][3];
    int dp[1000][3];
    long last[3];
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cin >> ar[i][j];
        }
    }
    for(int i=0;i<3;i++){ //R일때, G일때, B일떄
        for(int j=0;j<3;j++){
            if(i==j){
                dp[0][j] = ar[0][j];
            }
            else{
                dp[0][j] = 100000000;
            }
        }
        for(int k=1;k<n;k++){
            dp[k][0] = min(dp[k-1][1], dp[k-1][2]) + ar[k][0];
            dp[k][1] = min(dp[k-1][0], dp[k-1][2]) + ar[k][1];
            dp[k][2] = min(dp[k-1][0], dp[k-1][1]) + ar[k][2];     
        }
        if(i==0){
            last[i] = min(dp[n-1][1], dp[n-1][2]);
        }
        else if(i==1){
            last[i] = min(dp[n-1][0], dp[n-1][2]);
        }
        else if(i==2){
            last[i] = min(dp[n-1][1], dp[n-1][0]);
        }
    }
    cout << min(last[2], min(last[0], last[1]));
    
    return 0;
}