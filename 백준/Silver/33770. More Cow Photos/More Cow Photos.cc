
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
        long long ans=0;
        vector<int> v(n+1, 0);
        for(int i=0;i<n;i++){
            cin >> a;
            v[a]++;
        }
        bool flag=0;
        for(int i=n;i>=1;i--){
            if(flag==0 && v[i]>=1){
                ans+=1;
                flag=1;
            }
            else if(flag){
                if(v[i]>=2)ans+=2;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}