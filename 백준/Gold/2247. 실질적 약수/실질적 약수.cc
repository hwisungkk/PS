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
        string s;
        
        cin >> n;
        m = 200000000;
        long long ans=0;
        for(int i=2;i<=n/2;i++){
            ans += (n/i-1)*i;
            ans%=1000000;
        }
        cout << ans;
        return 0;
    }