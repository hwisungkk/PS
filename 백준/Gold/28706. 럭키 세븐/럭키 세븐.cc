#define ll long long
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <functional>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <map>
using namespace std;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long mod = 1e9+7;
        
    bool flag=0; 
    long long a, b, c, d;
    long long n, m, t, k;
    long long ans = 0;

    string s;
    cin >> t;
    while(t-->0){
        cin >> n;
        char c1,c2;
        int x,y;
        vector<vector<bool>> chk(n+1, vector<bool>(7,0));
        chk[0][1]=1;
        for(int i=1;i<=n;i++){
            cin >> c1 >> x >> c2 >> y;

            for(int j=0;j<7;j++){
                if(c1=='+'){
                    if(chk[i-1][j])chk[i][(j+x)%7]=1;
                }
                else{
                    if(chk[i-1][j])chk[i][(j*x)%7]=1;
                }
            }
            for(int j=0;j<7;j++){
                if(c2=='+'){
                    if(chk[i-1][j])chk[i][(j+y)%7]=1;
                }
                else{
                    if(chk[i-1][j])chk[i][(j*y)%7]=1;
                }
            }
        }
        if(chk[n][0])cout<<"LUCKY"<<'\n';
        else cout<<"UNLUCKY"<<'\n';
    }

    return 0;
}