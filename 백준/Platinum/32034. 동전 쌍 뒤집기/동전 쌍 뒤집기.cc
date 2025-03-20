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
    bool flag=0;
    cin >> t;
    while(t-->0){
        cin >> n;
        string s;
        cin >> s;
        long long ans=0;
        int j=1;
        for(int i=0;i<n;i++){
            if((s[i]=='T')^(i&1)){
                ans+=abs(i-j);
                j+=2;
            }
        }
        if(j>=n && j<=n+1){
            cout << ans << '\n';
        }
        else cout << "-1\n";
    }
    return 0;
}