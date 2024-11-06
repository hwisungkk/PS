#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>
using namespace std;
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    int n, m, r_count=0, count=0;
    int k=0;
    int p;
    int dp[100000] = {0};
    //vector <vector <int>> memo;
    
    vector <int> v;
    cin >> n;
    cin >> m;
    
    for(int i=0;i<n;i++){
        cin >> p;
        v.push_back(p);
    }
    dp[0]=1;
    sort(v.begin(), v.end());
    //1 2 5
    for(int i=0;i<v.size();i++){
        for(int j=1;j<=m;j++){
            if(j-v[i]>=0)
                dp[j] += dp[j-v[i]];
        }
    }
    cout << dp[m];
    //dp[1] = 1 dp[2] = 2 dp[3] = 2 dp[4] = 3 dp[5] = 4 dp[6]=5 dp[7]= 6
    return 0;
}
//메모이제이션
    /*
    cout << memo[0][0] << endl;
    cout << memo[1][0] << endl <<memo[1][1] << endl;
    cout << memo[2][0] << endl <<memo[2][1] << endl << memo[2][2] << endl 
    << memo[2][3] << endl << memo[2][4] << endl << memo[2][5] << endl << memo[2][6];*/
    /*
    1 2 5 10
    10
    10 5
    10 8 6 4 2 5 3 1
    
    */