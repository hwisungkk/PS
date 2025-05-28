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
    long long n, m, t, k;
    bool flag=0; 

    string s;
    long long ans=0;

    cin >> t;

    while(t-->0){
        cin >> a >> b >> c >> d;
        ans=0;

        vector<vector<bool>> v(b, vector<bool>(a, 0));

        for(int i=0;i<b;i++){
            for(int j=0;j<a;j++){
                if(i-d>=0 && j-c >=0){
                    if(!v[i-d][j-c]){
                        v[i][j]=1;
                        ans++;
                    }
                }
                else{
                    v[i][j]=1;
                    ans++;
                }
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
