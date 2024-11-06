#include <iostream>
#include <vector>
#include <string>
#include<math.h>
using namespace std;
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a, b, c;
    int ma = -1;
    int n, m, k=-1;
    int dp[1000][2]={0};
    int kc[1000]={0};
    cin >> n;

    for(int i=0;i<n;i++){
        cin >> kc[i];
    }
    dp[0][0] = 1;
    dp[0][1] = 1;
    for(int i=1;i<n;i++){
        ma=0;
        for(int j=0;j<i;j++){
            if(kc[j]<kc[i]){
               if(dp[j][0]>ma)ma=dp[j][0];
            }
            else if(kc[j]>kc[i]){
                if(dp[i][1]<max(dp[j][0], dp[j][1])+1)
                    dp[i][1]=max(dp[j][0], dp[j][1])+1;
            }
        }
        dp[i][0]=ma+1;
    }
    //1 100 2 50 60 3 5 6 7 8
    //올라가는 상태인지, 내려가는 상태인지에 대한 stat.
    
    for(int i=0;i<n;i++){
        if(k < max(dp[i][0], dp[i][1]))k=max(dp[i][0], dp[i][1]);
        //cout << dp[i][0] << " " << dp[i][1] << '\n';
    }
    cout <<k;
    
    return 0;
}