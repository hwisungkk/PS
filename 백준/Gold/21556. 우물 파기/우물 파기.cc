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

        cin >> n;
        vector<long long> v(n);

        for(int i=0;i<n;i++){
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        
        long long l = v[0]+v[1];
        long long r = v[n-2]+v[n-1];
        long long mid = (l+r) >> 1;
        long long gi = n*(n-1)/2;
        while(l+1<r){
            mid = (l+r)>>1;
            int cur = 0; // mid가 커질수록 cur이 커짐.
            for(int i=0;i<n;i++){
                int point=n-1;
                while(point>i && mid <= v[i]+v[point]){
                    point--;
                }
                cur += (point-i);
            }
            if(cur<gi/2){
                l = mid;
            }
            else r = mid;
        }
        cout << l;

        return 0;
    }