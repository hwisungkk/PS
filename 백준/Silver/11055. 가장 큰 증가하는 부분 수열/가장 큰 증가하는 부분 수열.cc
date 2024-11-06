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
    int dp[1000]={0};
    int kc[1000]={0};
    cin >> n;

    for(int i=0;i<n;i++){
        cin >> kc[i];
    }
    dp[0]=kc[0];
    for(int i=1;i<n;i++){
        ma=0;
        for(int j=0;j<i;j++){
            if(kc[j]<kc[i]){
                if(dp[j]>ma)ma=dp[j];
            }
        }
        dp[i]=ma+kc[i];
    }
    //1 100 2 50 60 3 5 6 7 8
    
    for(int i=0;i<n;i++){
        if(k < dp[i])k=dp[i];
    }
    cout <<k;
    
    return 0;
}