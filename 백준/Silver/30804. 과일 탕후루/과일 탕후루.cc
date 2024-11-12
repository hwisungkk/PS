#include <iostream>
#include<vector>
#include<set>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    int n;
    cin >> t;
    int ar[200001];
    int dp[200001];
    int f_1=-1;
    int f_2=-1;
    int cnti=1;
    for(int i=0;i<t;i++){
        cin >> ar[i];
    }
    f_1 = ar[0];
    dp[0] = 1;
    for(int i=1;i<t;i++){
        if(f_1 == ar[i] || f_2 == ar[i]){
            dp[i] = dp[i-1]+1;
        }
        else{
            if(f_2==-1){
                f_2=ar[i];
                dp[i] = dp[i-1]+1;
                cnti = 1;
                continue;
            }
            else {
                dp[i] = cnti+1;
            }
        }
        if(ar[i-1]==ar[i])cnti++;
        else {
            cnti=1;
            f_1 = f_2;
            f_2 = ar[i];
        }
    }
    int ma = -1;
    for(int i=0;i<t;i++){
        if(ma<dp[i])ma=dp[i];
        //cout << dp[i] << " ";
    }
    cout << ma;

    return 0;
}