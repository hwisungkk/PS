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
        long long n, m, t;
        bool flag=1; 

        cin >> t;
        while(t-->0){
            cin >> n;
            vector<long long> v(n);
            for(int i=0;i<n;i++){
                cin >> v[i];
            }
            sort(v.begin(), v.end());
            long long ans = 0;
            for(int i=0;i<n;i++){
                ans = max(ans, min(v[i]-v[0], v[n-1]-v[i]));
            }
            cout << ans << '\n';
        }

        return 0;
    }