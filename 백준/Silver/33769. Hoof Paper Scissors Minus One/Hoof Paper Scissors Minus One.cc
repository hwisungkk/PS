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
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int a, b, c, d;
    int n, m, t;
    char ch;
    string s;
    bool flag=0;
    cin >> n >> m;
    vector<vector<int>> win(n+1, vector<int>(n+1, 0));
    for(int i=1;i<=n;i++){
        cin >> s;
        for(int j=0;j<s.size()-1;j++){
            if(s[j]=='L'){
                win[i][j+1]=1;
            }
            else if(s[j]=='W'){
                win[j+1][i]=1;
            }
        }
    }
    for(int i=0;i<m;i++){
        cin >> a >> b;
        int cnt=0;
        long long ans=0;
        for(int j=1;j<=n;j++){
            if(win[a][j]==1 && win[b][j]==1){
                cnt++;
            }
        }
        ans += (2*n-1)*cnt;

        ans -= cnt*(cnt-1);

        cout << ans << '\n';
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout << win[i][j] << ' ';
    //     }cout << '\n';
    // }



    return 0;
}