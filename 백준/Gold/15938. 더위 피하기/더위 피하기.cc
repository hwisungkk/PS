#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <functional>
#include <algorithm>
#include <math.h>
#include <map>
using namespace std;
#define mod 1000000007
int main()
{
    ios_base ::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    
    int a, b, c, d;
    int n, m, k, t;
    int o_1, o_2;

    cin >> a >> b; //현재 좌표
    cin >> t; //시간
    cin >> c >> d; // 집 좌표
    cin >> n; // 장애물 개수

    //깔끔하게 좌표 조정
    c+=(201-a), d+=(201-b);
    vector<vector<long long>> dp(403, vector<long long>(403, 0));
    for(int i=0;i<n;i++){
        cin >> o_1 >> o_2;
        o_1 += (201-a), o_2 += (201-b);
        if(0<=o_1 && o_1<=402 && 0<= o_2 && o_2 <=402){ //의미 있는 장애물만 남기기
            dp[o_1][o_2] = -1; //바로 넣어
        }
    }
    a = 201, b = 201;
    if(abs(a-c)+abs(b-d)>t){ //t보다 크면 차피 못감
        cout << 0;
        return 0;
    }
    dp[201][201]=1;
    int dxx[4] = {0, 0, -1, 1};
    int dyy[4] = {-1, 1, 0, 0};
    while(t-->0){
        vector<vector<long long>> ex(403, vector<long long>(403, 0));
        for(int i=1;i<=401;i++){
            for(int j=1;j<=401;j++){
                if(dp[i][j]==-1)continue; //벽이면 x
                else{
                    for(int kk=0;kk<4;kk++){
                        if(dp[i+dxx[kk]][j+dyy[kk]]!=-1 && !(i+dxx[kk]==c&&j+dyy[kk]==d)){
                            ex[i][j] += (dp[i+dxx[kk]][j+dyy[kk]]);
                        }
                    }
                }
                ex[i][j] = ex[i][j]%mod;
            }
        }
        for(int i=1;i<=401;i++){
            for(int j=1;j<=401;j++){
                if(i==c && j==d)
                    dp[i][j] += ex[i][j];
                else if(dp[i][j]!=-1)
                    dp[i][j]=ex[i][j];
                dp[i][j] = dp[i][j]%mod;
            }
        }
    }
    cout << dp[c][d] % mod;
    

    return 0;
}